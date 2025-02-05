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

void	fadd(void *data)
{
	*((int *)data) += 1;
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *curr = begin_list;
	while (curr)
	{
		(*f)(curr->data);
		curr = curr->next;
	}
}

void	ft_print_list(t_list *list)
{
	t_list *curr = list;
	while (curr)
	{
		if (curr->next)
			printf("%d -> ", *((int *)(curr->data)));
		else
			printf("%d\n", *((int *)(curr->data)));
		curr = curr->next;
	}
}

void	ft_free_list(t_list *list)
{
	free(list);
}

int	main(void)
{
	int d1 = 2, d2 = 10, d3 = -10;

	t_list *list = NULL;
	//spoiler kids d2 is on this list 3 time
	//but the pointer is the same
	//any change would change the value for all list elements
	//crazy uh?
	//ye dont do this
	//create each new int for each elem
	//this is just a little experiment lol, have fun coding along xD
	push_front(&list, &d2);
	push_front(&list, &d2);
	push_front(&list, &d1);
	push_front(&list, &d3);
	push_front(&list, &d2);

	printf("list before:\n");
	ft_print_list(list);
	ft_list_foreach(list, fadd);
	printf("list after foreach:\n");
	ft_print_list(list);
	ft_free_list(list);
	return 0;
}


















