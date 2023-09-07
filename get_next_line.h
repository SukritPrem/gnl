
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include "Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
#endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

void  add_buffer_to_group_word(t_list **group_word_main,char *buffer);

char	*del_and_create_answer(t_list **group_word_main);

char *get_next_line(int fd);

size_t size_before_newline(t_list **word);

t_list  *ft_lstnew_get_next(char  *s);

size_t  ft_strlen_get(char *s);

void	*ft_strcpy(void *dest, const void *src, size_t n);

t_list	*ft_lstnew(void *content);

void	ft_lstdelone(t_list *lst, void (*del)(void *));
#endif
