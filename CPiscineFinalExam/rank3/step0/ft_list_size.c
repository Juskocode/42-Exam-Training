#include <stdlib.h>

typedef struct    s_list
{
	struct s_list	*next;
	void          	*data;
}                 	t_list;

t_list	*create_elem(void *data)
{
	t_list *new_node = malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->data = data;
		new_node->next = NULL;
	}
	return new_node;
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	
	if (*begin_list)
	{
		t_list *to_add = create_elem(data);
		to_add->next = *begin_list;
		*begin_list = to_add;
		return ;
	}
	*begin_list = create_elem(data);
}

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	t_list	*curr = begin_list;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return i;
}

#include <stdio.h>

int	main(void)
{
	int	d1 = 2, d2 = 3, d3 = -10;

	t_list *list = NULL;

	ft_list_push_front(&list, &d1);
	ft_list_push_front(&list, &d1);
	ft_list_push_front(&list, &d2);
	ft_list_push_front(&list, &d3);

	int size = ft_list_size(list);
	printf("%d", size);

	return 0;
}
