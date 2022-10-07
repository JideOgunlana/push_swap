/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:17:32 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/07 00:17:01 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	intialize_temp_chunk(t_temp_chunks *temp)
{
	temp->r = 0;
	temp->rr = 0;
	temp->first = 0;
	temp->last = 0;
	temp->total_r = 0;
	temp->total_rr = 0;
}

void	init_chunk_helper(t_chunk_helper *helper, int chunk_size, t_queue *stack_a)
{
	helper->head_a_moves = 0;
	helper->hold_chunk_size = chunk_size;
	helper->head_a = stack_a->front;
}

void	val_in_a(t_queue *stack_a, t_temp_chunks *temp, t_chunk_helper *helper)
{
	temp->last++;
	if (!temp->first)
	{
		temp->r = helper->head_a_moves;
		temp->first = 1;
	}
	if (temp->last == helper->hold_chunk_size)
	{
		temp->rr = stack_a->size - helper->head_a_moves;
	}
	temp->total_r += helper->head_a_moves;
	temp->total_rr += stack_a->size - helper->head_a_moves;
}

void	move_last_chunk_item(t_queue *stack_a, t_stack *stack_b, t_temp_chunks *temp, t_chunk_helper *helper)
{
	if (temp->total_r < temp->total_rr)
	{
		while (temp->r > 0)
		{
			rotate_a(stack_a);
			temp->r--;
		}
	}
	else if (temp->total_r > temp->total_rr)
	{
		while (temp->total_rr > 0)
		{
			rrotate_a(stack_a);
			temp->total_rr--;
		}
	}
	else
	{
		while (temp->total_r > 0)
		{
			rotate_a(stack_a);
			temp->total_r--;
		}
	}
	push_b(stack_a, stack_b);
	helper->hold_chunk_size--;
}

void	move_chunk_item_helper(t_queue *stack_a, t_stack *stack_b, t_temp_chunks *temp, t_chunk_helper *helper)
{
	if (temp->r < temp->rr && temp->rr != 0)
	{
		while (temp->r > 0)
		{
			rotate_a(stack_a);
			temp->r--;
		}
	}
	else if (temp->r > temp->rr && temp->rr != 0)
	{
		while (temp->rr > 0)
		{
			rrotate_a(stack_a);
			temp->rr--;
		}
	}
	else
	{
		while (temp->r > 0)
		{
			rotate_a(stack_a);
			temp->r--;
		}
	}
	push_b(stack_a, stack_b);
	helper->hold_chunk_size--;
}

void	move_chunk_item(t_queue *stack_a, t_stack *stack_b, t_temp_chunks *temp, t_chunk_helper *helper)
{
	if (temp->total_r < temp->total_rr)
	{
		while (temp->r > 0)
		{
			rotate_a(stack_a);
			temp->r--;
		}
		push_b(stack_a, stack_b);
		helper->hold_chunk_size--;
	}
	else if (temp->total_r > temp->total_rr)
	{
		while (temp->rr > 0)
		{
			rrotate_a(stack_a);
			temp->rr--;
		}
		push_b(stack_a, stack_b);
		helper->hold_chunk_size--;
	}
	else
		move_chunk_item_helper(stack_a, stack_b, temp, helper);
}

void	check_move_to_make(t_queue *stack_a, t_stack *stack_b, t_temp_chunks *temp, t_chunk_helper *helper)
{
	if (helper->hold_chunk_size == 1)
		move_last_chunk_item(stack_a, stack_b, temp, helper);
	else
		move_chunk_item(stack_a, stack_b, temp, helper);
}

void	reset_chunk(t_queue *stack_a, t_stack *stack_b, t_temp_chunks *temp, t_chunk_helper *helper)
{
	check_move_to_make(stack_a, stack_b, temp, helper);
	intialize_temp_chunk(temp);
	helper->head_a_moves = -1;
	helper->head_a = stack_a->front;
}

void	check_op_to_b(t_queue *stack_a, t_stack *stack_b, int *temp_chunk, int chunk_size)
{
	t_temp_chunks	*temp;
	t_chunk_helper	*helper;

	temp = (t_temp_chunks *)malloc(sizeof(t_temp_chunks));
	helper = (t_chunk_helper *)malloc(sizeof(t_chunk_helper));
	if (!temp || !helper)
		return ;
	intialize_temp_chunk(temp);
	init_chunk_helper(helper, chunk_size, stack_a);
	while (helper->head_a && helper->hold_chunk_size != 0)
	{
		helper->i = 0;
		while (helper->i < chunk_size)
		{
			if (helper->head_a->item == temp_chunk[helper->i])
				val_in_a(stack_a, temp, helper);
			if (temp->first && temp->last == helper->hold_chunk_size)
			{
				reset_chunk(stack_a, stack_b, temp, helper);
				break ;
			}
			helper->i++;
		}
		if (helper->head_a_moves != -1)
			helper->head_a = helper->head_a->next;
		helper->head_a_moves++;
	}
	free(temp);
	free(helper);
}

// Improve this function to check if rotating or reversing is a better option
void	move_chunks_to_b(t_queue *stack_a, t_stack *stack_b, int chunk_size)
{
	int	*temp_arr = gen_ascending_chunk(stack_a);
	int	*temp_chunk = (int *)malloc(sizeof(int) * chunk_size);
	if (!temp_chunk)
		return ;
	int i = 0;
	while (i < chunk_size)
	{
		temp_chunk[i] = temp_arr[i];
		i++;
	}
	check_op_to_b(stack_a, stack_b, temp_chunk, chunk_size);
	free(temp_arr);
	free(temp_chunk);
	// exit(0);
}
