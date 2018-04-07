/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 23:23:57 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 19:38:57 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

#define BASEKEY "0123456789abcdef"

typedef struct		s_list
{
	void			*data;
	size_t			d_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dblist
{
	void			*data;
	size_t			d_size;
	struct s_dblist	*prec;
	struct s_dblist	*next;
}					t_dblist;

typedef struct		s_queue
{
	t_dblist		*first;
	t_dblist		*last;
	int				qlen;
	int				min;
	int				max;
}					t_queue;

typedef struct		s_ffqueue
{
	t_list			*first;
	t_list			*last;
	int				qlen;
	int				min;
	int				max;
}					t_ffqueue;

void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isalpha(char c);
int					ft_isalnum(char c);
int					ft_isascii(int c);
int					ft_isdigit(char c);
int					ft_isprint(int c);
void				*ft_malloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, void *src, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char const *str, int fd);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(char const *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dst, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_nlookup(char *key, const char *str,
					size_t len, char b);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				ft_pushfront(t_queue *key, t_dblist *data);
void				ft_pushend(t_queue *key, t_dblist *data);
t_dblist			*ft_popfront(t_queue *key);
t_dblist			*ft_popend(t_queue *key);
int					ft_isspace(char c);
int					ft_skip_spaces(const char *str);
t_dblist			*ft_dblmergesort(t_dblist *head, int (*f)(void *, void *));
t_dblist			*ft_dblistnew(void *content, size_t content_size);
int					ft_enqueue(t_queue **key, void *data, size_t size);
void				ft_queue_postsort(t_queue *key);
t_dblist			*ft_dblistpop(t_dblist *node);
void				ft_queue_destruc(t_queue *key, t_dblist *(*f)(t_dblist *del));
int					ft_numlen(int num);
int					ft_atoi_base(const char *str, int base);
long				ft_atol_base(const char *str, int base);
char				*ft_strnchr(const char *s, int c);
t_list				*ft_listnew(void *content, size_t content_size);
void				ft_listadd(t_list **alst, void *content, size_t content_size);
t_list				*ft_listnew(void *content, size_t content_size);
int					ft_nnlookup(char *key, const char *str,
					size_t len, char b);
t_list				*ft_listpopfront(t_list **node);
t_list				*ft_listcritpop(t_list **node, int (*f)(void *));
t_list				*ft_sublistpop(t_list **node, int (*f)(void *));

int					ft_ffenqueue(t_ffqueue **key, void *data, size_t size);
void				ft_ffpushfront(t_ffqueue *key, t_list *data);
void				ft_ffpushend(t_ffqueue *key, t_list *data);
t_list				*ft_ffpopfront(t_ffqueue *key);
t_list				*ft_ffpopend(t_ffqueue *key);

int					ft_error(void);

#endif
