/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:17:32 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/07 17:20:05 by bogunlan         ###   ########.fr       */
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

void	ra(t_queue *stack_a, t_temp_chunks *temp)
{
	while (temp->r > 0)
	{
		rotate_a(stack_a);
		temp->r--;
	}
}

void	rra(t_queue *stack_a, t_temp_chunks *temp)
{
	while (temp->total_rr > 0)
	{
		rrotate_a(stack_a);
		temp->total_rr--;
	}
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
		ra(stack_a, temp);
	else if (temp->total_r > temp->total_rr)
		rra(stack_a, temp);
	else
		ra(stack_a, temp);
	push_b(stack_a, stack_b);
	helper->hold_chunk_size--;
}

void	move_chunk_item_helper(t_queue *stack_a, t_stack *stack_b, t_temp_chunks *temp, t_chunk_helper *helper)
{
	if (temp->r < temp->rr && temp->rr != 0)
		ra(stack_a, temp);
	else if (temp->r > temp->rr && temp->rr != 0)
		rra(stack_a, temp);
	else
		ra(stack_a, temp);
	push_b(stack_a, stack_b);
	helper->hold_chunk_size--;
}

void	move_chunk_item(t_queue *stack_a, t_stack *stack_b, t_temp_chunks *temp, t_chunk_helper *helper)
{
	if (temp->total_r < temp->total_rr)
	{
		ra(stack_a, temp);
		push_b(stack_a, stack_b);
		helper->hold_chunk_size--;
	}
	else if (temp->total_r > temp->total_rr)
	{
		rra(stack_a, temp);
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

void	free_stack_helper(t_temp_chunks *temp, t_chunk_helper *helper)
{
	free(temp);
	free(helper);
}

void	helper_head_moves(t_chunk_helper *helper)
{
	if (helper->head_a_moves != -1)
		helper->head_a = helper->head_a->next;
	helper->head_a_moves++;
}

void	helper_malloc_fail(t_temp_chunks *temp, t_chunk_helper *helper)
{
	if (!temp || !helper)
		exit(EXIT_SUCCESS);
}

void	check_op_to_b(t_queue *stack_a, t_stack *stack_b, int *temp_chunk, int chunk_size)
{
	t_temp_chunks	*temp;
	t_chunk_helper	*helper;

	temp = (t_temp_chunks *)malloc(sizeof(t_temp_chunks));
	helper = (t_chunk_helper *)malloc(sizeof(t_chunk_helper));
	helper_malloc_fail(temp, helper);
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
		helper_head_moves(helper);
	}
	free_stack_helper(temp, helper);
}

// Improve this function to check if rotating or reversing is a better option
void	move_chunks_to_b(t_queue *stack_a, t_stack *stack_b, int chunk_size)
{
	int	*temp_arr;
	int	*temp_chunk;
	int	i;

	i = 0;
	temp_arr = gen_ascending_chunk(stack_a);
	temp_chunk = (int *)malloc(sizeof(int) * chunk_size);
	if (!temp_chunk)
		return ;
	while (i < chunk_size)
	{
		temp_chunk[i] = temp_arr[i];
		i++;
	}
	check_op_to_b(stack_a, stack_b, temp_chunk, chunk_size);
	free(temp_arr);
	free(temp_chunk);
}
