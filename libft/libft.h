/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 10:38:10 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/21 12:26:10 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
int				ft_atoi(const char *str);
void			ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t n, size_t s);
int				ft_isalnum(int i);
int				ft_isalpha(int i);
int				ft_isascii(int i);
int				ft_isdigit(int i);
int				ft_isprint(int i);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *destino, const void *origen, size_t n);
void			*ft_memmove(void *destino, const void *origen, size_t len);
void			*ft_memset(void *str, int c, size_t n);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strlen(const char *str);
int				ft_strnlen(const char *str, int len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_substr(char const *str, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));
char			**ft_insert_string(char **table, char *str);
#endif
