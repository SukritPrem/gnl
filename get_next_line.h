#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int	put_s1_s2_to_ptr(char **ptr, char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *s);

char    *get_next_line(int fd);

#endif
