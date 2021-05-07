/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:59:35 by nbirdper          #+#    #+#             */
/*   Updated: 2021/01/29 22:37:17 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);

void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isempty_str(const char *str);

int					ft_toupper(int c);
int					ft_tolower(int c);

char				*ft_itoa(int n);
int					ft_atoi(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_indexof(const char *str, int c);
int					ft_last_indexof(char *str, int c);

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int32_t				ft_strlen(const char *str);
char				*ft_get_alloc_str(int32_t len);

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_substr(const char *src, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *src, const char *set);
char				**ft_split(const char *src, char c);
char				*ft_strdup(const char *s1);
char				*ft_strmapi(const char *src, char (*f)(unsigned int, char));

/** Write functions **/
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putnbr_fd(int n, int fd);

/** List functions **/
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/**	Additional functions	**/
/**	Functions for 2arr		**/
char				**ft_2arr_char_alloc(size_t h, size_t w);
int					**ft_2arr_int_alloc(size_t h, size_t w);
int					ft_2arr_viter(char **arr, int column, int (*f)(int));
int32_t				ft_2arr_get_rows(const char **arr);
void				ft_free_2arr(char **arr);
char				**ft_2arr_dup(const char *src_arr[]);
int					ft_copy_2arr(char *dst_arr[], char *src_arr[]);
char				**ft_expand_2arr(const char *src_arr[], int src_len,
						int dst_len);

int					ft_any(char **arr, int(*f)(char*));
int					ft_any_str(char **arr, int(*f)(int));
void				ft_foreach(int *arr, int length, void(*f)(int));
int					ft_foreach_str(const char *str, int(*f)(int));
int					*ft_map(int *src_arr, int length, int(*f)(int));
int					ft_count_if(char **str, int length, int (*f)(char*));
int					ft_count_if_str(char *str, int length, int (*f)(int));

#endif
