
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Libft/libft.h"

#define BUFFER_SIZE 2

static t_list *readfile_and_get_to_group_word(t_list **group_word_main,int fd);

void  add_buffer_to_group_word(t_list **group_word_main,char *buffer);

char	*del_and_create_answer(t_list **group_word_main);

size_t size_before_newline(t_list **word);

static t_list **push_group_word_main_to_answer(char  **answer, t_list **group_word_main);

t_list  *ft_lstnew_get_next(char  *s);

size_t  ft_strlen_get(char *s);

void	*ft_strcpy(void *dest, const void *src, size_t n);
#endif
