/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:40 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/24 12:12:47 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function will set a target node (from stack a)
 * for each node of b. The target node should be the smallest bigger
 * number than the current b node.
*/

void	set_target_node_stackb(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*target;
	long	max;

	while (b)
	{
		max = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value
				&& curr_a->value < max)
			{
				max = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (max == LONG_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target;
		b = b->next;
	}
}
/**
 * This function sets the required indexes, target node, moving cost
 * cheapest cost for stack b.
*/

void	initiate_stacks_stackb(t_stack **a, t_stack **b)
{
	set_index(*a);
	set_index(*b);
	set_target_node_stackb(*a, *b);
	set_rotcost(*a, *b);
	set_cheapest(*b);
}

void	move_node_stackb(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest_node(*b);
	if (cheapest_node->target_node->above_median
		&& cheapest_node->above_median)
	{
		reverse_rotate_both_stacks(a, b, cheapest_node);
	}
	else if (!(cheapest_node->target_node->above_median)
		&& !(cheapest_node->above_median))
	{
		rotate_both_stacks(a, b, cheapest_node);
	}
	rotate_target_to_top_of_b(b, cheapest_node);
	rotate_target_to_top_of_a(a, cheapest_node->target_node);
	ft_pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	first_two;

	first_two = 2;
	while (first_two-- > 0)
		ft_pb(a, b);
	sort_three(a);
	while (*b)
	{
		initiate_stacks_stackb(a, b);
		move_node_stackb(a, b);
	}
	set_index(*a);
	shift_smallest_to_top(a);
}
