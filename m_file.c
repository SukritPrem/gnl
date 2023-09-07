#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("test3", O_WRONLY);
    for (int i = 0; i < 100000; i++)
    {
        write(fd, "A", 1);
    }
    close (fd);
}