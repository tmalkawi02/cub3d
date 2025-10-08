/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaryllis <amaryllismain09@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:45:20 by amaryllis         #+#    #+#             */
/*   Updated: 2025/03/06 10:53:19 by tmalkawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define BOOL unsigned int
# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/types.h>
# include <limits.h>
# include <stdbool.h>

int			ft_putnbr_len(int nb);
int			ft_printf(const char *s, ...);
int			ft_putstr_len(const char *s);
int			ft_putchar_len(const char c);
int			ft_pointer_in_hex(unsigned long long p);
int			ft_putunbr_len(unsigned int n);
int			ft_itohx(unsigned int n);
int			ft_hex_uppercase(unsigned int n);
int			ft_print_percent(const unsigned char percent);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
}	t_gnl_list;

char		*get_next_line(int fd);
size_t		my_strlen(const char *s);
void		stash_currently_read(int fd, t_gnl_list **stash);
void		emplace_in_list(t_gnl_list **stash, char *buf, int bytes_returned);
void		extract_line_by_lf(t_gnl_list *stash, char **line);
void		mema_line(t_gnl_list *stash, char **line);
void		free_stash(t_gnl_list **stash);
void		free_everything_gnl(t_gnl_list **stash);
int			has_new_line(t_gnl_list	*content);
t_gnl_list	*get_last_node(t_gnl_list *stash);

void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_free_tab(void **tab);

int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		**ft_strsdup(const char **s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(char const *s, char c);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strnstr(const char *big, const char *little, size_t len);
size_t		ft_strlen(const char *s);
size_t		ft_strslen(const char **s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dsize);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
bool		ft_strnull(const char *s);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_print_array(void **array);

long long	ft_atoll(const char *s);
int			ft_isalpha(int c);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_iswhitespace(char c);

#endif
