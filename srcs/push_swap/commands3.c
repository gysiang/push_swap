/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:40:27 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/15 15:11:08 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_target_to_top_of_a(t_stack **stack_a, t_stack *target)
{
	while (*stack_a != target)
	{
		if (target->above_median)
			ft_rra(stack_a);
		else
			ft_ra(stack_a);
	}
}

void	rotate_target_to_top_of_b(t_stack **stack_b, t_stack *target)
{
	while (*stack_b != target)
	{
		if (target->above_median)
			ft_rrb(stack_b);
		else
			ft_rb(stack_b);
	}
}

void	rotate_both_stacks(t_stack **stack_a, t_stack **stack_b,
		t_stack *target)
{
	while (*stack_a != target->target_node && *stack_b != target)
	{
		ft_rr(stack_a, stack_b);
	}
	set_index(*stack_a);
	set_index(*stack_a);
}

void	reverse_rotate_both_stacks(t_stack **stack_a, t_stack **stack_b,
		t_stack *target)
{
	while (*stack_a != target->target_node && *stack_b != target)
	{
		ft_rrr(stack_a, stack_b);
	}
	set_index(*stack_a);
	set_index(*stack_a);
}

void	shift_smallest_to_top(t_stack **a)
{
	t_stack	*smallest;

	smallest = find_min_node(*a);
	if (smallest->above_median == 0)
	{
		while (*a != smallest)
			ft_ra(a);
	}
	else
	{
		while (*a != smallest)
			ft_rra(a);
	}
}
