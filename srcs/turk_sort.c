/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:03:23 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/18 12:38:40 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function will set a target node (from stack a)
 * for each node of b. The target node should be the smallest bigger
 * number than the current b node.
*/

static void	set_target_node_stacka(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	t_stack	*target;
	long	max;

	while (a)
	{
		target = NULL;
		max = LONG_MAX;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value > a->value
				&& curr_b->value < max)
			{
				max = curr_b->value;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (max == LONG_MAX)
			a->target_node = find_min_node(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

/**
 * Sets the price to push node from a to b
*/
static void	set_rotcost_stacka(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stacksize(a);
	len_b = ft_stacksize(b);
	while (a)
	{
		a->rot_cost = a->index;
		if (a->above_median == 1)
			a->rot_cost = len_a - a->index;
		if (a->target_node->above_median == 1)
			a->rot_cost += a->target_node->index;
		else
			a->rot_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

/**
 * This function sets the required indexes, target node, moving cost
 * cheapest cost for stack b.
*/

static void	initiate_stacks_stacka(t_stack **a, t_stack **b)
{
	set_index(*a);
	set_index(*b);
	set_target_node_stacka(*a, *b);
	set_rotcost_stacka(*a, *b);
	set_cheapest(*a);
}

void	move_node_stacka(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest_node(*a);
	if (cheapest_node->target_node->above_median
		&& cheapest_node->above_median)
	{
		rr_stacka(a, b, cheapest_node);
	}
	else if (!cheapest_node->target_node->above_median
		&& !cheapest_node->above_median)
	{
		rrr_stacka(a, b, cheapest_node);
	}
	rotate_target_to_top_of_b(b, cheapest_node->target_node);
	rotate_target_to_top_of_a(a, cheapest_node);
	ft_pb(a, b);
}

void	turk_sort(t_stack **a, t_stack **b)
{
	int	first_two;

	first_two = 2;
	while (first_two-- > 0)
		ft_pb(a, b);
	while (ft_stacksize(*a) > 3)
	{
		initiate_stacks_stacka(a, b);
		move_node_stacka(a, b);
	}
	while (*b)
	{
		initiate_stacks_stackb(a, b);
		move_node_stackb(a, b);
	}
	set_index(*a);
	shift_smallest_to_top(a);
}
