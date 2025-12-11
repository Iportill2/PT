#ifndef LIST_H
#define LIST_H

#include <pthread.h>


#include<unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>


typedef struct s_list {
    int *data;
    size_t i;
    size_t cap;
    pthread_mutex_t lock;
} t_list;

bool list_init(t_list *lst, size_t cap);



#endif