/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:01:36 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/22 10:02:20 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function will swap the first two nodes of the stack for stack a
 * and output "sa" to console.
*/
void	ft_sa(t_stack **a)
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

void	reverse_rotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*second_last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second_last = *a;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	second_last->next->next = first;
	*a = second_last->next;
	second_last->next = NULL;
}
