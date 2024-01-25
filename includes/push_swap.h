/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:46:49 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/24 18:10:47 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libraries/libft/libft.h"
# include "../libraries/printf/ft_printf.h"

int	cmp_num(const char *s1, const char *s2);
int	check_duplicates(char **av);
int	is_number(const char *s);
int	check_inputs(const char *s);
int is_sorted(t_list **stack);
long	ft_long_atoi(const char *s);
void	init_stack(t_list **a, char **av);
void	free_tmp_array(char **s);
void	free_stack(t_list **stack);
void	ft_sa(t_list **a);
void	ft_ra(t_list **a);
void	ft_rra(t_list **a);

#endif
