/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:46:26 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/31 17:37:53 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
1. Check if all the params are valid
	1. ac = 2, because the args are "num1, num2, num 3, ..."
	2. check all the nums are numbers and not random chars like "asdf"
	3. check if all the nums are not duplicates
**/

int	main(int ac, char **av)
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;

	if (ac == 2)
	{
		if (!check_inputs(av[1]))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		init_stack(&stack_a, av);
		push_swap(&stack_a, &stack_b);
		//ft_printf("stack_a\n");
		printList(stack_a);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}
