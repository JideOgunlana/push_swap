/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b_helper1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:33:06 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/11 17:52:34 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_temp_stack(t_pswap *pswap)
{
	pswap->set = (t_chunks *)malloc(sizeof(t_chunks));
	pswap->chunks = (t_chunks **)malloc(sizeof(pswap->set) * pswap->t_chks);
	if (!pswap->chunks || !pswap->set)
		exit(EXIT_SUCCESS);
}

/* 
	Check for need to sort to move items to stack B if numbers are not ordered
*/
void	is_sort_needed(t_stacks *s, t_pswap *p)
{
	if (is_chunk_a_ordered(s->stack_a))
		exit(EXIT_SUCCESS);
	p->set_count = 0;
	while (s->stack_a->size > 3)
	{
		p->chunks[p->set_count] = get_chunk_set(s->stack_a, p->set_count);
		m_chk_to_b(s->stack_a, s->stack_b, p->chunks[p->set_count]->data);
		p->set_count++;
	}
	sort_chunk_in_a(s, p);
	while (s->stack_b->size > 0)
		move_chunks_to_a(s->stack_b, s->stack_a, p->chunks, p->t_chks);
}

void	is_sort_needed_l(t_stacks *s, t_pswap *p)
{
	if (is_chunk_a_ordered(s->stack_a))
		exit(EXIT_SUCCESS);
	else
	{
		p->set_count = 0;
		while (s->stack_a->size > 3)
		{
			p->chunks[p->set_count] = get_chunk_set_l(s->stack_a, p->set_count);
			m_chk_to_b(s->stack_a, s->stack_b, p->chunks[p->set_count]->data);
			p->set_count++;
		}
		sort_chunk_in_a(s, p);
		while (s->stack_b->size > 0)
			move_chunks_to_a(s->stack_b, s->stack_a, p->chunks, p->t_chks);
	}
}

void	is_sort_needed_xl(t_stacks *s, t_pswap *p)
{
	if (is_chunk_a_ordered(s->stack_a))
		exit(EXIT_SUCCESS);
	else
	{
		p->set_count = 0;
		while (s->stack_a->size > 3)
		{
			p->chunks[p->set_count] = get_chk_set_xl(s->stack_a, p->set_count);
			m_chk_to_b(s->stack_a, s->stack_b, p->chunks[p->set_count]->data);
			p->set_count++;
		}
		sort_chunk_in_a(s, p);
		while (s->stack_b->size > 0)
			move_chunks_to_a(s->stack_b, s->stack_a, p->chunks, p->t_chks);
	}
}
