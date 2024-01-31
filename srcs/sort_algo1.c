/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:40:27 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/31 17:44:23 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_targets_to_top(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
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
