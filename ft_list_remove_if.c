// Assignment name  : ft_list_remove_if
// Expected files   : ft_list_remove_if.c
// Allowed functions: free
// --------------------------------------------------------------------------------

// Write a function called ft_list_remove_if that removes from the
// passed list any element the data of which is "equal" to the reference data.

// It will be declared as follows :

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// cmp takes two void* and returns 0 when both parameters are equal.

// You have to use the ft_list.h file, which will contain:

// $>cat ft_list.h
// typedef struct      s_list
// {
//     struct s_list   *next;
//     void            *data;
// }                   t_list;
// $>



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list {
	struct s_list	*next;
	void			*data;

}	t_list;


t_list *new_list(void *data)
{
	t_list *lst;
	lst = malloc(sizeof (t_list));
	if(!lst)
		return(NULL);
	lst -> data = data;
	lst -> next = NULL;

	return (lst);
}

int cmp(void *data1,void *data2)
{
	if (*(int*)data1 == *(int*)data2)
		return(0);
	else
		return(1);
}

/*******tohle je ta divna funkce kde je hrozne hvezdicek*******/

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (!*begin_list || ! begin_list)
		return;

	t_list *remove;

	if(cmp ((*begin_list) -> data, data_ref) == 0)
	{
		remove = *begin_list;
		*begin_list = (*begin_list) -> next;
		free (remove);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&((*begin_list)-> next), data_ref, cmp);
}

/*****************************************************************/

void print_list(t_list *begin_list)
{
   t_list *print = begin_list;
    while (print != NULL)
    {
       printf("%s ", (char *)print -> data);
	   print = print -> next;
    }
    printf("\n");
}


int main(void)
{
	t_list *lst1 = new_list ("a");
	t_list *lst2 = new_list ("b");
	t_list *lst3 = new_list ("c");

	lst1 -> next = lst2;
	lst2 -> next = lst3;
	lst3 -> next =NULL;

print_list(lst1);

ft_list_remove_if(&lst1, "b", cmp);

print_list(lst1);

while (lst1)
{
	t_list *free_list;
	free_list = lst1;

	while (lst1 != NULL)
	{
		free_list = lst1;
		lst1 = lst1 -> next;
		free(free_list);
	}
}
	return(0);
}
