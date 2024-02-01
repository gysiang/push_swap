/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:46:49 by gyong-si          #+#    #+#             */
/*   Updated: 2024/02/01 12:52:49 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdint.h>
# include "../libraries/libft/libft.h"
# include "../libraries/printf/ft_printf.h"

typedef struct s_stack
{
	int	value;
	int rot_cost;
	int index;
	bool above_median;
	bool is_cheapest;
	struct s_stack *target_node;
	struct s_stack *next;
}	t_stack;

int	cmp_num(const char *s1, const char *s2);
int	check_duplicates(char **av);
int	is_number(const char *s);
int	check_inputs(const char *s);
int	ft_is_sorted(t_stack **stack);
int	ft_stacksize(t_stack *lst);
long	ft_long_atoi(const char *s);
void	initalise_stack_a(t_stack **a, char **av);
void	free_tmp_array(char **s);
void	free_stack(t_stack *stack);
void	ft_sa(t_stack **a);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_simple_sort(t_stack **a);
void	print_list(t_stack *stack);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	push_swap(t_stack **a, t_stack **b);
void	set_index(t_stack *stack);
void	set_rotcost(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	initiate_stacks(t_stack **a, t_stack **b);
void	shift_smallest_to_top(t_stack **a);
void	rotate_target_to_top_of_a(t_stack **stack_a, t_stack *target);
void	rotate_target_to_top_of_b(t_stack **stack_b, t_stack *target);
t_stack	*ft_stacknew(long content);
t_stack	*ft_stacklast(t_stack *lst);
t_stack *find_max_node(t_stack *stack);
t_stack *find_min_node(t_stack *stack);
t_stack *find_cheapest_node(t_stack *stack);

#endif
