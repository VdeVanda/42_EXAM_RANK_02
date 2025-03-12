/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int					ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
*/

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}
/*
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	t_list	*begin_list;
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*list4;

	list1 = malloc(sizeof(t_list));
	list2 = malloc(sizeof(t_list));
	list3 = malloc(sizeof(t_list));
	list4 = malloc(sizeof(t_list));
	list1->data = "1";
	list1->next = list2;
	list2->data = "2";
	list2->next = list3;
	list3->data = "3";
	list3->next = list4;
	list4->data = "4";
	list4->next = NULL;
	begin_list = list1;
	printf("%d\n", ft_list_size(begin_list));
	return (0);
}
*/
