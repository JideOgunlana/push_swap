/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:37:49 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/08 19:58:18 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	check_m(t_queue *a, t_stack *b, t_tmp_chk *tmp, t_ch_help *h)
{
	if (h->hold_chunk_size == 1)
		m_l_chk_i(a, b, tmp, h);
	else
		m_chk_item(a, b, tmp, h);
}
