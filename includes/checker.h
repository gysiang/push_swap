/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:13:28 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/23 17:19:28 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "../libraries/libft/libft.h"
# include "../libraries/printf/ft_printf.h"

void	rotate_target_to_top_of_a_checker(t_stack **stack_a, t_stack *target);
void	rotate_target_to_top_of_b_checker(t_stack **stack_b, t_stack *target);
void	rotate_both_stacks_checker(t_stack **stack_a, t_stack **stack_b,
		t_stack *target);
void	reverse_rotate_both_stacks_checker(t_stack **stack_a,
		t_stack **stack_b, t_stack *target);
void	move_node_stackb_checker(t_stack **a, t_stack **b);
void	sort_three_checker(t_stack **a);
void	sort_five_checker(t_stack **a, t_stack **b);
void	turk_sort_checker(t_stack **a, t_stack **b);
void	push_swap_checker(t_stack **a, t_stack **b);


#endif
