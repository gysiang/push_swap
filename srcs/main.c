/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:46:26 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/24 18:37:20 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
1. Check if all the params are valid
	1. ac = 2, because the args are "num1, num2, num 3, ..."
	2. check all the nums are numbers and not random chars like "asdf"
	3. check if all the nums are not duplicates
**/

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

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (!check_inputs(av[1]))
			exit(EXIT_FAILURE);
		ft_printf("Check input passed\n");
		stack_a = NULL;
		init_stack(&stack_a, av);
		ft_sa(&stack_a);
		printList(stack_a);
	}
	return (0);
}