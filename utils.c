#include "utils.h"
void putstr(const char *str, int fd)
{
    int i =0;
    while(str && str[i])
    {
        write(fd,&str[i], 1);
        i++;
    }
    write(fd,"\n",1);
}