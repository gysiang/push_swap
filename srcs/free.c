/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:47:21 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/31 15:44:06 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tmp_array(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_stack(t_stack *stack)
{
	t_stack *head;
	t_stack *tmp;

	head = stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
