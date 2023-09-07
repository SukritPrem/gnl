
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	// fd = open("files/empty", O_RDWR);
	fd = open("test3",O_RDONLY);
	// printf("before close = %d\n",fd);
	// close(fd);
	// printf("before close = %d\n",fd);
	char *ptr;
	// while(ptr)
	// {
	// 	printf("%s\n",ptr);
	// 	ptr = get_next_line(fd);
	// 	free(ptr);
	// }
	// printf("%s",ptr);
	// free(ptr);
	ptr = get_next_line(fd);
	// printf("++++++++++++++++++++%d",ptr == NULL);
	// free(ptr);
	// ptr =get_next_line(fd);
	// printf("++++++++++++++++++++%s",ptr);
	// free(ptr);
	// ptr =get_next_line(fd);
	// free(ptr);
	// printf("++++++++++++++++++++%s",ptr);
	// 	ptr =get_next_line(fd);
	// free(ptr);
	// printf("++++++++++++++++++++%s",ptr);
	// 	ptr =get_next_line(fd);
	// printf("++++++++++++++++++++%s",ptr);
	// free(ptr);
	// 	ptr =get_next_line(fd);
	// printf("++++++++++++++++++++%s",ptr);
	// free(ptr);
	// ptr =get_next_line(fd);
	// printf("++++++++++++++++++++%s",ptr);
	// free(ptr);
	// ptr =get_next_line(fd);
	// printf("++++++++++++++++++++%s",ptr);
	// free(ptr);
	// printf("%s\n",get_next_line(fd)== NULL);
	// while(1)
	// {
	// 	ptr = get_next_line(fd);
	// 	if(ptr == NULL)
	// 		break;
	// 	printf("%s", ptr);
	// 	free(ptr);
	// }
}
