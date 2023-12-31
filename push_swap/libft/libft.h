/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:51:01 by Arturg04          #+#    #+#             */
/*   Updated: 2023/10/28 15:51:25 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648
# define FT_INT_MAX_PLUS 2147483648
# define FT_INT_MIN_PLUS -2147483649 

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void			ft_bzero(void *src,
					size_t n);

void			*ft_memccpy(void *dest,
					const void *src,
					int c,
					size_t n);

void			*ft_memchr(const void *src,
					int c,
					size_t n);

int				ft_memcmp(const void *str1,
					const void *str2,
					size_t n);

void			*ft_memcpy(void *dest,
					void const *src,
					size_t n);

void			*ft_memmove(void *dest,
					const void *src,
					size_t n);

void			*ft_memset(void *src,
					int c,
					size_t n);

char			*ft_strchr(const char *str,
					int c);

size_t			ft_strlcat(char *dst,
					const char *src,
					size_t size);

size_t			ft_strlcpy(char *dest,
					const char *src,
					size_t size);

size_t			ft_strlen(const char *str);

char			*ft_strrchr(const char *str,
					int c);

char			*ft_strnstr(const char *str,
					const char *locate,
					size_t size);

int				ft_strncmp(const char *str,
					const char *cmp,
					size_t n);

long long int	ft_atoi(const char *nptr);

int				ft_isalpha(int c);

int				ft_isdigit(int c);

int				ft_isalnum(int c);

int				ft_isascii(int c);

int				ft_isprint(int c);

int				ft_tolower(int c);

int				ft_toupper(int c);

void			*ft_calloc(size_t nmemb,
					size_t size);

char			*ft_strdup(const char *str);

char			*ft_substr(char const *s,
					unsigned int start,
					size_t len);

char			*ft_strjoin(char const *s1,
					char const *s2);

char			*ft_strtrim(char const *s1,
					char const *set);

char			**ft_split(char const *s,
					char c);

char			*ft_itoa(int n);

char			*ft_strmapi(char const *s,
					char (*f)(unsigned int, char));

void			ft_striteri(char *s,
					void (*f)(unsigned int, char*));

void			ft_putchar_fd(char c,
					int fd);

void			ft_putstr_fd(char *s,
					int fd);

void			ft_putendl_fd(char *s,
					int fd);

void			ft_putnbr_fd(int n,
					int fd);

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **lst,
					t_list *new);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst,
					t_list *new);

void			ft_lstdelone(t_list *lst,
					void (*del)(void *));

void			ft_lstclear(t_list **lst,
					void (*del)(void*));

void			ft_lstiter(t_list *lst,
					void (*f)(void *));

t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *),
					void (*del)(void *));

#endif
