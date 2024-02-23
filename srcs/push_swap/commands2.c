/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:55:50 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/23 16:42:02 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
/**
void	rr_stacka(t_stack **stack_a, t_stack **stack_b, t_stack *target)
{
	while (*stack_a != target && *stack_b != target->target_node)
	{
		ft_rr(stack_a, stack_b);
	}
	set_index(*stack_a);
	set_index(*stack_a);
}

void	rrr_stacka(t_stack **stack_a, t_stack **stack_b, t_stack *target)
{
	while (*stack_a != target && *stack_b != target->target_node)
	{
		ft_rrr(stack_a, stack_b);
	}
	set_index(*stack_a);
	set_index(*stack_a);
} **/

/**
 * This function will reverse rotate stack a up, last node becomes first node,
 * the rest moves down and output "rra" to console.
*/
void	ft_rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

/**
 * This function will reverse rotate stack b, last node becomes first node,
 * the rest moves down and output "rrb" to console.
*/
void	ft_rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
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

void	rrr_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
