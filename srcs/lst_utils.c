/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:18:01 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/26 15:29:55 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_list **stack)
{
	t_list *head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void printList(t_list *stack)
{
    ft_printf("Printing linked list:\n");
    while (stack != NULL)
	{
        ft_printf("Node value: %d\n", stack->content);
        stack = stack->next;
    }
    ft_printf("End of linked list\n");
}
