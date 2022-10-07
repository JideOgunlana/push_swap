/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:07:58 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/07 18:50:34 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
	Check for a value that is not an integer
 */
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
			exit(0);
		}
		j++;
	}
}

void	check_arg(t_stacks *stacks, char *argv[])
{
	if (stacks->split)
		check_split_arg(stacks);
	else if (check_invalid_vals(argv[stacks->i]))
	{
		error_message();
		free(stacks->stack_a);
		exit(0);
	}
}

/* 
	put values into stack A
 */
void	enqueue_stack_a(t_stacks *stacks)
{
	if (stacks->split)
	{
		check_split_arg_is_int(stacks);
		stacks->split = ft_free(stacks->split);
	}
	else
		check_arg_is_int(stacks);
}

/* 
	Check numbers are in INT range
 */
void	check_split_arg_is_int(t_stacks *stacks)
{
	int	j;

	j = 0;
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
}

void	check_arg_is_int(t_stacks *stacks)
{
	int	j;

	j = 0;
	stacks->ret_val = ft_atoi(stacks->split[j]);
	if (stacks->ret_val < INT32_MIN || stacks->ret_val > INT32_MAX)
	{
		error_message();
		exit(0);
	}
	enqueue(stacks->stack_a, stacks->ret_val);
}

/* 

 */
void	sort_chunk_in_a_helper(t_stacks *stacks, t_pswap *pswap)
{
	if (stacks->stack_a->front->item == pswap->median)
	{
		if (stacks->stack_a->front->next->item < pswap->median)
			swap_a(stacks->stack_a);
		else
			rrotate_a(stacks->stack_a);
	}
	else if (stacks->stack_a->front->item > pswap->median)
	{
		rotate_a(stacks->stack_a);
		if (stacks->stack_a->front->item == pswap->median)
			swap_a(stacks->stack_a);
	}
	else
	{
		swap_a(stacks->stack_a);
		rotate_a(stacks->stack_a);
	}
}

void	sort_chunk_in_a(t_stacks *stacks, t_pswap *pswap)
{
	if (!is_ordered(stacks->stack_a))
	{
		pswap->median = get_a_limiter(stacks->stack_a);
		if (stacks->stack_a->size < 3)
		{
			if (stacks->stack_a->front->item == pswap->median)
				swap_a(stacks->stack_a);
		}
		else
			sort_chunk_in_a_helper(stacks, pswap);
	}
}


/* 
	Find the total chunk needed to move numbers 
	from smallest to largest into B
 */
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
			pswap->temp_stack_a_size -= LIMIT_100;
		else
			pswap->temp_stack_a_size = pswap->temp_stack_a_size - (pswap->temp_stack_a_size / 2);
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
			pswap->temp_stack_a_size -= LIMIT_500;
		else
			pswap->temp_stack_a_size = pswap->temp_stack_a_size - (pswap->temp_stack_a_size / 2);
		pswap->total_chunks++;
	}
}

/* 

 */
void	init_temp_stack(t_pswap *pswap)
{
	pswap->set = (t_chunks *)malloc(sizeof(t_chunks));
	pswap->chunks = (t_chunks **)malloc(sizeof(pswap->set) * pswap->total_chunks);
	if (!pswap->chunks || !pswap->set)
		exit(0);
}

/* 

 */
void	is_sort_needed(t_stacks *stacks, t_pswap *pswap)
{
	if (is_ordered(stacks->stack_a))
		exit(EXIT_SUCCESS);
	pswap->set_count = 0;
	while (stacks->stack_a->size > 3)
	{
		pswap->chunks[pswap->set_count] = get_chunk_set(stacks->stack_a, pswap->set_count);
		move_chunks_to_b(stacks->stack_a, stacks->stack_b, pswap->chunks[pswap->set_count]->data);
		pswap->set_count++;
	}
	sort_chunk_in_a(stacks, pswap);
	while (stacks->stack_b->size > 0)
		move_chunks_to_a(stacks->stack_b, stacks->stack_a, pswap->chunks, pswap->total_chunks);
}

void	is_sort_needed_l(t_stacks *stacks, t_pswap *pswap)
{
	if (is_ordered(stacks->stack_a))
		exit(EXIT_SUCCESS);
	else
	{
		pswap->set_count = 0;
		while (stacks->stack_a->size > 3)
		{
			pswap->chunks[pswap->set_count] = get_chunk_set_l(stacks->stack_a, pswap->set_count);
			move_chunks_to_b(stacks->stack_a, stacks->stack_b, pswap->chunks[pswap->set_count]->data);
			pswap->set_count++;
		}
		sort_chunk_in_a(stacks, pswap);
		while (stacks->stack_b->size > 0)
			move_chunks_to_a(stacks->stack_b, stacks->stack_a, pswap->chunks, pswap->total_chunks);
	}
}

void	is_sort_needed_xl(t_stacks *stacks, t_pswap *pswap)
{
	if (is_ordered(stacks->stack_a))
		exit(EXIT_SUCCESS);
	else
	{
		pswap->set_count = 0;
		while (stacks->stack_a->size > 3)
		{
			pswap->chunks[pswap->set_count] = get_chunk_set_xl(stacks->stack_a, pswap->set_count);
			move_chunks_to_b(stacks->stack_a, stacks->stack_b, pswap->chunks[pswap->set_count]->data);
			pswap->set_count++;
		}
		sort_chunk_in_a(stacks, pswap);
		while (stacks->stack_b->size > 0)
			move_chunks_to_a(stacks->stack_b, stacks->stack_a, pswap->chunks, pswap->total_chunks);
	}
}
