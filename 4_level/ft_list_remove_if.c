/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/

#include "ft_list.h"
#include <stdlib.h>

// Função para remover nós da lista ligada com base numa referência de dados
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	// Verifica se a lista está vazia ou se o ponteiro é NULL
    if (begin_list == NULL || *begin_list == NULL)
		return;
    // Ponteiro para o nó atual
	t_list *cur = *begin_list;

    // Se os dados do nó atual corresponderem aos dados de referência
	if (cmp(cur->data, data_ref) == 0)
	{
		// Atualiza o ponteiro do início da lista para o próximo nó
        *begin_list = cur->next;
        // Liberta a memória do nó atual
		free(cur);
        // Chama recursivamente a função para continuar a remover nós
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
    // Atualiza o ponteiro cur para o início da lista (após possível remoção)
	cur = *begin_list;
    // Chama recursivamente a função para processar o próximo nó na lista
	ft_list_remove_if(&cur->next, data_ref, cmp);
}
