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

int	ft_cmp_int(int a, int b)
{
	return a - b;
}

t_list	*sort_list(t_list *l, int (*cmp)(int, int))
{
	(void)(*cmp)(0, 0);
	t_list *curr = l;
	t_list *next = curr->next;
	while (curr)
	{
		next = curr->next;
		while (next)
		{
			if ((*cmp)(*(int *)curr->data, *(int *)next->data) > 0)
			{
				void* t = curr->data;
				curr->data = next->data;
				next->data = t;
			}
			next = next->next;
		}
		curr = curr->next;
	}
	return l;
}

int	main(void)
{
	int d1 = 0, d2 = 2, d3 = -10;
	
	t_list *list = NULL;

	push_front(&list, &d1);
	push_front(&list, &d2);
	push_front(&list, &d3);

	ft_print_list(list);
	sort_list(list, ft_cmp_int);
	ft_print_list(list);
	return 0;
}















