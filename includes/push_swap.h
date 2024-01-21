/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:46:49 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/22 03:52:51 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libraries/libft/libft.h"
# include "../libraries/printf/ft_printf.h"

typedef struct s_stack_node
{
	int						nbr;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct	s_stack_node 	*target_node;
	struct	s_stack_node	*next;
	struct	s_stack_node	*prev;
}	t_stack_node;

#endif
