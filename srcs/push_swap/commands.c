/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:01:36 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/23 16:16:00 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * This function will swap the first two nodes of the stack.
*/
void	swap(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	tmp = second->next;
	*a = second;
	second->next = first;
	first->next = tmp;
}

/**
 * This function will swap the first two nodes of the stack for stack a
 * and output "sa" to console.
*/
void	ft_sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	rotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	last = ft_stacklast(*a);
	*a = second;
	last->next = first;
	first->next = NULL;
}

/**
 * This function will rotate stack a, second node becomes the
 * start of list ,first node becomes last node and output "ra" to console.
*/
void	ft_ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

/**
 * This function will rotate stack b, second node becomes the
 * start of list ,first node becomes last node and output "rb" to console.
*/
void	ft_rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}
