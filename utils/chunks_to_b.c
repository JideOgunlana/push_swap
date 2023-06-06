/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:37:49 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/06 15:50:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
	Determine the rotations or reverse rotations to make in order to move found val to stack B
 */
void	val_in_a(t_queue *stack_a, t_tmp_chk *tmp, t_ch_help *helper)
{
	tmp->last++;
	if (!tmp->first)
	{
		tmp->r = helper->head_a_moves;
		tmp->first = 1;
	}
	if (tmp->last == helper->hold_chunk_size)
	{
		tmp->rr = stack_a->size - helper->head_a_moves;
	}
	tmp->total_r += helper->head_a_moves;
	tmp->total_rr += stack_a->size - helper->head_a_moves;
}

/* 
	move the last item for a chunk in stack A to B
 */
void	m_l_chk_i(t_queue *a, t_stack *b, t_tmp_chk *tmp, t_ch_help *h)
{
	if (tmp->total_r < tmp->total_rr)
		ra(a, tmp);
	else if (tmp->total_r > tmp->total_rr)
		rra(a, tmp);
	else
		ra(a, tmp);
	push_b(a, b);
	h->hold_chunk_size--;
}

/* 
	helper fxn used by m_chk_item.
	Invoked to determine the best move to make when both
	total rotation and rrotations are the same
 */
void	m_chk_i_h(t_queue *a, t_stack *b, t_tmp_chk *tmp, t_ch_help *h)
{
	if (tmp->r < tmp->rr && tmp->rr != 0)
		ra(a, tmp);
	else if (tmp->r > tmp->rr && tmp->rr != 0)
		rra(a, tmp);
	else
		ra(a, tmp);
	push_b(a, b);
	h->hold_chunk_size--;
}

/* 
	Move the item for a chunk in stack A to B whenever there is
	at least 2 items in the chunk
 */
void	m_chk_item(t_queue *a, t_stack *b, t_tmp_chk *tmp, t_ch_help *h)
{
	if (tmp->total_r < tmp->total_rr)
	{
		ra(a, tmp);
		push_b(a, b);
		h->hold_chunk_size--;
	}
	else if (tmp->total_r > tmp->total_rr)
	{
		rra(a, tmp);
		push_b(a, b);
		h->hold_chunk_size--;
	}
	else
		m_chk_i_h(a, b, tmp, h);
}

/* 
	Moves the items in A to B for a given chunk
 */
void	check_m(t_queue *a, t_stack *b, t_tmp_chk *tmp, t_ch_help *h)
{
	if (h->hold_chunk_size == 1)
		m_l_chk_i(a, b, tmp, h);
	else
		m_chk_item(a, b, tmp, h);
}
