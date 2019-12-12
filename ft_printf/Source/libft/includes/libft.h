/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   libft.h                                           :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/01/09 17:46:02 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:24 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define FT_INT_MIN -2147483648
# define FT_INT_MAX 2147483647

typedef size_t	t_index;

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

char		*ft_strupper(char *str);
char		*ft_strlower(char *str);

int			ft_sqrt_floor(int nb);
int			ft_sqrt_ceil(int nb);

int			*ft_range(int min, int max);
int			*ft_range_step(int min, int max, int step);

long long	ft_min(long long x, long long y);
long long	ft_max(long long x, long long y);

int			ft_count_if(char **tab, int (*f)(char*));

void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(long long n);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		*ft_memrcpy(void *dst, const void *src, size_t n);
void		*ft_memdup(const void *src, size_t len);
void		*ft_memichr(const void *s, int c, size_t n);
void		*ft_memrchr(const void *s, int c, size_t n);

void		*ft_slow_memchr(const void *s, int c, size_t n);

int			ft_memccmp(const void *s1, const void *s2, int c, size_t n);
size_t		ft_strclen(const char *s, char c);
size_t		ft_strllen(const char *s, size_t size);
char		*ft_strndup(const char *s1, size_t len);
void		strrepl(char **dst, char const *src);
char		*ft_strichr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strctrim(char const *s, char c);
int			ft_islower(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);
size_t		ft_log(unsigned int base, unsigned long long n);
char		*ft_itoa_base(long long n, unsigned int base);
char		*ft_utoa_base(unsigned long long n, unsigned int base);

typedef struct s_magicmask	t_magicmask;

struct		s_magicmask
{
	unsigned long	lomagic;
	unsigned long	himagic;
	unsigned long	word;
};

# pragma mark - Lists

typedef struct s_list	t_list;

struct		s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void(*del)(void*, size_t));
void		ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list*(*f)(t_list *elem));

# pragma mark - Dictionary

typedef struct s_kvpair	t_kvpair;

struct		s_kvpair
{
	int		key;
	void	*value;
};

typedef struct s_dict	t_dict;

struct		s_dict
{
	t_kvpair	*pair;
	t_dict		*next;
};

t_dict		*ft_dictnew(void);
t_dict		*ft_dictadd(t_dict *dict, int key, void *content);
t_dict		*ft_dictget(t_dict *dict, int key);
void		ft_dictremove(t_dict *dict, int key);
void		ft_dictfree(t_dict *dict);

t_list		*ft_lstdequeue(t_list **alst);
t_list		*ft_lstunlink(t_list **head_node, t_list *to_unlink);
void		ft_lstappend(t_list **alst, t_list *new);

#endif
