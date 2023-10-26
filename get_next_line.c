/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:51:29 by spipitku          #+#    #+#             */
/*   Updated: 2023/09/15 12:06:57 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			number_read;
	static char	*last_buffer;
	char		*answer;
	int			i;

	i = 0;
	number_read = 1;
	answer = NULL;
	if (last_buffer)
	{
		answer = last_buffer;
		last_buffer = NULL;
	}
	if (fd < 0)
		return (NULL);
	answer = ft_read_and_init_i(&number_read, answer, fd, &i);
	if (number_read == 0 && answer)
	{
		while (answer[i] != '\n' && answer[i] != '\0')
			i++;
	}
	answer = ft_cut_new_line(answer, &last_buffer, i);
	return (answer);
}

char	*ft_cut_new_line(char *answer, char **last_buffer, int i)
{
	int	length;

	length = ft_strlen(answer);
	if (length != 0)
		*last_buffer = ft_substr(answer, i + 1, length - i);
	if (!length)
	{
		free(answer);
		return (NULL);
	}
	while (answer && answer[i])
	{
		if (answer[i] == '\n')
		{
			answer[i + 1] = '\0';
			break ;
		}
		i++;
	}
	return (answer);
}

char	*free_null(char *answer, char *buffer, int check, int *i_main)
{
	int	i;

	i = 0;
	if (check == 1)
	{
		free(answer);
		free(buffer);
	}
	else if (check == 2)
	{
		while (answer[i] != '\n' && answer[i] != '\0')
			i++;
		*i_main = i;
	}
	return (NULL);
}

char	*ft_read_and_init_i(int *number_read, char *answer, int fd, int *i_main)
{
	char	*tmp;
	char	*buffer;
	int		i;

	buffer = malloc(BUFFER_SIZE + 1);
	while (*number_read != 0)
	{
		*number_read = read(fd, buffer, BUFFER_SIZE);
		if (*number_read < 0)
			return (free_null(&(*answer), &(*buffer), 1, &(*i_main)));
		if (!*number_read)
			break ;
		buffer[*number_read] = '\0';
		i = 0;
		if (!(answer))
			answer = ft_strdup("");
		tmp = ft_strjoin(answer, buffer);
		free(answer);
		answer = tmp;
		free_null(&(*answer), NULL, 2, &(*i_main));
		if (answer[*i_main] == '\n')
			break ;
	}
	free(buffer);
	return (answer);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	while (*(s + i))
	{
		ptr[i] = *(s + i);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int	put_s1_s2_to_ptr(char **ptr, char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (i < ft_strlen(s1))
// 		(*ptr)[j++] = s1[i++];
// 	i = 0;
// 	while (i < ft_strlen(s2))
// 		(*ptr)[j++] = s2[i++];
// 	return (j);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t		sum_len;
// 	char		*ptr;
// 	size_t		i;

// 	i = 0;
// 	if (!s2 && !s1)
// 		return (NULL);
// 	if (!*s1 && !*s2)
// 		return (ft_strdup(""));
// 	sum_len = ft_strlen(s1) + ft_strlen(s2);
// 	if (sum_len == 0)
// 		return ((char *)0);
// 	ptr = malloc(sum_len + 1);
// 	if (!ptr)
// 		return (ptr);
// 	i = put_s1_s2_to_ptr(&ptr, s1, s2);
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	num_size;

// 	num_size = 0;
//   if(!s)
//     return(0);
// 	while (*(s + num_size) != '\0')
// 		num_size++;
// 	return (num_size);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char		*ptr;
// 	size_t		i;

// 	i = 0;
// 	if (!s && !start && !len)
// 		return (ft_strdup(""));
// 	if (!s)
// 		return (NULL);
// 	if (ft_strlen(s) == 0 || start > ft_strlen(s))
// 		return (0);
// 	if (ft_strlen(s + start) < len)
// 		len = ft_strlen(s + start);
// 	ptr = malloc(len + 1);
// 	if (!ptr)
// 		return (NULL);
// 	while (len--)
// 		ptr[i++] = s[start++];
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// int main()
// {
//     int fd;

//     fd = open("test",O_RDONLY);
//     char *test;
//     int i = 2;

//     test = get_next_line(10);
//     printf("++%s",test);
//     free(test);
//     test = get_next_line(fd);
//     printf("++%s",test);
//     free(test);
//     char c = 0 ;read(fd,&c,1);
//     printf("-->%c\n",c);
//     test = get_next_line(fd);
//     printf("++%s",test);
//     free(test);
//     test = get_next_line(fd);
//     printf("++%s",test);
//     free(test);
//      test = get_next_line(fd);
//     printf("++%s",test);
//     free(test);
// }