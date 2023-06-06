/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:06:13 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/11 17:27:04 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Move to stack A when B contains just 2 items
	order the numbers in descending order before moving if 
	they are not ordered
*/
void	stack_b_has_two(t_queue *stack_a, t_stack *stack_b)
{
	int	k;

	k = 0;
	if (is_chunk_b_ordered(stack_b, 2))
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

/* 
	helper function used by stack_b_has_three,
	check if limiter is at the top of stack B to sort it
 */
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

/* 
	Helper function used by stack_b_has_three
	check if the smallest val is at the top of stack B to sort it
*/
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

/* 
	Helper function used by stack_b_has_three
	check if the largest val is at the top of stack to sort it
*/
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

/* 
	Sort the three remaining items in stack B and move to A
*/
void	stack_b_has_three(t_queue *stack_a, t_stack *stack_b)
{
	int	median;
	int	k;

	k = 0;
	median = get_b_limiter(stack_b, 3);
	if (!is_chunk_b_ordered(stack_b, 3))
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
