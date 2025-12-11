#include "list.h"
bool list_init(t_list *lst, size_t cap)
{
    lst->data = NULL;
    lst->data = malloc(sizeof(int) * cap);
    if (lst->data == NULL)
        return false;
    lst->i = 0;
    lst->cap = cap;
    if (pthread_mutex_init(&lst->lock, NULL) != 0) 
    {
        free(lst->data);
        return false;
    }
    return true;
}