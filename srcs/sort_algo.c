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

/**
void	ft_sa(t_list **a)
{
	t_list *tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	ft_printf("sa\n");
} **/

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
	t_list *tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	ft_printf("ra\n");
}

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
}