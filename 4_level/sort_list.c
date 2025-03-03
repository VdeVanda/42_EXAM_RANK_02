/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

#include "ft_list.h"

// Função para ordenar uma lista ligada usando uma função de comparação
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swap; // Variável para armazenar temporariamente os dados durante a troca
	t_list *tmp;  // Ponteiro temporário para o início da lista

	tmp = lst; // Inicializa tmp com o início da lista
	while (lst->next != 0) // Percorre a lista até o penúltimo nó
	{
		// Se a função de comparação retornar 0, significa que os dados estão fora de ordem
        if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			// Troca os dados entre os nós
            swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
            // Reinicia a iteração a partir do início da lista
			lst = tmp;
		}
		else
             // Avança para o próximo nó
			lst = lst->next;
	}
	// Restaura o ponteiro lst para o início da lista
    lst = tmp;
	return (lst);
}