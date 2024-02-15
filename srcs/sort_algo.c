/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:46:16 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/15 09:27:00 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function will set a target node (from stack a)
 * for each node of b. The target node should be the smallest bigger
 * number than the current b node.
*/

static void	set_target_node(t_stack *a, t_stack *b)
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

void	initiate_stacks(t_stack **a, t_stack **b)
{
	set_index(*a);
	set_index(*b);
	set_target_node(*a, *b);
	set_rotcost(*a, *b);
	set_cheapest(*b);
}

/**
 * Sorts 3 elements in ascending order
 * If largest number at top, ra
 * If at middle, rra
 * Check the first two nodes, swap if needed
*/
void	sort_three(t_stack **a)
{
	t_stack	*max;

	if (ft_is_sorted(a))
		return ;
	max = find_max_node(*a);
	if (*a == max)
		ft_ra(a);
	else if ((*a)->next == max)
		ft_rra(a);
	if (((*a)->value) > ((*a)->next->value))
		ft_sa(a);
}

/**
 * Rotate the stacks until both target node in a and cheapest node are
 * both at the top to the stacks. Push from stack b to stack a
*/


static void	move_node(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest_node(*b);
	if (cheapest_node->target_node->above_median
		&& cheapest_node->above_median)
	{
		rotate_both_stacks(a, b, cheapest_node);
	}
	else if (!cheapest_node->target_node->above_median
		&& !cheapest_node->above_median)
	{
		reverse_rotate_both_stacks(a, b, cheapest_node);
	}
	rotate_target_to_top_of_b(b, cheapest_node);
	rotate_target_to_top_of_a(a, cheapest_node->target_node);
	ft_pa(a, b);
}

/**
 * This function will initalise the push swap algorithm by pushing
 * elements from a to b until there are 3 elements left in b. It will
 * then start to move the nodes from stack b to stack a in order until
 * there are no elements left in stack b.
*/
void	push_swap(t_stack **a, t_stack **b)
{
	int	len_a;
	int first_two;

	first_two = 2;
	len_a = ft_stacksize(*a);
	if (ft_is_sorted(a))
		return ;
	if (len_a == 3)
		sort_three(a);
	while (first_two-- > 0)
		ft_pb(a, b);
	sort_three(a);
	while (*b)
	{
		initiate_stacks(a, b);
		move_node(a, b);
	}
	set_index(*a);
	shift_smallest_to_top(a);
/**	while (len_a-- > 3)
		ft_pb(a, b);
	ft_simple_sort(a);
	while (*b)
	{
		initiate_stacks(a, b);
		move_node(a, b);
	}
	set_index(*a);
	shift_smallest_to_top(a);
	**/
}
