/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyong-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:08:42 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/22 09:58:20 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function will loop through the stack to look for the node
 * with the biggest value and return a pointer to that node.
*/
/**
t_stack	*find_max_node(t_stack *stack)
{
	long	max;
	t_stack	*biggest_node;

	if (stack == NULL)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
} **/

/**
 * This function will loop through the stack to look for the node
 * with the smallest value and return a pointer to that node.
*/
t_stack	*find_min_node(t_stack *stack)
{
	long	min;
	t_stack	*smallest_node;

	if (stack == NULL)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

/**
 * This function will go through the stack to look for
 * a node that sets is_cheapest to true and will return a pointer
 * to that node.
*/
t_stack	*find_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest_node;

	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest == 1)
		{
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

/**
 * This function will convert a string to a integer in long format.
*/
long	ft_long_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((sign * res));
}

/**
 * This function will loop through the stack and return an integer
 * that is the size of the stack.
*/
int	ft_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

char	*join_arguments(char **av, int ac)
{
	char	*tmp;
	char	*s;
	int		i;

	i = 2;
	s = ft_strdup(av[1]);
	while (i < ac)
	{
		tmp = ft_strjoin(s, " ");
		free(s);
		s = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	return (s);
}
