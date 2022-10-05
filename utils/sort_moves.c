/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:17:32 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/05 03:35:30 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_op_to_b(t_queue *stack_a, t_stack *stack_b, int *temp_chunk, int chunk_size)
{
	t_temp_chunks	*temp;
	t_queue_node	*head_a;
	int				head_a_moves;

	head_a = stack_a->front;
	head_a_moves = 0;
	int found_first = 0;
	int found_last = 0;
	int r = 0;
	int	rr = 0;
	int i;
	int hold_chunk_size;

	hold_chunk_size = chunk_size;

	temp = (t_temp_chunks *)malloc (sizeof(t_temp_chunks));
	temp->r = 0;
	temp->rr = 0;
	if (!temp)
		return ;
	while (head_a && hold_chunk_size != 0)
	{
		i = 0;
		while (i < chunk_size)
		{
			// printf("temp %d A: %d\n", temp_chunk[i], head_a->item);
			if (head_a->item == temp_chunk[i])
			{
				found_last++;
				if (!found_first)
				{
					temp->r = head_a_moves;
					found_first = 1;
				}
				if (found_last == hold_chunk_size)
				{
					// printf("Stack size: %d\n", stack_a->size);
					// printf("head a move: %d\n", head_a_moves);
					temp->rr = stack_a->size - head_a_moves;
					// printf("\n***found last***: %d\n", found_last);
					// printf("hold chunk size: %d\n", hold_chunk_size);

				}
				r += head_a_moves;
				rr += stack_a->size - head_a_moves;
			}
			if (found_first && found_last == hold_chunk_size)
			{
				// printf("total r moves: %d\n", r);
				// printf("total rr moves: %d\n", rr);
				// printf("r moves: %d\n", temp->r);
				// printf("rr moves: %d\n", temp->rr);
				// display(stack_a);
				if (hold_chunk_size == 1)
				{
					if (r < rr)
					{
						// printf("*Use rotation*");
						while (temp->r > 0)
						{
							rotate_a(stack_a);
							temp->r--;
						}
						push_b(stack_a, stack_b);
					}
					else if (r > rr)
					{
						// printf("*Use reverse rotation*");
						while (rr > 0)
						{
							rrotate_a(stack_a);
							rr--;
						}
						push_b(stack_a, stack_b);
					}
					else
					{
						while (r > 0)
						{
							rotate_a(stack_a);
							r--;
						}
						push_b(stack_a, stack_b);
					}
					hold_chunk_size--;
				}
				else
				{
					if (r < rr)
					{
						// printf("Use rotation");
						while (temp->r > 0)
						{
							rotate_a(stack_a);
							temp->r--;
						}
						push_b(stack_a, stack_b);
						hold_chunk_size--;
					}
					else if (r > rr)
					{
						// printf("Use reverse rotation");
						while (temp->rr > 0)
						{
							rrotate_a(stack_a);
							temp->rr--;
						}
						push_b(stack_a, stack_b);
						hold_chunk_size--;
					}
					else
					{
						// printf("Check the top and bottom values for least move\n");
						if (temp->r < temp->rr && temp->rr != 0)
						{
							// printf("Use rotation\n");
							while (temp->r > 0)
							{
								rotate_a(stack_a);
								temp->r--;
							}
							push_b(stack_a, stack_b);
						}
						else if (temp->r > temp->rr && temp->rr != 0)
						{
							// printf("Use reverse rotation\n");
							while (temp->rr > 0)
							{
								rrotate_a(stack_a);
								temp->rr--;
							}
							push_b(stack_a, stack_b);
						}
						else
						{
							// printf("r and rr are same\n");
							while (temp->r > 0)
							{
								rotate_a(stack_a);
								temp->r--;
							}
							push_b(stack_a, stack_b);
						}
						hold_chunk_size--;
					}
				}
				found_first = 0;
				found_last = 0;
				r = 0;
				rr =  0;
				// print_stack(stack_b);
				// printf("chunk size: %d\n", hold_chunk_size);
				head_a_moves = -1;
				temp->r = 0;
				temp->rr = 0;
				head_a = stack_a->front;
				break ;
			}
			i++;
		}
		if (head_a_moves != -1)
			head_a = head_a->next;
		head_a_moves++;
	}

}

// Improve this function to check if rotating or reversing is a better option
void	move_chunks_to_b(t_queue *stack_a, t_stack *stack_b, int chunk_size)
{
	// int				median;
	t_queue_node	*head_a;
	int				head_a_moves;

	// median = insertion_sort(stack_a);
	head_a = stack_a->front;
	head_a_moves = 0;


	int	*temp_arr = gen_ascending_chunk(stack_a);
	int	*temp_chunk = (int *)malloc(sizeof(int) * chunk_size);
	if (!temp_chunk)
		return ;
	int i = 0;
	while (i < chunk_size)
	{
		temp_chunk[i] = temp_arr[i];
		// printf("temp: %d\n", temp_chunk[i]);
		// printf("chunk size: %d\n", chunk_size);
		i++;
	}
	check_op_to_b(stack_a, stack_b, temp_chunk, chunk_size);
	// exit(0);


/* 	while (head_a)
	{
		if (head_a->item < median)
		{
			if (head_a_moves < (stack_a->size / 2))
			{
				while (head_a_moves > 0)
				{
					rotate_a(stack_a);
					head_a_moves--;
				}
			}
			else
			{
				head_a_moves = stack_a->size - head_a_moves;
				while (head_a_moves > 0)
				{
					rrotate_a(stack_a);
					head_a_moves--;
				}
			}
			push_b(stack_a, stack_b);
			head_a = stack_a->front;
			head_a_moves = -1;
		}
		if (head_a_moves != -1)
			head_a = head_a->next;
		head_a_moves++;
	} */
}

