/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:03:15 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/22 15:27:22 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * This function will loop through the stack to look for the node
 * with the biggest value and return a pointer to that node.
*/

t_stack	*find_max_node(t_stack *stack)
{
	long	max;
	t_stack	*biggest_node;

	if (stack == NULL)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
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
