/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:40:27 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/01 12:51:51 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/**
void	rotate_target_to_top(t_stack **stack, t_stack *target, char stack_name)
{
	while (*stack != target)
	{
		if (stack_name == 'a')
		{
			if (target->above_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (target->above_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
} **/

void	rotate_target_to_top_of_a(t_stack **stack_a, t_stack *target)
{
	while (*stack_a != target)
	{
		if (target->above_median)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

void	rotate_target_to_top_of_b(t_stack **stack_b, t_stack *target)
{
	while (*stack_b != target)
	{
		if (target->above_median)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
	}
}

void	shift_smallest_to_top(t_stack **a)
{
	t_stack	*smallest;

	smallest = find_min_node(*a);
	if (smallest->above_median)
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
