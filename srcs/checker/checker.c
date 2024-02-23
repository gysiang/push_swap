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

void	ft_check_commands(t_stack **a, t_stack **b, char *line)
{
	//ft_printf("in check cmd %s\n", line);
	//ft_printf("first char %c\n", line[0]);
	//ft_printf("sec char %c\n", line[1]);
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
	{
		//ft_printf("line :", line);
		//ft_printf("in check cmds\n");
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	//return (get_next_line(0));
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
			ft_printf("check args %s\n", s);
			ft_putstr_fd("Error\n", 2);
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
		write(1, "KO\n", 3);
	else if (!ft_is_sorted(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	//int		i = 0;
	char	*line;

	stack_a = ft_check_args(ac, av);
	stack_b = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		ft_check_commands(&stack_a, &stack_b, line);
		line =  get_next_line(STDIN_FILENO);
	}
	//print_list(stack_a);
	//print_list(stack_b);
	ft_final_checker(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}
