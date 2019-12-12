/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_print_functions.c                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include "ft_print_functions.h"

#define LOCAL_BUFFER_SIZE 2048

static t_pf_ret		print_buffer(const char *str, size_t len, t_pf_obj *obj)
{
	int ret;
	int fd;

	ret = PF_RET_ERROR;
	if (obj->dtype == PRINT_DEST_FIDES)
		ret = (write(obj->dest.fd, str, len) >= 0
				? PF_RET_SUCCESS : PF_RET_WRITE_ERROR);
	else if (obj->dtype == PRINT_DEST_STREAM)
	{
		fd = fileno(obj->dest.file);
		if (fd >= 0)
			ret = (write(fd, str, len) >= 0
				? PF_RET_SUCCESS : PF_RET_WRITE_ERROR);
		else
			ret = PF_RET_WRITE_ERROR;
	}
	return (ret);
}

static t_pf_ret		write_to_buffer(const char *str, size_t len, t_pf_obj *obj)
{
	static char		buffer[LOCAL_BUFFER_SIZE + 1] = {0};
	static size_t	idx = 0;
	size_t			added_bytes;
	t_pf_ret		ret;
	long long		lens;

	ret = PF_RET_SUCCESS;
	added_bytes = 0;
	while (added_bytes <= len && ret == PF_RET_SUCCESS)
	{
		if (idx < LOCAL_BUFFER_SIZE && len > 0)
		{
			lens = ft_min(LOCAL_BUFFER_SIZE - idx, len - added_bytes);
			ft_memcpy(&buffer[idx], &str[added_bytes], lens);
			added_bytes += lens;
			idx += lens;
		}
		else
		{
			ret = print_buffer(buffer, LOCAL_BUFFER_SIZE, obj);
			idx = 0;
		}
	}
	return (ret);
}

t_pf_ret			print(const char *str, ssize_t n, t_pf_obj *obj)
{
	if (str == NULL && n == 0)
		return (write_to_buffer(str, n, obj));
	if (n == LEN_NS || n < 0)
		n = ft_strlen(str);
	if (write_to_buffer(str, n, obj) >= 0)
	{
		obj->chr_wrtn += n;
		return (PF_RET_SUCCESS);
	}
	return (PF_RET_WRITE_ERROR);
}
