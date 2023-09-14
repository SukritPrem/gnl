
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// #define BUFFER_SIZE 10

int	put_s1_s2_to_ptr(char **ptr, char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *s);

char    *get_next_line(int fd)
{
  int number_read;
  static char *last_buffer;
  char  *buffer;
  char  *answer;
  char  *tmp;
  char  *send;
  int i;
  int j;
  int k;

  k = 0;
  j = 0;
  i = 0;
  buffer = malloc(BUFFER_SIZE + 1);
  number_read = 1;
  tmp = NULL;
  answer = NULL;
  if(fd < 0)
    return(NULL);
  if(last_buffer)
    answer = last_buffer;
  while(number_read != 0)
  {
    number_read = read(fd,buffer,BUFFER_SIZE);
    if(!number_read)
      break;
    buffer[BUFFER_SIZE + 1] = '\0';
    // printf("%s",buffer);
    // printf("----\n");
    i = 0;
    // while(buffer[i] != '\n' && buffer[i])
    //   i++;
    // if(buffer[i] == '\n')
    //   break;
    if(!answer)
      answer = ft_strdup("");
    tmp = ft_strjoin(answer,buffer);
    // printf("%s",tmp);
    free(answer);
    answer = tmp;

    while(buffer[i] != '\n' && buffer[i])
      i++;
    if(buffer[i++] == '\n')
      break;
    free(buffer);
  }
  // printf("i = %d | number_read = %d\n",i,number_read);
  j = 0;
  k = i;
  if(i < number_read && answer)
  {
    last_buffer = malloc(number_read - i + 1);
    // printf("%d\n",number_read - i + 1);
    while(buffer[i])
      last_buffer[j++] = buffer[i++];
    last_buffer[j] = '\0';
    send = malloc(i + 1);
    // i = 0;
    j = 0;
    while(j < k)
    {
      send[j] = answer[j];
      j++;
    }
    free(answer);
    if(buffer)
      free(buffer);
    // printf("%s",send);
    // printf("%d j\n",j);
    // printf("%s",last_buffer);
  }
  else if(i == number_read && answer)
  {
    send = malloc(i + 1);
    // i = 0;
    j = 0;
    while(j < k)
    {
      // printf("answer = %c \n",answer[j]);
      send[j] = answer[j];
      j++;
    }
    send[j] = '\0';
    free(answer);
    if(buffer)
      free(buffer);
    // printf("%s",send);
  }
  return(send);
}

char	*ft_strdup(const char *s)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	while (*(s + i))
	{
		ptr[i] = *(s + i);
		i++;
	}
  // printf("II\n");
	ptr[i] = '\0';
	return (ptr);
}

int	put_s1_s2_to_ptr(char **ptr, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
		(*ptr)[j++] = s1[i++];
	i = 0;
	while (i < ft_strlen(s2))
		(*ptr)[j++] = s2[i++];
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		sum_len;
	char		*ptr;
	size_t		i;

	i = 0;
	if (!s2 && !s1)
		return (NULL);
	if (!*s1 && !*s2)
		return (ft_strdup(""));
  // printf("HH\n");
	sum_len = ft_strlen(s1) + ft_strlen(s2);
  // printf("%ld\n",sum_len);
	if (sum_len == 0)
		return ((char *)0);
	ptr = malloc(sum_len + 1);
	if (!ptr)
		return (ptr);
	i = put_s1_s2_to_ptr(&ptr, s1, s2);
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	num_size;

	num_size = 0;
	while (*(s + num_size) != '\0')
		num_size++;
	return (num_size);
}

// int main()
// {
//     int fd;
//
//     fd = open("test",O_RDONLY);
//     char *test;
//     int i = 2;
//
//     test = get_next_line(fd);
//     printf("%s",test);
//     free(test);
//     test = get_next_line(fd);
//     printf("%s\n",test);
//     free(test);
// }
