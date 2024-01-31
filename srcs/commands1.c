/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:03:22 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/31 10:52:34 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Push the head node of b to top of a
*/
void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack *node;

	if (!*b)
		return ;
	node = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = node;
	ft_printf("pa\n");
}

/**
 * Push the head node of a to top of b
*/
void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack *node;

	if (!*a)
		return ;
	node = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = node;
	ft_printf("pb\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_rb(b);
	ft_printf("rr\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a);
	ft_rrb(b);
	ft_printf("rrr\n");
}
