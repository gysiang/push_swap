/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:01:36 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/31 17:03:20 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function will swap the first two nodes of the stack for stack a
 * and output "sa" to console.
*/
void ft_sa(t_stack **a)
{
	t_stack *first;
	t_stack *second;
	t_stack *tmp;

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
 * This function will rotate stack a, second node becomes the
 * start of list ,first node becomes last node and output "ra" to console.
*/
void	ft_ra(t_stack **a)
{
	t_stack *first;
	t_stack *second;
	t_stack *last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	last = ft_stacklast(*a);
	*a = second;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

/**
 * This function will rotate stack b, second node becomes the
 * start of list ,first node becomes last node and output "rb" to console.
*/
void	ft_rb(t_stack **b)
{
	t_stack *first;
	t_stack *second;
	t_stack *last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	last = ft_stacklast(*b);
	*b = second;
	last->next = first;
	first->next = NULL;
	ft_printf("rb\n");
}

/**
 * This function will reverse rotate stack a up, last node becomes first node,
 * the rest moves down and output "rra" to console.
*/
void	ft_rra(t_stack **a)
{
	t_stack *first;
	t_stack *second_last;

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
 * This function will reverse rotate stack b, last node becomes first node,
 * the rest moves down and output "rrb" to console.
*/
void	ft_rrb(t_stack **b)
{
	t_stack *first;
	t_stack *second_last;

	if (!*b || !(*b)->next)
		return;
	first = *b;
	second_last = *b;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	second_last->next->next = first;
	*b = second_last->next;
	second_last->next = NULL;
	ft_printf("rrb\n");
}
