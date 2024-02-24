/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:39:54 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/22 23:38:11 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include "../../libraries/getnextline/get_next_line.h"

void	ft_check_commands(t_stack **a, t_stack **b, char *line, int *error)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap(a);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push(b, a);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push(a, b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'
			&& line[3] == '\n')
		rrr_both(a, b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a'
			&& line[3] == '\n')
		reverse_rotate(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'
			&& line[3] == '\n')
		reverse_rotate(b);
	else
		*error = 1;
}

t_stack *ft_check_args(int ac, char **av)
{
	char	*s;
	t_stack *stack_a;

	if (ac >= 2)
	{
		s = join_arguments(av, ac);
		if (!check_inputs(s))
		{
			ft_putstr_fd("\033[1;31mError\033[0m\n", 2);
			free(s);
			exit(EXIT_FAILURE);
		}
		stack_a = NULL;
		initalise_stack_a(&stack_a, s);
		free(s);
		return (stack_a);
	}
	return (0);
}

void	ft_final_checker(t_stack **a, t_stack **b)
{
	if (*b)
		ft_printf("\033[1;31mKO\031[0m\n");
	else if (!ft_is_sorted(a))
		ft_printf("\033[1;31mKO\031[0m\n");
	else
		ft_printf("\033[1;32mOK\033[0m\n");
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	char	*line;
	int		error;

	stack_a = ft_check_args(ac, av);
	stack_b = NULL;
	error = 0;
	line = get_next_line(STDIN_FILENO);
	if (ft_strncmp(line, "Error", 5) == 0)
		return (1);
	while (line != NULL)
	{
		if (ft_strncmp(line, "Error", 5) == 0)
		{
			free_stack(stack_a);
			return (1);
		}
		ft_check_commands(&stack_a, &stack_b, line, &error);
		if (error)
		{
			ft_putstr_fd("\033[1;31mError\033[0m\n", 2);
			free_stack(stack_a);
			return (1);
		}
		line =  get_next_line(STDIN_FILENO);
	}
	//print_list(stack_a);
	//print_list(stack_b);
	ft_final_checker(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}
