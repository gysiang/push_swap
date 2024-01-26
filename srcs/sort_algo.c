/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:46:16 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/26 18:39:45 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_sa(t_list **a)
{
	t_list *first;
	t_list *second;
	t_list *tmp;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	tmp = second->next;
	*a = second;
	second->next = first;
	first->next = tmp;
	ft_printf("sa\n");
}

/**
 * move first node to end of list
 * rest of the nodes move up
*/
void	ft_ra(t_list **a)
{
	t_list *first;
	t_list *second;
	t_list *last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	last = ft_lstlast(*a);
	*a = second;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

/**
 * last node attach to top of stack
 * second last node link to NULL
*/
void	ft_rra(t_list **a)
{
	t_list *first;
	t_list *second_last;

	if (!*a || !(*a)->next)
		return;
	first = *a;
	second_last = *a;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	second_last->next->next = first;
	*a = second_last->next;
	second_last->next = NULL;
	ft_printf("rra\n");
}

/**
 * Push the head node of b to top of a
*/
void	ft_pa(t_list **a, t_list **b)
{
	t_list *node;

	if (!*b)
		return ;
	node = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = node;
	ft_printf("pa\n");
}

/**
 * Push the head node of a to top of b
*/
void	ft_pb(t_list **a, t_list **b)
{
	t_list *node;

	if (!*a)
		return ;
	node = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = node;
	ft_printf("pb\n");
}

/**
 * Sorts 3 elements in ascending order
 * If largest number at top, ra
 * If at middle, rra
 * Check the first two nodes, swap if needed
*/
void	ft_simple_sort(t_list **a)
{
	intptr_t	max;

	if (ft_is_sorted(a))
		return ;
	max = find_max_value(a);
	if ((intptr_t)(*a)->content == max)
		ft_ra(a);
	else if ((intptr_t)(*a)->next->content == max)
		ft_rra(a);
	if (((intptr_t)(*a)->content) > ((intptr_t)(*a)->next->content))
		ft_sa(a);
}
