#ifndef UTILS_H
#define UTILS_H

#include "list.h"

void putstr(const char *str, int fd);
int cmp(const void *a,const void *b);
void list_sort(t_list *lst);

#endif