/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:17:32 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/11 17:06:39 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
	Reset the chunk starting postion in A when all items in previous 
	chunk have been moved to stack B
*/
void	reset_chk(t_queue *a, t_stack *b, t_tmp_chk *tmp, t_ch_help *h)
{
	check_m(a, b, tmp, h);
	init_temp_chunk(tmp);
	h->head_a_moves = -1;
	h->head_a = a->front;
}

/* 
	Help fxn for check_op_to_b
	Determine where the head position is
*/
void	helper_head_moves(t_ch_help *helper)
{
	if (helper->head_a_moves != -1)
		helper->head_a = helper->head_a->next;
	helper->head_a_moves++;
}

/* 
	Help fxn for check_op_to_b
	Deallocates memory allocated to helper pointers temp
	and helper
*/
void	helper_malloc_fail(t_tmp_chk *temp, t_ch_help *helper)
{
	if (!temp || !helper)
		exit(EXIT_SUCCESS);
}

/*  
	Check the operation to perform to move items to B for a 
	particular set of chunk
*/
void	check_op_to_b(t_queue *a, t_stack *b, int *tmp_chk, int chk_size)
{
	t_tmp_chk	*temp;
	t_ch_help	*helper;

	temp = (t_tmp_chk *)malloc(sizeof(t_tmp_chk));
	helper = (t_ch_help *)malloc(sizeof(t_ch_help));
	helper_malloc_fail(temp, helper);
	init_temp_chunk(temp);
	init_ch_help(helper, chk_size, a);
	while (helper->head_a && helper->hold_chunk_size != 0)
	{
		helper->i = 0;
		while (helper->i < chk_size)
		{
			if (helper->head_a->item == tmp_chk[helper->i])
				val_in_a(a, temp, helper);
			if (temp->first && temp->last == helper->hold_chunk_size)
			{
				reset_chk(a, b, temp, helper);
				break ;
			}
			helper->i++;
		}
		helper_head_moves(helper);
	}
	free_stack_helper(temp, helper);
}

/* 
	Move the items in chunks to B from smallest vals to largest
*/
void	m_chk_to_b(t_queue *stack_a, t_stack *stack_b, int chk_size)
{
	int	*temp_arr;
	int	*tmp_chk;
	int	i;

	i = 0;
	temp_arr = gen_ascending_chunk(stack_a);
	tmp_chk = (int *)malloc(sizeof(int) * chk_size);
	if (!tmp_chk)
		return ;
	while (i < chk_size)
	{
		tmp_chk[i] = temp_arr[i];
		i++;
	}
	check_op_to_b(stack_a, stack_b, tmp_chk, chk_size);
	free(temp_arr);
	free(tmp_chk);
}
