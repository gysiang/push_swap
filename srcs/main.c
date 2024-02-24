/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:46:26 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/24 12:09:09 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function will initalise the push swap algorithm by pushing
 * elements from a to b until there are 3 elements left in b. It will
 * then start to move the nodes from stack b to stack a in order until
 * there are no elements left in stack b.
*/
void	push_swap(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_stacksize(*a);
	if (ft_is_sorted(a))
		return ;
	else if (len_a <= 3)
		sort_three(a);
	else if (len_a == 5)
		sort_five(a, b);
	else
		turk_sort(a, b);
}

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
		free_stack(stack_a);
		free(s);
	}
	return (0);
}
