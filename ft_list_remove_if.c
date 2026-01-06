// Assignment name  : ft_list_remove_if
// Expected files   : ft_list_remove_if.c
// Allowed functions: free
// --------------------------------------------------------------------------------

// Write a function called ft_list_remove_if that removes from the
// passed list any element the data of which is "equal" to the reference data.

// It will be declared as follows :

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// cmp takes two void* and returns 0 when both parameters are equal.



#include <stdio.h>
#include <unistd.h>
#include "ft_list.h"

int *cmp(void *a, void *b)
{
	int diff = *(int *)a  - *(int *)b;
	return(diff);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{

	t_list *tmp;

	if(begin_list == NULL || *begin_list == NULL)
		return;
	
	if (cmp ((*begin_list)-> data, data_ref) == 0) 
	{
		tmp = *begin_list;
		*begin_list = (*begin_list) -> next;
		free (tmp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else 
		ft_list_remove_if(&((*begin_list)-> next), data_ref, cmp);
}



