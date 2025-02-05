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
			printf("%d ->", curr->data);
		else
			printf("%d", curr->data);
		curr = curr->data;
	}
}
