/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:58:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/07 05:30:51 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_split_arg(t_stacks *stacks)
{
	int	j;

	j = 0;
	while (stacks->split[j] != NULL)
	{
		if (check_invalid_vals(stacks->split[j]))
		{
			error_message();
			ft_free(stacks->split);
			// system("leaks push_swap");
			exit(0);
		}
		j++;
	}
}

void	check_arg(t_stacks *stacks,char *argv[])
{
	if (stacks->split)
	{
		check_split_arg(stacks);
	}
	else if(check_invalid_vals(argv[stacks->i]))
	{
		error_message();
		free(stacks->stack_a);
		// system("leaks push_swap");
		exit(0);
	}
}

void	enqueue_stack_a(t_stacks *stacks)
{
	int	j;

	j = 0;
	if (stacks->split)
	{
		while (stacks->split[j] != NULL)
		{
			stacks->ret_val = ft_atoi(stacks->split[j]);
			if (stacks->ret_val < INT32_MIN || stacks->ret_val > INT32_MAX)
			{
				error_message();
				exit(0);
			}
			enqueue(stacks->stack_a, stacks->ret_val);
			j++;
		}
		stacks->split = ft_free(stacks->split);
	}
	else
	{
		stacks->ret_val = ft_atoi(stacks->split[j]);
		if (stacks->ret_val < INT32_MIN || stacks->ret_val > INT32_MAX)
		{
			error_message();
			exit(0);
		}
		enqueue(stacks->stack_a, stacks->ret_val);
	}
}

void	parse_args(t_stacks *stacks, int argc, char *argv[])
{
	stacks->i = 1;
	while (stacks->i < argc)
	{
		if (ft_strlen(argv[stacks->i]) > 0)
		{
			stacks->split = ft_split(argv[stacks->i], ' ');
		}
		check_arg(stacks, argv);
		enqueue_stack_a(stacks);
		stacks->i++;
	}
	// scan the created stack A for any duplicate values
	if (check_duplicates(stacks->stack_a))
	{
		error_message();
		// if (stacks->split)
		// 	ft_free(stacks->split);
		// system("leaks push_swap"); // no need to free because I am not reusing the memory after exiting
		exit(EXIT_SUCCESS);
	}
}

int	init_stacks(t_stacks *stacks)
{
	stacks->stack_a = (t_queue *) malloc(sizeof(t_queue));
	stacks->stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stacks->stack_a || !stacks->stack_b)
		return (0);
	inint_stack_a(stacks->stack_a);
	init_stack_b(stacks->stack_b);
	stacks->split = NULL;
	return (1);
}

void	sort_chunk_in_a(t_stacks *stacks, t_pswap *pswap)
{
	if (!is_ordered(stacks->stack_a))
	{
		pswap->median = insertion_sort(stacks->stack_a);
		if (stacks->stack_a->size < 3)
		{
			if (stacks->stack_a->front->item == pswap->median)
			{
				swap_a(stacks->stack_a);
			}
		}
		else
		{
			if (stacks->stack_a->front->item == pswap->median)
			{
				if (stacks->stack_a->front->next->item < pswap->median)
				{
					swap_a(stacks->stack_a);
				}
				else
				{
					rrotate_a(stacks->stack_a);
				}
			}
			else if (stacks->stack_a->front->item > pswap->median)
			{
				rotate_a(stacks->stack_a);
				if (stacks->stack_a->front->item == pswap->median)
				{
					swap_a(stacks->stack_a);
				}
			}
			else
			{
				swap_a(stacks->stack_a);
				rotate_a(stacks->stack_a);
			}
		}
	}
}

void	get_total_chunks(t_stacks *stacks, t_pswap *pswap)
{
	pswap->temp_stack_a_size = stacks->stack_a->size;
	pswap->total_chunks = 0;
	while (pswap->temp_stack_a_size > 3)
	{
		pswap->temp_stack_a_size = pswap->temp_stack_a_size - (pswap->temp_stack_a_size / 2);
		pswap->total_chunks++;
	}
}

void	get_total_chunks_l(t_stacks *stacks, t_pswap *pswap)
{
	pswap->temp_stack_a_size = stacks->stack_a->size;
	pswap->total_chunks = 1;
	while (pswap->temp_stack_a_size > 3)
	{
		if (stacks->stack_a->size > 40)
		{
			pswap->temp_stack_a_size -= LIMIT_100;
		}
		else
		{
			pswap->temp_stack_a_size = pswap->temp_stack_a_size - (pswap->temp_stack_a_size / 2);
		}
		pswap->total_chunks++;
	}
}

void	get_total_chunks_xl(t_stacks *stacks, t_pswap *pswap)
{
	pswap->temp_stack_a_size = stacks->stack_a->size;
	pswap->total_chunks = 0;
	while (pswap->temp_stack_a_size > 3)
	{
		if (stacks->stack_a->size > 40)
		{
			pswap->temp_stack_a_size -= LIMIT_500;
		}
		else
		{
			pswap->temp_stack_a_size = pswap->temp_stack_a_size - (pswap->temp_stack_a_size / 2);
		}
		pswap->total_chunks++;
	}
}

