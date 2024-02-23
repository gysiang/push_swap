/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:42:30 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/23 19:21:39 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	rotate_target_to_top_of_a_checker(t_stack **stack_a, t_stack *target)
{
	while (*stack_a != target)
	{
		if (target->above_median)
			reverse_rotate(stack_a);
		else
			rotate(stack_a);
	}
}

void	rotate_target_to_top_of_b_checker(t_stack **stack_b, t_stack *target)
{
	while (*stack_b != target)
	{
		if (target->above_median)
			reverse_rotate(stack_b);
		else
			rotate(stack_b);
	}
}

void	rotate_both_stacks_checker(t_stack **stack_a, t_stack **stack_b,
		t_stack *target)
{
	while (*stack_a != target->target_node && *stack_b != target)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	set_index(*stack_a);
	set_index(*stack_b);
}

void	reverse_rotate_both_stacks_checker(t_stack **stack_a, t_stack **stack_b,
		t_stack *target)
{
	while (*stack_a != target->target_node && *stack_b != target)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	set_index(*stack_a);
	set_index(*stack_b);
}

void	move_node_stackb_checker(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest_node(*b);
	if (cheapest_node->target_node->above_median
		&& cheapest_node->above_median)
	{
		reverse_rotate_both_stacks_checker(a, b, cheapest_node);
	}
	else if (!(cheapest_node->target_node->above_median)
		&& !(cheapest_node->above_median))
	{
		rotate_both_stacks_checker(a, b, cheapest_node);
	}
	rotate_target_to_top_of_b_checker(b, cheapest_node);
	rotate_target_to_top_of_a_checker(a, cheapest_node->target_node);
	push(b, a);
}
