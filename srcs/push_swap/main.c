/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:46:26 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/23 17:45:57 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
	1. Check if all the params are valid.
	2. ac = 2, because the args are "num1, num2, num 3, ...".
	3. check all the nums are numbers and not random chars like "asdf".
	4. check if all the nums are not duplicates.
	5. initalise the push swap algorithm.
	6. free the memory in the stacks.
	//print_list(stack_a);
**/

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*s;

	if (ac >= 2)
	{
		s = join_arguments(av, ac);
		if (!check_inputs(s))
		{
			ft_putstr_fd("Error\n", 2);
			free(s);
			exit(EXIT_FAILURE);
		}
		stack_a = NULL;
		stack_b = NULL;
		initalise_stack_a(&stack_a, s);
		push_swap(&stack_a, &stack_b);
		//print_list(stack_a);
		free_stack(stack_a);
		free(s);
	}
	return (0);
}
