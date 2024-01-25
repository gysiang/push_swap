/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:46:16 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/24 19:01:20 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_sa(t_list **a)
{
	t_list *first;
	t_list *second;
	t_list *tmp;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	tmp = second->next;
	*a = second;
	second->next = first;
	first->next = tmp;
	ft_printf("sa\n");
}

void	ft_ra(t_list **a)
{
	t_list *first;
	t_list *second;
	t_list *last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	last = ft_lstlast(*a);
	*a = second;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}
/**
void	ft_rra(t_list **a)
{
	t_list *tmp;
	int	i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i >1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	ft_printf("rra\n");
} **/

void	ft_rra(t_list **a)
{
	t_list *first;
	t_list *second_last;

	if (!*a || !(*a)->next)
		return;

	first = *a;

	// If the list has only two elements, update the head and return
	if ((*a)->next->next == NULL)
	{
		*a = (*a)->next;
		(*a)->next = first;
		first->next = NULL;
		ft_printf("rra\n");
		return;
	}
	// Traverse the list until the second last element
	second_last = *a;
	while (second_last->next->next != NULL)
		second_last = second_last->next;

	second_last->next->next = first;
	*a = second_last->next;
	second_last->next = NULL;

	ft_printf("rra\n");
}

