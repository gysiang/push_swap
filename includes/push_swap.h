/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:46:49 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/26 15:54:29 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdint.h>
# include "../libraries/libft/libft.h"
# include "../libraries/printf/ft_printf.h"

int	cmp_num(const char *s1, const char *s2);
int	check_duplicates(char **av);
int	is_number(const char *s);
int	check_inputs(const char *s);
int	ft_is_sorted(t_list **stack);
int find_max_value(t_list **a);
int find_min_value(t_list **a);
long	ft_long_atoi(const char *s);
void	init_stack(t_list **a, char **av);
void	free_tmp_array(char **s);
void	free_stack(t_list **stack);
void	ft_sa(t_list **a);
void	ft_ra(t_list **a);
void	ft_rra(t_list **a);
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **a, t_list **b);
void	ft_simple_sort(t_list **a);
void 	printList(t_list *stack);

#endif
