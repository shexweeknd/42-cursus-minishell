/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:02:13 by ballain           #+#    #+#             */
/*   Updated: 2024/11/03 19:40:48 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "libft_struct.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);
size_t	ft_get_occ(char *str, char c);
int		ft_lenvar_name(char *arg);
int		ft_issvar(char c);
int		ft_isvar(char *str);
int		ft_isspace(const int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isnbr(char *str);
int		ft_isprint(int c);
int		ft_isdecimal(char *base);
int		ft_isset(const char *str, char *set);
int		is_only_spaces(char *str);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_nl_to_zero(char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_toupper_str(char *str);
char	*ft_tolower_str(char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd);
size_t	get_line_size(char *str);
size_t	get_twodim_char_size(char **buffer);
void	free_two_dim(char **buffer);
void	_loop(void **src, t_lst_utils utils);
void	ft_add_front_(void **src, void *new, t_lst_utils utils);
void	ft_add_back_(void **src, void *new, t_lst_utils utils);
char	*ft_lstjoin(t_list *lst, char sep);
int		ft_lst_content_len(t_list *lst);
int		ft_getlen_strtab(char *tab[]);
char	*ft_str_replace(char *src, char *to_find, char *replace, int all);
char	*ft_join(char *str[]);
void	ft_putnbr_fd(int n, int fd);
int		ft_is_quote(const char c);
int		ft_is_cmd_sep(const char c);
int		ft_is_redirect(const char c);
int		ft_is_delimiter(const char c);
int		_skip_space(char *str);
int		skip_until(char *prompt, char offset);

char	*to_ps_two(char cmd, char *value);
int		ft_nblen(int nb);
void	ft_perror_fd(int fd, char *var[]);

#endif
