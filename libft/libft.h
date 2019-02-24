/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:17:00 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/11/27 19:17:01 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define GNL_BUFF_SIZE 1000

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_bst
{
	int				key;
	void			*content;
	size_t			content_size;
	struct s_bst	*left;
	struct s_bst	*right;
}					t_bst;

typedef struct		s_avl
{
	int				key;
	int				height;
	void			*content;
	size_t			content_size;
	struct s_avl	*left;
	struct s_avl	*right;
}					t_avl;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *string);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *h, const char *n, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_del(void *lst, size_t size);
t_list				*ft_lstappend(t_list *start, t_list *new);
int					ft_isupper(int c);
int					ft_islower(int c);
void				ft_freearray(void **arr, int elems);
char				**ft_strrealloc(const char *str, char **line);
void				ft_sortshell(int *arr, size_t size);
void				ft_swap(int *a, int *b);
void				ft_sortbubble(int *arr, size_t size);
int					ft_iswhitespace(char c);
void				ft_bitsprint(unsigned n, int format);
size_t				ft_bitsnbr(long a);
void				ft_sortinsertion(int *arr, size_t size);
void				ft_sortquick(int *arr, size_t size);
void				ft_strreverse(char *str);
char				*ft_itoaws(int n, int width, char symbol);
void				ft_putcharn(char c, int n);
size_t				ft_digitsnbr(int n);
void				ft_putstrw(char const *s, size_t width, char c);
int					ft_max(int a, int b);
void				ft_tree_del(void **node, void (*f)(void *, size_t));
void				*ft_tree_delone(void *root, int key);
void				*ft_tree_new(int k, void *cont, size_t c_sz, size_t n_sz);
void				*ft_tree_search(void *node, int key);
void				*ft_tree_find_parent(void *node, int key);
t_bst				*ft_tree_bst_new(int k, void *c, size_t c_size);
t_bst				*ft_tree_bst_insert(t_bst *root, t_bst *node);
void				ft_tree_bst_print(t_bst *root);
t_avl				*ft_tree_avl_new(int k, void *cont, size_t c_size);
t_avl				*ft_tree_avl_insert(t_avl *root, t_avl *node);
int					ft_tree_avl_getbalance(t_avl *node);
int					ft_tree_avl_getheight(t_avl *node);
void				ft_tree_avl_print(t_avl *root);
t_avl				*ft_tree_avl_rotate_right(t_avl *node);
t_avl				*ft_tree_avl_rotate_left(t_avl *node);
t_avl				*ft_tree_avl_delone(t_avl *root, int key);
int					ft_get_next_line(const int fd, char **line);
#endif
