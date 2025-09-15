#include <stdio.h>
#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int main ()
{
int fd = open("h.txt",O_RDONLY);
char *len;
while ((len = get_next_line(fd)) != 0)
{
 printf(" f1 :%s",len);
 free(len);
}
// int fd1 = open("hh.txt",O_RDONLY);
// char *len2;
// while ((len2 = get_next_line(fd1)) != 0)
// {
//  printf("f2 ;  %s",len2);
//  free(len2);
// }

// int fd2 = open("hhh.txt",O_RDONLY);
// char *len3;
// while ((len3 = get_next_line(fd2)) != 0)
// {
//  printf("f3 ;  %s",len3);
//  free(len3);
// }

    
}