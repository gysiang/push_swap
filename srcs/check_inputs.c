/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:11:58 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/01 11:08:49 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function will compare if two strings are the same. Returns 0 if true.
*/
int	cmp_num(const char *s1, const char *s2)
{
	if (*s1 == '+')
	{
		if (*s2 != '+')
			s1++;
	}
	else
	{
		if (*s2 == '+')
			s2++;
	}
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/**
 * This function loops through the stack and check if there are any duplicates
 * in the params input by the user. If there are no duplicates it will return 1.
*/
int	check_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && cmp_num(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * This function checks if the character is a number. If true it will return 1.
*/
int	is_number(const char *s)
{
	if (*s == '\0')
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * This function will check each of the input to make sure all of them are
 * numbers and there are no duplicate numbers. If the input is okay,
 * it will return 1.
*/
int	check_inputs(const char *s)
{
	int		i;
	char	**tmp;
	char	**tmp1;

	i = 0;
	tmp = ft_split(s, ' ');
	tmp1 = tmp;
	while (tmp[i] != NULL)
	{
		if (!is_number(tmp[i]))
		{
			free_tmp_array(tmp1);
			return (0);
		}
		i++;
	}
	if (!check_duplicates(tmp1))
	{
		free_tmp_array(tmp1);
		return (0);
	}
	free_tmp_array(tmp1);
	return (1);
}
