/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_to_a_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:59:08 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/08 20:47:04 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	m_sorted_chk(t_queue *a, t_stack *b, t_sort_chunk *sc)
{
	while (sc->chunk_size > 0)
	{
		push_a(b, a);
		sc->chunk_size--;
	}
}

void	m_a(t_queue *a, t_stack *b, t_sort_chunk *s_c, t_chunks **c)
{
	push_a(b, a);
	s_c->push_to_a_state = 1;
	c[s_c->t_chks - 1]->data--;
	s_c->items_at_top_count = c[s_c->t_chks - 1]->data - s_c->rotations;
}

void	found_at_bottom(t_stack *stack_b, t_sort_chunk *sc)
{
	int	y;

	y = 0;
	if (sc->rotations)
	{
		rrotate_b(stack_b);
		while (sc->sch_val != stack_b->s_nodes->item)
		{
			rrotate_b(stack_b);
			y++;
		}
		sc->rotations -= (y + 1);
	}
	sc->head_b = stack_b->s_nodes;
}

void	serach_val(t_stack *stack_b, t_sort_chunk *sc)
{
	sc->temp_items_at_top = sc->items_at_top_count;
	sc->search_at_top = 0;
	sc->temp_head_b = sc->head_b;
	while (sc->temp_items_at_top > 0)
	{
		if (sc->temp_head_b->item == sc->sch_val)
		{
			sc->search_at_top = 1;
		}
		sc->temp_head_b = sc->temp_head_b->next;
		sc->temp_items_at_top--;
	}
	if (sc->search_at_top)
	{
		rotate_b(stack_b);
		sc->rotations++;
		sc->search_at_top = 0;
	}
	else
		found_at_bottom(stack_b, sc);
}

void	find_val_in_chunk(t_stack *stack_b, t_sort_chunk *sc)
{
	if (sc->items_at_top_count > 1)
		serach_val(stack_b, sc);
	else if (sc->items_at_top_count == 1 && sc->rotations > 0)
	{
		rrotate_b(stack_b);
		sc->items_at_top_count++;
		sc->rotations--;
	}
}
