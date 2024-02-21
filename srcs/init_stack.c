/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:34:55 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/22 02:03:54 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function will create stack with the numbers passed in
 * the params. It will use atol and insert the numbers in order into stack a.
*/
void	initalise_stack_a(t_stack **a, char *s)
{
	t_stack	*new;
	char	**tmp;
	int		i;
	long	n;

	i = 0;
	tmp = ft_split(s, ' ');
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
 * This function will go through the stack and look for the element with the
 * lowest code. It will then set is_cheapest to true.
*/
void	set_cheapest(t_stack *stack)
{
	long	min;
	t_stack	*cheapest_node;

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
 * This function will set the index for each element of the stack and
 * check whether it's position in the stack is above or below the median.
*/
void	set_index(t_stack *stack)
{
	int	i;
	int median;

	i = 0;
	median = ft_stacksize(stack) / 2;
	while (stack)
	{
		if (stack != NULL)
		{
			stack->index = i;
			if (i <= median)
				stack->above_median = 0;
			else
				stack->above_median = 1;
		}
		++i;
		stack = stack->next;
	}
}

/**
 * Sets the price to push node from b to a
*/
void	set_rotcost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stacksize(a);
	len_b = ft_stacksize(b);
	//ft_printf("len_a%d\n", len_a);
	//ft_printf("len_b%d\n", len_b);
	while (b)
	{
		b->rot_cost = b->index;
		if (b->above_median)
			b->rot_cost = len_b - (b->index);
		if (b->target_node->above_median)
			b->rot_cost += len_a - (b->target_node->index);
		else
			b->rot_cost += b->target_node->index;
		b = b->next;
	}
}
