#include"list.h"
#include "rutine.h"
#include "utils.h"
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

void list_print(const t_list *lst)
{
    size_t i = 0;
    while (i < lst->i)
    {
        printf("[%zu] %d\n", i, lst->data[i]);
        i++;
    }
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
    threads =malloc(sizeof(pthread_t) * num_threads);
    if(threads == NULL)
    {
        putstr("ERROR: failed to allocate memory for threads",fileno(stderr));
        list_free(&positive_list);
        list_free(&negative_list);
        return(EXIT_FAILURE);
    }
    t_args args;
    args.per_thread=num_per_threads;
    args.pos = &positive_list;
    args.neg = &negative_list;
    unsigned int i =0;
    while(i < num_threads)
    {
        pthread_create(&threads[i],NULL,rutine,&args);
        i++;
    }
    i=0;
    while(i < num_threads)
    {
        pthread_join(threads[i],NULL);
        i++;
    }
    free(threads);
    list_print(args.pos);

    putstr("FIN",fileno(stdout));
    return(EXIT_SUCCESS);

}