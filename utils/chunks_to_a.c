/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:57:21 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/09 01:53:29 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mov_chunk_mid_to_a(t_stack *stack_b, t_queue *stack_a, int median)
{
	int	k;

	k = 0;
	if (stack_b->s_nodes->next->item > median)
	{
		swap_b(stack_b);
		push_a(stack_b, stack_a);
	}
	else
	{
		rotate_b(stack_b);
		swap_b(stack_b);
		push_a(stack_b, stack_a);
		rrotate_b(stack_b);
	}
	while (k < 2)
	{
		push_a(stack_b, stack_a);
		k++;
	}
}

void	mov_chunk_sm_a(t_stack *stack_b, t_queue *stack_a, int median)
{
	int	k;

	k = 0;
	rotate_b(stack_b);
	if (stack_b->s_nodes->item == median)
		swap_b(stack_b);
	while (k < 2)
	{
		push_a(stack_b, stack_a);
		k++;
	}
	rrotate_b(stack_b);
	push_a(stack_b, stack_a);
}

void	mov_chunk_big_to_a(t_stack *stack_b, t_queue *stack_a)
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

void	stack_b_has_three_chunks(t_queue *stack_a, t_stack *stack_b)
{
	int	median;
	int	k;

	k = 0;
	median = get_b_limiter(stack_b, 3);
	if (!is_chunk_ordered(stack_b, 3))
	{
		if (stack_b->s_nodes->item == median)
			mov_chunk_mid_to_a(stack_b, stack_a, median);
		else if (stack_b->s_nodes->item < median)
			mov_chunk_sm_a(stack_b, stack_a, median);
		else
			mov_chunk_big_to_a(stack_b, stack_a);
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
