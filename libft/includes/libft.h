/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:25:51 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/16 20:23:24 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "ft_printf.h"

# define MAXINT  0x7fffffff
# define MININT  0xffffffff
# define MAXLONG 0x7fffffffffffffff
# define MINLONG 0xffffffffffffffff

# define BUF_SIZE  4096
# define BUFF_SIZE 1
# define MAX_FD    15000

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

void				ft_display_file(const char *src);
void				ft_swap(int *a, int *b);
void				ft_putnendl(const char *s, size_t n);
void				ft_bzero(void *dst, size_t n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_wcsdel(wchar_t **aw);

void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				*ft_realloc(void *dst, size_t nd,\
								const void *src, size_t ns);
void				*ft_memdup(const void *src, size_t n);
void				*ft_memjoin(const void *p1, size_t n1,\
								const void *p2, size_t n2);
void				*ft_memsub(const void *src, size_t start, size_t n);

void				*ft_memset(void *dst, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);

int					ft_abs(int a);
int					pratoi(char **src, int *pr_nb);
int					pratoi_hex(char **src, int *pr_nb);
int					ft_putchari(int c, int fd);
int					ft_putchari_fd(int c, int fd);
int					get_next_line(const int fd, char **line);
int					ft_pow(int n, int power);
int					ft_isprime(int n);
int					ft_sqrt(int	n);
int					ft_err(int retv, void **p);
int					ft_masserr(int retv, int **m);
int					ft_nmasserr(int retv, int ***nm, size_t n);
int					ft_strerr(int retv, char **s);
int					ft_nstrerr(int retv, char ***ns);
int					ft_puterr(int retv, const char *s);
int					ft_chrcnt(const char *src, char c);
int					ft_memcmp(const void *src1, const void *src2, size_t n);
int					ft_atoi(const char *src);
int					ft_strcmp(const char *src1, const char *src2);
int					ft_strncmp(const char *src1, const char *src2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);

size_t				ft_strlchr(const char *src, char c);
size_t				ft_strlen(const char *src);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);

char				*ft_strfnew(size_t size, char c);
char				*ft_strrealloc(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, \
								const char *needle, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				*ft_itoa(int n);

char				**ft_nstrnew(size_t size);
char				**ft_strsplit(const char *s, char c);

wchar_t				*ft_wcsdup(const wchar_t *src);
wchar_t				*ft_wcsnew(size_t size);
#endif