void	move_chunks_to_a(t_stack *stack_b, t_queue *stack_a, t_chunks **chunks, int total_chunks)
{
	int	median;
	int *descending_arr;
	descending_arr = NULL;
	// print_stack(stack_b);
	if (stack_b->size <= 2)
	{
		// // printf("\nSorting stack B having only 2 or less items\n");
		stack_b_has_two(stack_a, stack_b);
	}
	if (stack_b->size == 3)
	{
		// // printf("\nSort ing stack B having only 3 items\n");
		stack_b_has_three(stack_a, stack_b);
	}
	if (stack_b->size > 3)
	{
		// // printf("\nSorting stack B having chunks\n");
		// // printf("Total chunks: %d\n", total_chunks);
		while (total_chunks > 0)
		{
			median = insertion_sort_on_b(stack_b, chunks[total_chunks - 1]->data);
			int chunk_size = chunks[total_chunks - 1]->data;
			// // printf("chunk size: %d\n", chunk_size);
			if (is_chunk_ordered(stack_b, chunk_size))
			{
				while (chunk_size > 0)
				{
					push_a(stack_b, stack_a);
					chunk_size--;
				}
			}
			else
			{
				// // printf("Chunk size is: %d\n\n", chunk_size);
				if (stack_b->size <= 2)
				{
					stack_b_has_two(stack_a, stack_b);
				}
				else if (stack_b->size == 3)
				{
					stack_b_has_three(stack_a, stack_b);
				}
				else
				{
					// // printf("Chunk size is large\n");
					t_stack_node	*head_b;
					int				rotations;
					int				head_b_moves;
					int				push_to_a_state;
					int				pushed_items_count;
					int				encountered_big_val;
					int				chunk_mid_val;
					int				items_at_top_count;

					head_b = stack_b->s_nodes;
					pushed_items_count = 0;
					head_b_moves = 0;
					rotations = 0;
					encountered_big_val = 0;
					chunk_mid_val = chunks[total_chunks - 1]->data / 2;
					
					descending_arr = gen_descending_chunk(stack_b, chunks[total_chunks - 1]->data);
					int search_index = chunks[total_chunks - 1]->data;
					items_at_top_count = chunks[total_chunks - 1]->data;
					while (chunks[total_chunks - 1]->data > 0)
					{
						int search_val = descending_arr[search_index - chunks[total_chunks - 1]->data];
						// // printf("x: %d\n", search_val);
						push_to_a_state = 0;
						// // printf("Head b item is: %d\n", head_b->item);
						if (head_b->item == search_val)
						{
							push_a(stack_b, stack_a);
							push_to_a_state = 1;
							chunks[total_chunks - 1]->data--;
							items_at_top_count = chunks[total_chunks - 1]->data - rotations;
							// // printf("Number of items at top: %d\n", items_at_top_count);
							// // printf("Rotations: %d\n", rotations);
							// // printf("Chunk size: %d\n", chunks[total_chunks - 1]->data);
						}
						else if (head_b->item != search_val)
						{
							if (items_at_top_count > 1)
							{
								int temp_items_at_top = items_at_top_count;
								int	search_at_top = 0;
								t_stack_node *temp_head_b = head_b;
								while (temp_items_at_top > 0)
								{
									if (temp_head_b->item == search_val)
									{
										search_at_top = 1;
									}
									temp_head_b = temp_head_b->next;
									temp_items_at_top--;
								}
								if (search_at_top)
								{
									rotate_b(stack_b);
									rotations++;
									search_at_top = 0;
								}
								else
								{
									int y = 0;
									if (rotations)
									{
										rrotate_b(stack_b);
										while (search_val != stack_b->s_nodes->item)
										{
											rrotate_b(stack_b);
											y++;
										}
										rotations -= (y + 1);
									}
									head_b = stack_b->s_nodes;
								}
							}
							else if (items_at_top_count == 1 && rotations > 0)
							{
								rrotate_b(stack_b);
								items_at_top_count++;
								rotations--;
							}
						}
						if (!push_to_a_state)
						{
							head_b = head_b->next;
							head_b_moves++;
						}
						if (items_at_top_count > 0)
						{
							head_b = stack_b->s_nodes;
						}
						else if (items_at_top_count == 0 && chunks[total_chunks - 1]->data > 0)
						{
							int	y;

							y = 0;
							search_val = descending_arr[search_index - chunks[total_chunks - 1]->data];
							if (stack_b->size == 1)
							{
								push_a(stack_b, stack_a);
								rotations = 0;
								break ;
							}
							else
							{
								rrotate_b(stack_b);
								while (search_val != stack_b->s_nodes->item)
								{
									rrotate_b(stack_b);
									y++;
								}
								rotations -= (y + 1);
							}
							head_b = stack_b->s_nodes;
						}
					}
				}
			}
			total_chunks--;
			if (descending_arr)
			{
				free(descending_arr);
				descending_arr = NULL;
			}
		}
		
		
	}
}
