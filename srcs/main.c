/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:46:26 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/26 18:02:45 by gyong-si         ###   ########.fr       */
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
	t_list	*stack_a;
	//t_list	*stack_b;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (!check_inputs(av[1]))
			exit(EXIT_FAILURE);
		ft_printf("Check input passed\n");
		stack_a = NULL;
		//stack_b = malloc(sizeof(t_list));
		//stack_b = NULL;
		init_stack(&stack_a, av);
		//ft_printf("The max value of the list is: %d\n", find_max_value(&stack_a));
		//ft_printf("The min value of the list is: %d\n", find_min_value(&stack_a));
		ft_simple_sort(&stack_a);
		printList(stack_a);
	}
	return (0);
}
