#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list 	*next;
	void		*data;
}			t_list;

t_list	*create_elem(void *data)
{
	t_list *node = malloc(sizeof(t_list));
	if (node)
	{
		node->data = data;
		node->next = NULL;
	}
	node->next = NULL;
	return (node);
}

void	push_front(t_list **list, void *data)
{
	if (!*list)
	{
		*list = create_elem(data);
		return ;
	}
	t_list *node = create_elem(data);
	node->next = *list;
	*list = node;
}

void	ft_print_list(t_list *list)
{
	t_list *curr = list;
	while (curr)
	{
		if (curr->next)
			printf("%d -> ", *(int *)curr->data);
		else
			printf("%d\n", *(int *)curr->data);
		curr = curr->next;
	}
}

int	ft_cmp_int(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *it = *begin_list;
	t_list *t;

	while (it && it->next)
	{
		if ((*cmp)(it->next->data, data_ref) == 0)
		{
			t = it->next;
			it->next = it->next->next;
			printf("removing: %d\n", *(int *)t->data);
			//free(t->data);
			free(t);
			//case repeated to_remove elems
			continue;
		}
		it = it->next;
	}
	//case 1 elem
	it = *begin_list;
	if (it && (*cmp)(it->data, data_ref) == 0)
	{
		
		printf("removing: %d\n", *(int *)it->data);
		*begin_list = it->next;
		//free(it->data);
		free(it);
	}
}

int	main(void)
{
	int	d1 = 2, d2 = 2, d3 = 3, d4 = 10, d5 = 2, d6 = 2, d7 = 2;
	int	to_remove = 2;
	t_list *list = NULL;
	
	push_front(&list, &d7);
	push_front(&list, &d6);
	push_front(&list, &d4);
	push_front(&list, &d5);
	push_front(&list, &d2);
	push_front(&list, &d3);
	push_front(&list, &d1);

	ft_print_list(list);
	ft_list_remove_if(&list, &to_remove, ft_cmp_int);
	ft_print_list(list);
	free(list);
	return 0;
}






























