#include"list.h"
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

int main(int ac, char **av)
{
    if(ac != 3)
    {
        putstr("ERROR : ./a.out <num_threads> <num_per_threads>", fileno(stderr));
        return EXIT_FAILURE;
    }
    unsigned int num_threads = 0;
    unsigned int num_per_threads = 0;
    if(parse_av(av[1], &num_threads) == false || parse_av(av[2], &num_per_threads) == false)
    {
        putstr("ERROR : The arguments must be int valid ",fileno(stderr));
        return(EXIT_FAILURE);
    }
    if(num_threads <=0 || num_per_threads <=0)
    {
        putstr("ERROR : The arguments must be int with value > 0 ",fileno(stderr));
        return(EXIT_FAILURE);
    }
    
    size_t total =(size_t) num_per_threads * num_threads;
    t_list positive_list, negative_list;
    if(list_init(&positive_list, total)==false || list_init(&negative_list, total)==false)
    {
        putstr("ERROR : Error initializing lists", fileno(stderr));
        return(EXIT_FAILURE);
    }
    pthread_t *threads = NULL;
    putstr("FIN",fileno(stdout));
    return(EXIT_SUCCESS);

}