/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:10:23 by spipitku          #+#    #+#             */
/*   Updated: 2023/09/15 12:48:26 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*put_s1_s2(char const *s1, char const *s2, size_t len1, size_t len2);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s);

char	*ft_read_and_init_i(int *number_read, char *answer, int fd, int *i);

char	*ft_cut_new_line(char *answer, char **last_buffer, int i);

char	*free_null(char *answer, char *buffer, int check, int *i_main);

char	*get_next_line(int fd);

#endif
