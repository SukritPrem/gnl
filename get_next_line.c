#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER 2

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s);

typedef struct s_list
{
  char  *last_word;
  char  *current_word;
} t_list;

char  *get_next_line(int fd);

size_t	ft_strlen(const char *s)
{
	int	num_size;

	num_size = 0;
	while (s[num_size] != '\0')
		num_size++;
	return (num_size);
}

int main()
{
  int fd;
  char  *ptr;
  fd = open("test", O_RDONLY);
  // char  ptry[] = "Hello";
  // printf("%s\n",ptry);
  // printf("%s\n",ptry+2);
  ptr = get_next_line(fd);
  printf("%s",ptr);
  free(ptr);
  ptr =get_next_line(fd);
  printf("%s",ptr);
  free(ptr);
  // ptr = get_next_line(fd);
  // free(ptr);

  // ptr = ft_strjoin(""," World\n");
  // printf("%s\n",ptr);
  // free(ptr);
  // get_next_line(fd);
}


char  *get_next_line(int fd)
{
  static t_list *group_word;
  char  *tmp_group_word;
  static int i;

  // printf("i ====================> %d\n",i++);
  // if(!group_word)
  // {

  //   group_word = malloc(sizeof(t_list));
  //   group_word->current_word = ft_strdup("");
  // }
  char *line;
  char *buffer;
  int number_read;
  number_read = 1;
  while(number_read != 0)
  {
        buffer = malloc(sizeof(char) * (BUFFER + 1));
        number_read = read(fd,  buffer, BUFFER);
        if(number_read == 0)
        {
          break;
        }
        buffer[BUFFER + 1] = '\0';

        if(!group_word)
        {
          group_word = malloc(sizeof(t_list));
          group_word->current_word = ft_strdup("");
        }
        if(group_word->last_word)
        {
            group_word->current_word = ft_strdup("");
            group_word->current_word = ft_strjoin(group_word->current_word,group_word->last_word);
            printf("ggg = %s\n",group_word->current_word);
            free(tmp_group_word);
        }
        group_word->last_word = ft_strchr(buffer,'\n');
        tmp_group_word = group_word->current_word;
        group_word->current_word = ft_strjoin(tmp_group_word,buffer);
        free(tmp_group_word);
        if(group_word->last_word)
        {
          tmp_group_word = group_word->current_word;
          group_word->current_word = ft_strjoin(tmp_group_word,group_word->last_word);
          free(tmp_group_word);
          return(group_word->current_word);
          break;
        }
        free(buffer);
  }
  if(number_read == 0)
  {
      // group_word->last_word = ft_strchr(buffer,'\n');
      if(group_word)
        return(group_word->current_word);
    // printf("%s\n",group_word->current_word);
    // free(group_word->current_word);
    // free(group_word->last_word);
    free(group_word);
    return(NULL);
  }
  // }
}

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*ptr;

	ptr = s;
	i = 0;
	c = (unsigned char)c;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return ((char *)(ptr + i));
		i++;
	}
	if ((size_t)i == ft_strlen(s) && c == 0)
		return ((char *)(ptr + i));
	return (0);
}

int	put_s1_s2_to_ptr(char **ptr, char const *s1, char const *s2)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
  {
    // printf("check\n");
		(*ptr)[j++] = s1[i++];
  }
	i = 0;
	while (i < ft_strlen(s2))
		(*ptr)[j++] = s2[i++];
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sum_len;
	char	*ptr;
	int		i;

	i = 0;
	if (!s2)
		return (NULL);
	if (!*s1 && !*s2)
		return (ft_strdup(""));
	sum_len = ft_strlen(s1) + ft_strlen(s2);
	if (sum_len == 0)
		return ((char *)0);
	ptr = malloc(sum_len + 1);
	if (!ptr)
		return (ptr);
	i = put_s1_s2_to_ptr(&ptr, s1, s2);
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

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
