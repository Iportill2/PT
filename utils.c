#include "utils.h"
void list_print(const t_list *lst)
{
    size_t i = 0;
    while (i < lst->i)
    {
        printf("[%zu] %d\n", i, lst->data[i]);
        i++;
    }
}
bool parse_av(const char *av, unsigned int *out)
{
    errno = 0;
    char *end;
    long v =strtol(av, &end, 10);

    if(end == av)
        return false;
    if(errno == ERANGE)
        return false;
    if(*end != '\0')
        return false;
    if(v < INT_MIN || v > INT_MAX)
        return false;
    *out =(unsigned int ) v;
    return true;
}
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