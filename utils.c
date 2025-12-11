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
int cmp(const void *a,const void *b)
{
    const int *a_value = (const int *)a;
    const int *b_value = (const int *)b;

    int x=*a_value;
    int y=*b_value;

    if(x > y)
        return 1;
    else if(x < y)
        return -1;
    return 0;
}
void list_sort(t_list *lst)
{
    qsort(lst->data,lst->i, sizeof(int),cmp);
}