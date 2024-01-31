/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:18:01 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/31 11:35:45 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack **stack)
{
	t_stack *head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void printList(t_stack *stack)
{
    ft_printf("Printing linked list:\n");
    while (stack != NULL)
	{
		ft_printf("Node index: %d", stack->index);
		//ft_printf(", is above median: %d", stack->above_median);
		//ft_printf(", target node: %d", stack->target_node->value);
		//ft_printf(", push cost: %d", stack->rot_cost);
		//ft_printf(", is_cheapest: %d", stack->is_cheapest);
        ft_printf(", Node value: %d\n", stack->value);
        stack = stack->next;
    }
    ft_printf("End of linked list\n");
}

t_stack	*ft_stacknew(long content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = content;
	new -> next = NULL;
	return (new);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*lastlst;

	lastlst = lst;
	while (lst != NULL)
	{
		lastlst = lst;
		lst = lst -> next;
	}
	return (lastlst);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_stacklast(*lst);
	last -> next = new;
}
