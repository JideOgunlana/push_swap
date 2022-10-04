/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:06:13 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/03 20:29:38 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Algorithm to sort Array of numbers
*/

void	stack_b_has_two(t_queue *stack_a, t_stack *stack_b)
{
	int	k;

	k = 0;
	if (is_chunk_ordered(stack_b, 2))
	{
		// // printf("Chunk is ordered\n");
		while (k < 2)
		{
			// // printf("Total elements in 1 chunk %d\n", 2);
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
		// // printf("Size of stack B is: %d\n", stack_b->size);
	}
}

void	stack_b_has_three(t_queue *stack_a, t_stack *stack_b)
{
	int	median;
	int	k;

	k = 0;
	median = insertion_sort_on_b(stack_b, 3);
	if (!is_chunk_ordered(stack_b, 3))
	{
		if (stack_b->s_nodes->item == median)
		{
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
		else if (stack_b->s_nodes->item < median)
		{
			rotate_b(stack_b);
			if (stack_b->s_nodes->item == median)
				swap_b(stack_b);
			while (k < 3)
			{
				push_a(stack_b, stack_a);
				k++;
			}
		}
		else
		{
			push_a(stack_b, stack_a);
			swap_b(stack_b);
			while (k < 2)
			{
				push_a(stack_b, stack_a);
				k++;
			}
		}
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

void	stack_b_has_three_chunks(t_queue *stack_a, t_stack *stack_b)
{
	int	median;
	int	k;

	k = 0;
	median = insertion_sort_on_b(stack_b, 3);
	if (!is_chunk_ordered(stack_b, 3))
	{
		if (stack_b->s_nodes->item == median)
		{
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
		else if (stack_b->s_nodes->item < median)
		{
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
		else
		{
			push_a(stack_b, stack_a);
			swap_b(stack_b);
			while (k < 2)
			{
				push_a(stack_b, stack_a);
				k++;
			}
		}
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