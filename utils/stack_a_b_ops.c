/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_b_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:43:45 by bogunlan          #+#    #+#             */
/*   Updated: 2022/09/15 18:55:20 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
====================================================================
			Swap / Rotate / Reverse a and b at same time			
====================================================================
*/

void	swap_a_b(t_queue *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

void	rotate_a_b(t_queue *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}

void	reverse_a_b(t_queue *stack_a, t_stack *stack_b)
{
	rrotate_a(stack_a);
	rrotate_b(stack_b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
