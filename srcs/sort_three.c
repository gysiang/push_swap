/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:03:15 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/16 14:03:29 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
