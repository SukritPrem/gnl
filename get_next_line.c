#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *answer;
	static t_list *group_word;

	if(fd < 0)
	 return(NULL);
  if(!group_word)
	 group_word = readfile_and_get_to_group_word(&group_word,fd);
  // answer = del_and_create_answer(&group_word);
  int i = 0;
  // free(answer);
  while(group_word)
  {
    printf("group_word %d = %s\n",i++,group_word->content);
    group_word = group_word->next;
  }

  // ft_lstclear(&group_word, free);
  // answer = get_line(&group_word);
	// if(group_word != NULL)
  // 	delete_before_newline(&group_word);

	// close(fd);
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
      i_word++;
      *string++;
    }
    if(*string == '\n')
      i = 0;
    word_clone = word_clone->next;
  }
  i_word--;
  return (i_word);
}

char  *del_and_create_answer(t_list **group_word_main)
{
  t_list *group_word;
  char *answer;
  size_t i;

  group_word = *group_word_main;
  if(!group_word)
  {
    printf("Hello\n");
    return (NULL);
  }
  i = size_before_newline(&(*group_word_main));
  // printf("size word = %ld\n",i);
  answer = malloc(sizeof(char) * i + 1);
  *group_word_main = push_group_word_main_to_answer(&answer,&(*group_word_main));
  printf("%s\n",answer);
  return (answer);
}

static t_list *push_group_word_main_to_answer(char  **answer_main, t_list **group_word_main)
{
  t_list  *group_word;
  t_list  *new_list;
  char  *answer;
  char  *string;
  size_t  i;

  i = 0;
  answer = *answer_main;
  group_word = *group_word_main;
  while(group_word)
  {
    string = group_word->content;
    new_list = group_word->next;
    i = 0;
    while(*string != '\n' && *(string + i))
      *answer++ = *(string + i++);
    if(*(string + i++) == '\n')
    {
      printf("string = %s\n",string);
      new_list = ft_lstnew_get_next(string + i);
      // printf("string = %s\n",new_list->content);
      new_list->next = group_word->next;
      t_list *check = new_list;
      while(new_list)
      {
        printf("%s\n",new_list->content);
        new_list = new_list->next;
      }
      new_list = check;
      ft_lstdelone(group_word,free);
      group_word = new_list;
      *answer = '\0';
      return (group_word);
    }
    ft_lstdelone(group_word,free);
    group_word = new_list;
  }
  free(group_word);
  return (0);
}

t_list  *ft_lstnew_get_next(char  *s)
{
  char  *ptr;
  t_list  *new_list;

  // printf("s = %s\n",s);
  // printf("len s = %ld\n",ft_strlen_get(s));
  ptr = malloc(ft_strlen_get(s) + 1);
  ptr = ft_strcpy(ptr,s,ft_strlen_get(s));
  // printf("s = %s",ptr);
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

size_t  ft_strlen_get(char *s)
{
  size_t  i;

  i = 0;
  // printf("s = %s\n",s);
  if(!s)
    return (0);
  while(*s && *s != '\n')
  {
    i++;
    s++;
  }
  return (i);
}
static t_list *readfile_and_get_to_group_word(t_list **group_word_main,int fd)
{
  char *buffer;
  int number_alpha_after_read;
  t_list  *group_word;
  int i = 0;

  group_word = *group_word_main;
  number_alpha_after_read = 1;
  while(i <= 27)
  {
    buffer = ft_calloc(sizeof(char) * (BUFFER_SIZE + 1),1);
    number_alpha_after_read = read(fd, buffer, BUFFER_SIZE );
    // buffer[number_alpha_after_read + 1] = '\0';
    // printf("check buffer and readline\n");
    //bugs fuckkkkkkkkkkkkkkkkkkkkkkkkkkk
    if(i == 27)
      printf("buffer = %d | read = %d\n",buffer[2],number_alpha_after_read);
    if(number_alpha_after_read)
      add_buffer_to_group_word(&group_word,buffer);
    else
      free(buffer);
    i++;
  }
  return (group_word);
  // t_list *check_group_word = group_word;
  // int i = 0;
  // while(group_word)
  // {
  //   printf("group_word %d = %s\n",i++,group_word->content);
  //   group_word = group_word->next;
  // }
  // group_word = check_group_word;
  // i = 0;
  // ft_lstclear(&group_word, free);
  // free(group_word);
}

void  add_buffer_to_group_word(t_list **group_word_main,char *buffer)
{
  t_list  *group_word;
  t_list  *tmp;

  group_word = *group_word_main;
  if(!group_word)
  {
    tmp = ft_lstnew(buffer);
    *group_word_main = tmp;
  }
  else
  {
    tmp = ft_lstnew(buffer);
    ft_lstadd_back(&(*group_word_main),tmp);
  }
}

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*tmp;
//
// 	if (!lst && !new)
// 		return ;
// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	tmp = ft_lstlast(*lst);
// 	tmp->next = new;
// }

int main()
{
  int fd;

  fd = open("test.txt",O_RDONLY);
  // printf("fd = %d\n",fd);
  char *ptr = get_next_line(fd);
  free(ptr);
  ptr =get_next_line(fd);
    free(ptr);
  ptr =get_next_line(fd);
    // free(ptr);
  ptr =get_next_line(fd);
    // free(ptr);
  ptr = get_next_line(fd);
    // free(ptr);
  close(fd);
}
