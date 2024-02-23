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

#include "../../includes/push_swap.h"
#include "../../libraries/getnextline/get_next_line.h"

char	*ft_check(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(a);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(a , b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(b);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rr(a, b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == 'a'
			&& line[4] == '\n')
		ft_rra(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == 'b'
			&& line[4] == '\n')
		ft_rrb(b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (get_next_line(STDIN_FILENO));
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

void	ft_checker(t_stack **a, t_stack **b, char *line)
{
	char *tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!ft_is_sorted(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(void)
{
	//t_stack *stack_a;
	//t_stack	*stack_b;
	int		i = 0;
	char	*line;

	//stack_a = ft_check_args(ac, av);
	//stack_b = NULL;
	line = NULL;
	//push_swap(&stack_a, &stack_b);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			return (0);
		ft_printf("LINE %d: %s",i++, line);
	}
	/**
	if (!line && !ft_is_sorted(&stack_a))
		ft_putstr_fd("KO\n", 1);
	else if (!line && ft_is_sorted(&stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_checker(&stack_a, &stack_b, line);
	free_stack(stack_a); **/
	return (0);
}
