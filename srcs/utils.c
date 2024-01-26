/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:08:42 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/26 18:09:35 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_max_value(t_list **a)
{
	t_list *first;
	intptr_t max;
	intptr_t current;

	if (!a || !*a)
		return (0) ;
	first = *a;
	max = (intptr_t)first->content;

	while (first)
	{
		current = (intptr_t)first->content;
		if (current > max)
			max = current;
		first = first->next;
	}
	return ((int)max);
}

int find_min_value(t_list **a)
{
	t_list *first;
	intptr_t min;
	intptr_t current;

	if (!a || !*a)
		return (0) ;
	first = *a;
	min = (intptr_t)first->content;
	while (first)
	{
		current = (intptr_t)first->content;
		if (current < min)
			min = current;
		first = first->next;
	}
	return ((int)min);
}
