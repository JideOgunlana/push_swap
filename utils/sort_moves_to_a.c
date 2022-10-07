/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:39:44 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/07 16:54:27 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_sorted_chunk(t_queue *stack_a, t_stack *stack_b, t_sort_chunk *sort_chunk)
{
	while (sort_chunk->chunk_size > 0)
	{
		push_a(stack_b, stack_a);
		sort_chunk->chunk_size--;
	}
}

void	move_chunk_val_to_a(t_queue *stack_a, t_stack *stack_b, t_sort_chunk *sort_chunk, t_chunks **chunks)
{
	push_a(stack_b, stack_a);
	sort_chunk->push_to_a_state = 1;
	chunks[sort_chunk->total_chunks - 1]->data--;
	sort_chunk->items_at_top_count = chunks[sort_chunk->total_chunks - 1]->data - sort_chunk->rotations;
}

void	found_at_bottom(t_stack *stack_b, t_sort_chunk *sort_chunk)
{
	int	y;

	y = 0;
	if (sort_chunk->rotations)
	{
		rrotate_b(stack_b);
		while (sort_chunk->search_val != stack_b->s_nodes->item)
		{
			rrotate_b(stack_b);
			y++;
		}
		sort_chunk->rotations -= (y + 1);
	}
	sort_chunk->head_b = stack_b->s_nodes;
}

void	serach_val(t_stack *stack_b, t_sort_chunk *sort_chunk)
{
	sort_chunk->temp_items_at_top = sort_chunk->items_at_top_count;
	sort_chunk->search_at_top = 0;
	sort_chunk->temp_head_b = sort_chunk->head_b;
	while (sort_chunk->temp_items_at_top > 0)
	{
		if (sort_chunk->temp_head_b->item == sort_chunk->search_val)
		{
			sort_chunk->search_at_top = 1;
		}
		sort_chunk->temp_head_b = sort_chunk->temp_head_b->next;
		sort_chunk->temp_items_at_top--;
	}
	if (sort_chunk->search_at_top)
	{
		rotate_b(stack_b);
		sort_chunk->rotations++;
		sort_chunk->search_at_top = 0;
	}
	else
		found_at_bottom(stack_b, sort_chunk);
}

int	move_found_item_to_a(t_stack *stack_b, t_queue *stack_a, t_sort_chunk *sort_chunk, t_chunks **chunks)
{
	int	y;

	y = 0;
	sort_chunk->search_val = sort_chunk->descending_arr[sort_chunk->search_index - chunks[sort_chunk->total_chunks - 1]->data];
	if (stack_b->size == 1)
	{
		push_a(stack_b, stack_a);
		sort_chunk->rotations = 0;
		return (1);
	}
	else
	{
		rrotate_b(stack_b);
		while (sort_chunk->search_val != stack_b->s_nodes->item)
		{
			rrotate_b(stack_b);
			y++;
		}
		sort_chunk->rotations -= (y + 1);
	}
	sort_chunk->head_b = stack_b->s_nodes;
	return (0);
}

void	find_val_in_chunk(t_stack *stack_b, t_sort_chunk *sort_chunk)
{
	if (sort_chunk->items_at_top_count > 1)
		serach_val(stack_b, sort_chunk);
	else if (sort_chunk->items_at_top_count == 1 && sort_chunk->rotations > 0)
	{
		rrotate_b(stack_b);
		sort_chunk->items_at_top_count++;
		sort_chunk->rotations--;
	}
}

void	search_and_move(t_stack *stack_b, t_queue *stack_a, t_sort_chunk *sort_chunk, t_chunks **chunks)
{
	while (chunks[sort_chunk->total_chunks - 1]->data > 0)
	{
		sort_chunk->search_val = sort_chunk->descending_arr[sort_chunk->search_index - chunks[sort_chunk->total_chunks - 1]->data];
		sort_chunk->push_to_a_state = 0;
		if (sort_chunk->head_b->item == sort_chunk->search_val)
			move_chunk_val_to_a(stack_a, stack_b, sort_chunk, chunks);
		else if (sort_chunk->head_b->item != sort_chunk->search_val)
			find_val_in_chunk(stack_b, sort_chunk);
		if (!sort_chunk->push_to_a_state)
		{
			sort_chunk->head_b = sort_chunk->head_b->next;
			sort_chunk->head_b_moves++;
		}
		if (sort_chunk->items_at_top_count > 0)
			sort_chunk->head_b = stack_b->s_nodes;
		else if (sort_chunk->items_at_top_count == 0 && chunks[sort_chunk->total_chunks - 1]->data > 0)
		{
			if (move_found_item_to_a(stack_b, stack_a, sort_chunk, chunks))
				break ;
		}
	}
}

void	init_chunks(t_stack *stack_b, t_sort_chunk *sort_chunk, t_chunks **chunks)
{
	sort_chunk->head_b = stack_b->s_nodes;
	sort_chunk->head_b_moves = 0;
	sort_chunk->rotations = 0;
	sort_chunk->descending_arr = gen_descending_chunk(stack_b, chunks[sort_chunk->total_chunks - 1]->data);
	sort_chunk->search_index = chunks[sort_chunk->total_chunks - 1]->data;
	sort_chunk->items_at_top_count = chunks[sort_chunk->total_chunks - 1]->data;
}

void	sort_chunks_in_b(t_stack *stack_b, t_queue *stack_a, t_sort_chunk *sort_chunk, t_chunks **chunks)
{
	while (sort_chunk->total_chunks > 0)
	{
		sort_chunk->median = get_b_limiter(stack_b, chunks[sort_chunk->total_chunks - 1]->data);
		sort_chunk->chunk_size = chunks[sort_chunk->total_chunks - 1]->data;
		if (is_chunk_ordered(stack_b, sort_chunk->chunk_size))
			move_sorted_chunk(stack_a, stack_b, sort_chunk);
		else
		{
			if (stack_b->size <= 2)
				stack_b_has_two(stack_a, stack_b);
			else if (stack_b->size == 3)
				stack_b_has_three(stack_a, stack_b);
			else
			{
				init_chunks(stack_b, sort_chunk, chunks);
				search_and_move(stack_b, stack_a, sort_chunk, chunks);
			}
		}
		sort_chunk->total_chunks--;
		if (sort_chunk->descending_arr)
		{
			free(sort_chunk->descending_arr);
			sort_chunk->descending_arr = NULL;
		}
	}
}

void	move_chunks_to_a(t_stack *stack_b, t_queue *stack_a, t_chunks **chunks, int total_chunks)
{
	t_sort_chunk	*sort_chunk;

	sort_chunk = (t_sort_chunk *) malloc(sizeof(t_sort_chunk));
	if (!sort_chunk)
		return ;
	sort_chunk->total_chunks = total_chunks;
	sort_chunk->descending_arr = NULL;
	if (stack_b->size <= 2)
		stack_b_has_two(stack_a, stack_b);
	if (stack_b->size == 3)
		stack_b_has_three(stack_a, stack_b);
	if (stack_b->size > 3)
	{
		sort_chunks_in_b(stack_b, stack_a, sort_chunk, chunks);
	}
	free(sort_chunk);
}
