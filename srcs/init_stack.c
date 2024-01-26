/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:34:55 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/26 13:14:28 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_long_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long		res;

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
	return (sign * res);
}

void	init_stack(t_list **a, char **av)
{
	t_list *new;
	char	**tmp;
	int		i;
	long	n;

	i = 0;
	tmp = ft_split(av[1], ' ');
	while (tmp[i])
	{
		n = ft_long_atoi(tmp[i]);
		ft_printf("Adding node with value: %d\n", n);
		new = ft_lstnew((void *)n);
		ft_lstadd_back(a, new);
		i++;
	}
}