void	init_temp_stack(t_pswap *pswap)
{
	pswap->set = (t_chunks *)malloc(sizeof(t_chunks));
	pswap->chunks = (t_chunks **)malloc(sizeof(pswap->set) * pswap->total_chunks);
	if (!pswap->chunks || !pswap->set)
		exit(0);
}

void	is_sort_needed_xl(t_stacks *stacks, t_pswap *pswap)
{
	if (is_ordered(stacks->stack_a))
	{
		// system("leaks push_swap");
		exit(EXIT_SUCCESS);
	}
	else
	{
		// Moving chunks to B
		pswap->set_count = 0;
		while (stacks->stack_a->size > 3)
		{
			pswap->chunks[pswap->set_count] = get_chunk_set_xl(stacks->stack_a, pswap->set_count);
			move_chunks_to_b(stacks->stack_a, stacks->stack_b, pswap->chunks[pswap->set_count]->data);
			pswap->set_count++;
		}

		// Ordering the 3 or 2 remaing items stack A 
		sort_chunk_in_a(stacks, pswap);
		// using the sort algo to sort pswap->chunks sent to B back to A
		while (stacks->stack_b->size > 0)
			move_chunks_to_a(stacks->stack_b, stacks->stack_a, pswap->chunks, pswap->total_chunks);
	}
}

void	is_sort_needed_l(t_stacks *stacks, t_pswap *pswap)
{
	if (is_ordered(stacks->stack_a))
	{
		// system("leaks push_swap");
		exit(EXIT_SUCCESS);
	}
	else
	{
		// Moving chunks to B

		pswap->set_count = 0;
		while (stacks->stack_a->size > 3)
		{
			pswap->chunks[pswap->set_count] = get_chunk_set_l(stacks->stack_a, pswap->set_count);
			move_chunks_to_b(stacks->stack_a, stacks->stack_b, pswap->chunks[pswap->set_count]->data);
			pswap->set_count++;
		}

		// Ordering the 3 or 2 remaing items stack A 
		sort_chunk_in_a(stacks, pswap);
		// using the sort algo to sort pswap->chunks sent to B back to A
		while (stacks->stack_b->size > 0)
			move_chunks_to_a(stacks->stack_b, stacks->stack_a, pswap->chunks, pswap->total_chunks);
	}
}

void	is_sort_needed(t_stacks *stacks, t_pswap *pswap)
{
	
	if (is_ordered(stacks->stack_a))
	{
		// system("leaks push_swap");
		exit(EXIT_SUCCESS);
	}
	// Moving chunks to B
	pswap->set_count = 0;
	while (stacks->stack_a->size > 3)
	{
		pswap->chunks[pswap->set_count] = get_chunk_set(stacks->stack_a, pswap->set_count);
		move_chunks_to_b(stacks->stack_a, stacks->stack_b, pswap->chunks[pswap->set_count]->data);
		// free(pswap->chunks[pswap->set_count]);
		pswap->set_count++;
	}
	// Ordering the 3 or 2 remaing items stack A 
	sort_chunk_in_a(stacks, pswap);
	// using the sort algo to sort pswap->chunks sent to B back to A
	while (stacks->stack_b->size > 0)
		move_chunks_to_a(stacks->stack_b, stacks->stack_a, pswap->chunks, pswap->total_chunks);
}

void	clean_up(t_stacks *stacks, t_pswap *pswap)
{
	int i;

	i = 0;
	while (stacks->stack_a->front)
	{
		t_queue_node *temp;
		temp = stacks->stack_a->front;
		stacks->stack_a->front = stacks->stack_a->front->next;
		free(temp);
	}
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
	free(pswap->set);
	while (i < pswap->set_count)
	{
		free(pswap->chunks[i]);
		i++;
	}
	free(pswap->chunks);
	free(pswap);
}

void	push_swap(t_stacks *stacks, t_pswap *pswap)
{
	if (stacks->stack_a->size == 500)
	{
		get_total_chunks_xl(stacks, pswap);
		init_temp_stack(pswap);
		is_sort_needed_xl(stacks, pswap);
	}
	else if (stacks->stack_a->size == 100)
	{
		get_total_chunks_l(stacks, pswap);
		init_temp_stack(pswap);
		is_sort_needed_l(stacks, pswap);
	}
	else
	{
		get_total_chunks(stacks, pswap);
		init_temp_stack(pswap);
		is_sort_needed(stacks, pswap);
	}
}

int main(int argc, char *argv[])
{
	t_stacks	*stacks;
	t_pswap		*pswap;

	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	pswap = (t_pswap *) malloc(sizeof(t_pswap));
	if (!stacks || !pswap)
		return (0);
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (!init_stacks(stacks))
		return (EXIT_SUCCESS);
	// Analyze arguments passed
	parse_args(stacks, argc, argv);

	// With no Errors found in arguments passed, create chunks and sort the numbers
	push_swap(stacks, pswap);

	// Show the Stacks After applying the sorting algorithm
/* 
	ft_putstr_fd("\n\x1b[1;33m", STDERR_FILENO);
	printf("\nAfter applying sorting algorithm, We've got:\x1B[0m\n");
	display(stacks->stack_a);
 */
	// clean up used memory
	clean_up(stacks, pswap);

	// system("leaks push_swap");
	return (EXIT_SUCCESS);
}
