/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:34:55 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/31 17:43:03 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_stack **a, char **av)
{
	t_stack *new;
	char	**tmp;
	int		i;
	long	n;

	i = 0;
	tmp = ft_split(av[1], ' ');
	while (tmp[i])
	{
		n = ft_long_atoi(tmp[i]);
		new = ft_stacknew(n);
		ft_stackadd_back(a, new);
		i++;
	}
	free_tmp_array(tmp);
}

/**
 * set the element that has the cheapest rot cost to true
*/
void	set_cheapest(t_stack *stack)
{
	long min;
	t_stack *cheapest_node;

	if (stack == NULL)
		return ;
	min = LONG_MAX;
	while (stack)
	{
		if (stack->rot_cost < min)
		{
			min = stack->rot_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = true;
}

/**
 * Function that sets index in stack starting from 0 to end of list
*/
void	set_index(t_stack *stack)
{
	int i;
	int	median;
	int stack_len;

	i = 0;
	stack_len = ft_stacksize(stack);
	median = (stack_len / 2) + 1;
	while (stack)
	{
		if (stack != NULL)
		{
			stack->index = i;
			if (i <= median)
				stack->above_median = false;
			else
				stack->above_median = true;
		}
		i++;
		stack = stack->next;
	}
}

/**
 * Sets the price to push node from b to a
*/
void	set_rotcost(t_stack *a, t_stack *b)
{
	int len_a;
	int len_b;

	len_a = ft_stacksize(a);
	len_b = ft_stacksize(b);
	while (b)
	{
		b->rot_cost = b->index;
		if (b->above_median == 1)
			b->rot_cost = len_b - b->index;
		if (b->target_node->above_median == 1)
			b->rot_cost += b->target_node->index;
		else
			b->rot_cost += len_a - (b->target_node->index);
		b = b->next;
	}
}
