/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:06:13 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/09 01:53:22 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Algorithm to sort Array of numbers 9
*/

void	stack_b_has_two(t_queue *stack_a, t_stack *stack_b)
{
	int	k;

	k = 0;
	if (is_chunk_ordered(stack_b, 2))
	{
		while (k < 2)
		{
			push_a(stack_b, stack_a);
			k++;
		}
	}
	else
	{
		swap_b(stack_b);
		while (k < 2)
		{
			push_a(stack_b, stack_a);
			k++;
		}
	}
}

void	mov_med_to_a(t_stack *stack_b, t_queue *stack_a, int median)
{
	int	k;

	k = 0;
	if (stack_b->s_nodes->next->item > median)
		swap_b(stack_b);
	else
		rrotate_b(stack_b);
	while (k < 3)
	{
		push_a(stack_b, stack_a);
		k++;
	}
}

void	mov_sm_a(t_stack *stack_b, t_queue *stack_a, int median)
{
	int	k;

	k = 0;
	rotate_b(stack_b);
	if (stack_b->s_nodes->item == median)
		swap_b(stack_b);
	while (k < 3)
	{
		push_a(stack_b, stack_a);
		k++;
	}
}

void	mov_big_to_a(t_stack *stack_b, t_queue *stack_a)
{
	int	k;

	k = 0;
	push_a(stack_b, stack_a);
	swap_b(stack_b);
	while (k < 2)
	{
		push_a(stack_b, stack_a);
		k++;
	}
}

void	stack_b_has_three(t_queue *stack_a, t_stack *stack_b)
{
	int	median;
	int	k;

	k = 0;
	median = get_b_limiter(stack_b, 3);
	if (!is_chunk_ordered(stack_b, 3))
	{
		if (stack_b->s_nodes->item == median)
			mov_med_to_a(stack_b, stack_a, median);
		else if (stack_b->s_nodes->item < median)
			mov_sm_a(stack_b, stack_a, median);
		else
			mov_big_to_a(stack_b, stack_a);
	}
	else
	{
		while (k < 3)
		{
			push_a(stack_b, stack_a);
			k++;
		}
	}
}
