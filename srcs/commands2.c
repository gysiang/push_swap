/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:55:50 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/18 09:56:23 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr_stacka(t_stack **stack_a, t_stack **stack_b, t_stack *target)
{
	while (*stack_a != target && *stack_b != target->target_node)
	{
		ft_rr(stack_a, stack_b);
	}
	set_index(*stack_a);
	set_index(*stack_a);
}

void	rrr_stacka(t_stack **stack_a, t_stack **stack_b, t_stack *target)
{
	while (*stack_a != target && *stack_b != target->target_node)
	{
		ft_rrr(stack_a, stack_b);
	}
	set_index(*stack_a);
	set_index(*stack_a);
}
