/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:57:21 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/06 15:49:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
 *	Move the delimiter val to chunk A after all values greater than it have been moved
 */
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

/* 
 *	Move all values lower than the delimiter to stack A for chunks in stack B after all the large values and the delimiting value have been moved
 */
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

/* 
 *	Move values larger than the delimiting value to stack A
 */
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

/* 
 *	Move the three items left in stack B to A
 */
void	stack_b_has_three_chunks(t_queue *stack_a, t_stack *stack_b)
{
	int	median;
	int	k;

	k = 0;
	median = get_b_limiter(stack_b, 3);
	if (!is_chunk_b_ordered(stack_b, 3))
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
