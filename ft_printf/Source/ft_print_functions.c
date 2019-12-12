//
//  ft_print_functions.c
//  ft_printf
//
//  Created by Floris Fredrikze on 12/12/2019.
//  Copyright © 2019 Floris Fredrikze. All rights reserved.
//

#include <unistd.h>
#include <libft.h>
#include "ft_print_functions.h"

#define LOCAL_BUFFER_SIZE 2048

static t_pf_ret print_buffer(int fd, const char *str, size_t len)
{
	return (write(fd, str, len) >= 0 ? PF_RET_SUCCESS : PF_RET_ERROR);
}

static t_pf_ret write_to_buffer(const char *str, size_t len)
{
	static char		buffer[LOCAL_BUFFER_SIZE + 1] = {0};
	static size_t	idx = 0;
	size_t			added_bytes;
	t_pf_ret		ret;
	
	ret = PF_RET_SUCCESS;
	added_bytes = 0;
	if (str == NULL)
	{
		ret = print_buffer(1, buffer, idx);
		idx = 0;
		return (ret);
	}
	while (added_bytes < len && ret == PF_RET_SUCCESS)
	{
		if (idx < LOCAL_BUFFER_SIZE)
		{
			long long lens = ft_min(LOCAL_BUFFER_SIZE - idx, len - added_bytes);
			ft_memcpy(&buffer[idx], &str[added_bytes], lens);
			added_bytes += lens;
			idx += lens;
		}
		else
		{
			ret = print_buffer(1, buffer, LOCAL_BUFFER_SIZE);
			idx = 0;
		}
	}
	return (ret);
}

t_pf_ret		print(const char *str, ssize_t n, t_pf_obj *obj)
{
	if (str == NULL && n == 0)
		return write_to_buffer(str, n);
	if (n == LEN_NS || n < 0)
		n = ft_strlen(str);
	if (write_to_buffer(str, n) >= 0)
	{
		obj->chr_wrtn += n;
		return (PF_RET_SUCCESS);
	}
	return (PF_RET_WRITE_ERROR);
}
