#include "get_next_line.h"

static t_list **push_group_word_main_to_answer(char  **answer_main, t_list **group_word_main)
{
  t_list  *group_word;
  t_list  *new_list;
  char  *answer;
  char  *string;
  size_t  i;

  i = 0;
  answer = *answer_main;
  group_word = *group_word_main;
	new_list = NULL;
  while(group_word)
  {
    string = group_word->content;
    new_list = group_word->next;
    i = 0;
    while(*(string + i) != '\n' && *(string + i))
      *answer++ = *(string + i++);
    if(*(string + i) == '\n')
    {
			if((*(string + i + 1)))
		  {
      	new_list = ft_lstnew_get_next(string + i + 1);
				new_list->next = group_word->next;
			}
      free(group_word->content);
      free(group_word);
      *group_word_main = new_list;
      if(i == 0)
        *answer++ = '\n';
      if(i > 0)
        *answer++ = '\n';
      *answer = '\0';
      return (group_word_main);
    }
    if(!(*(string + i)) && group_word->next == NULL)
    {
      free(group_word->content);
      free(group_word);
      *group_word_main = new_list;
      *answer = '\0';
      return (group_word_main);
    }
    free(group_word->content);
    free(group_word);
    group_word = new_list;
  }
  return (group_word_main);
}

static t_list *readfile_and_get_to_group_word(t_list **group_word_main,int fd)
{
  char *buffer;
  int number_alpha_after_read;

  number_alpha_after_read = 1;
  while(number_alpha_after_read != 0)
  {
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    number_alpha_after_read = read(fd, buffer, BUFFER_SIZE );
    buffer[number_alpha_after_read] = '\0';
    if(number_alpha_after_read)
      add_buffer_to_group_word(&(*group_word_main),buffer);
    else
      free(buffer);
  }
  return (*group_word_main);
}

char *get_next_line(int fd)
{
	char *answer;
	static t_list *group_word;
  static int  i;

  i++;
  // printf("--------> %d",i);
	if(fd < 0)
	 return(NULL);
  if(!group_word)
	 group_word = readfile_and_get_to_group_word(&group_word,fd);
  answer = del_and_create_answer(&group_word);
	return(answer);
}

size_t size_before_newline(t_list **word)
{
  size_t  i;
  size_t  i_word;
  t_list  *word_clone;
  char  *string;

  i_word = 0;
  i = 1;
  word_clone = *word ;
  while(word_clone && i)
  {
    string = word_clone->content;
    while(*string != '\n' && *string)
    {
			string++;
      i_word++;
    }
    if(*string == '\n')
    {
      i_word++;
      break;
    }
    word_clone = word_clone->next;
  }
  return (i_word);
}

char	*del_and_create_answer(t_list **group_word_main)
{
  t_list *group_word;
  char *answer;
  size_t i;

  if(group_word_main == NULL)
    return (NULL);
  group_word = *group_word_main;
  // t_list *check;
  // check = group_word;
  // while(group_word)
  // {
  //   // printf("group word =========== %s\n",group_word->content);
  //   group_word = group_word->next;
  // }
  // group_word = check;
  i = size_before_newline(&(*group_word_main));
  // printf("count word = %zu\n",i);
  answer = malloc(sizeof(char) * i + 1);
  group_word_main = push_group_word_main_to_answer(&answer,&(*group_word_main));
  return (answer);
}

t_list  *ft_lstnew_get_next(char  *s)
{
  char  *ptr;
  size_t  i;

  i = 0;
  t_list  *new_list;
  if(!s)
    return (0);
  while(*(s + i))
    i++;
  // printf("----------+++++++++++ %zu\n",i);
  ptr = malloc(i + 1);
  ptr = ft_strcpy(ptr,s,i);
  // printf("----------+++++++++++ %s\n",ptr);
  new_list = malloc(sizeof(t_list));
  new_list -> content = ptr;
  new_list -> next = NULL;
  return(new_list);
}

void	*ft_strcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (n)
	{
		*d++ = *s++;
		n--;
	}
  *d = '\0';
	return (dest);
}

void  add_buffer_to_group_word(t_list **group_word_main,char *buffer)
{
  t_list  *group_word;
  t_list  *tmp;
  t_list  *go_last;

  group_word = *group_word_main;
  if(!group_word)
  {
    tmp = ft_lstnew(buffer);
    *group_word_main = tmp;
  }
  else
  {
    tmp = ft_lstnew(buffer);
    go_last = *group_word_main;
    while(go_last->next)
      go_last = go_last->next;
    go_last->next = tmp;
  }
}



// int main()
// {
//   int fd;

//   fd = open("test1.txt",O_RDONLY);
//   // // printf("fd = %d\n",fd);
//   // char BUFF[1000];
//   // read(fd, &BUFF, 2);
//   // printf(">>>>>{%d}", BUFF[0]);
//   char *ptr = get_next_line(fd);
//   printf("%s\n",ptr);
//   free(ptr);
//   ptr = get_next_line(fd);
//   printf("%s\n",ptr);
//   free(ptr);
//   ptr =get_next_line(fd);
//   printf("%s\n",ptr);
//   free(ptr);
//   ptr =get_next_line(fd);
//   printf("%s\n",*ptr);
//     free(ptr);
//   // ptr =get_next_line(fd);
//   //   free(ptr);
//   // ptr =get_next_line(fd);
//   //   free(ptr);
//   // ptr = get_next_line(fd);
//   //   free(ptr);
// 	// ptr = get_next_line(fd);
// 	//   free(ptr);
// 	// ptr = get_next_line(fd);
// 	// 	free(ptr);
//   close(fd);
// }
