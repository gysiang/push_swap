/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algo1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:04:06 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/23 17:24:16 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	sort_three_checker(t_stack **a)
{
	t_stack	*max;

	if (ft_is_sorted(a))
		return ;
	max = find_max_node(*a);
	if (*a == max)
		rotate(a);
	else if ((*a)->next == max)
		reverse_rotate(a);
	if (((*a)->value) > ((*a)->next->value))
		swap(a);
}

void	sort_five_checker(t_stack **a, t_stack **b)
{
	int	first_two;

	first_two = 2;
	while (first_two-- > 0)
		push(a, b);
	while (*b)
	{
		initiate_stacks_stackb(a, b);
		move_node_stackb_checker(a, b);
	}
	set_index(*a);
	shift_smallest_to_top(a);
}

void	turk_sort_checker(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*a) > 3)
		push(a, b);
	sort_three(a);
	while (*b)
	{
		initiate_stacks_stackb(a, b);
		move_node_stackb_checker(a, b);
	}
	set_index(*a);
	shift_smallest_to_top(a);
}

void	push_swap_checker(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_stacksize(*a);
	if (ft_is_sorted(a))
		return ;
	else if (len_a <= 3)
		sort_three_checker(a);
	else if (len_a == 5)
		sort_five_checker(a, b);
	else
		turk_sort_checker(a, b);
}
