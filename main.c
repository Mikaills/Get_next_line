#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("file.txt", O_RDONLY);
	int i = 0;
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

}