#include "list.h"

bool list_push(t_list *lst, int value)
{
    pthread_mutex_lock(&lst->lock);
    if(lst->i >= lst->cap)
    {
        pthread_mutex_unlock(&lst->lock);
        return(false);
    }
    lst->data[lst->i++] = value;
    pthread_mutex_unlock(&lst->lock);
    return true;
}
void list_free(t_list *lst)
{
    if(lst ==NULL)
        return;
    pthread_mutex_destroy(&lst->lock);
    free(lst->data);
    lst->data =NULL;
    lst->i =0;
    lst->cap =0;
}
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