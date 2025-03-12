/*
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void				ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
*/

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

// Função para imprimir os dados do nó
void	print_data(void *data)
{
	printf("%s\n", (char *)data);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Criando nós da lista
	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node3 = (t_list *)malloc(sizeof(t_list));
	// Inicializando dados dos nós
	node1->data = "Node 1";
	node1->next = node2;
	node2->data = "Node 2";
	node2->next = node3;
	node3->data = "Node 3";
	node3->next = NULL;
	// Testando a função ft_list_foreach
	ft_list_foreach(node1, print_data);
	// Liberando memória alocada
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/