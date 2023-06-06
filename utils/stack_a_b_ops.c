/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_b_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:43:45 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/11 17:37:52 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Push_swap Operations to:
	Swap / Rotate / Reverse a and b at same time
*/
void	swap_a_b(t_queue *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	if (stack_a->no_print || stack_b->no_print)
		return ;
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}

void	rotate_a_b(t_queue *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	if (stack_a->no_print || stack_b->no_print)
		return ;
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}

void	reverse_a_b(t_queue *stack_a, t_stack *stack_b)
{
	rrotate_a(stack_a);
	rrotate_b(stack_b);
	if (stack_a->no_print || stack_b->no_print)
		return ;
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
