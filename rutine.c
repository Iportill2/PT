#include "list.h"
#include "rutine.h"
#include "utils.h"

void *rutine(void *arg)
{
    t_args *a =(t_args*) arg;
    unsigned int i =0;
    int num =0;
    long long min_max_range = (long long)INT_MAX -(long long)INT_MIN +1;
    unsigned int pthread_id =(unsigned int )(size_t) pthread_self();

    while(i < a->per_thread)
    {
        long long ramdom_value =rand_r(&pthread_id);
        long long ramdom_num = (ramdom_value * min_max_range) / (long long)RAND_MAX;
        num =(int)(ramdom_num +INT_MIN);
        if (num >= 0) 
        { 
            if (list_push(a->pos, num)== false ) 
                putstr("ERROR: list positive full", fileno(stderr)); 
        } 
        else 
        { 
            if (list_push(a->neg, num) == false) 
                putstr("ERROR: lista negative full", fileno(stderr)); 
        }
        i++;
    }
    return NULL;
}