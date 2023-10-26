/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:55:12 by spipitku          #+#    #+#             */
/*   Updated: 2023/09/15 12:49:25 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_s1_s2(char const *s1, char const *s2, size_t len1, size_t len2)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	size_t	sum_len;

	i = 0;
	j = 0;
	sum_len = len1 + len2;
	if (sum_len == 0)
		return ((char *)0);
	ptr = malloc(sum_len + 1);
	if (!ptr)
		return (NULL);
	while (i < len1)
		(ptr)[j++] = s1[i++];
	i = 0;
	while (i < len2)
		(ptr)[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s2 && !s1)
		return (NULL);
	if (!*s1 && !*s2)
		return (ft_strdup(""));
	ptr = put_s1_s2(s1, s2, len1, len2);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	num_size;

	num_size = 0;
	if (!s)
		return (0);
	while (*(s + num_size) != '\0')
		num_size++;
	return (num_size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s && !start && !len)
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0 || start > ft_strlen(s))
		return (0);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (len--)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
