/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:39:44 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/11 17:27:04 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
	Move found item to a
*/
int	m_f_i_to_a(t_stack *b, t_queue *a, t_sort_chunk *sc, t_chunks **chk)
{
	int	y;

	y = 0;
	sc->sch_val = sc->d_arr[sc->search_index - chk[sc->t_chks - 1]->data];
	if (b->size == 1)
	{
		push_a(b, a);
		sc->rotations = 0;
		return (1);
	}
	else
	{
		rrotate_b(b);
		while (sc->sch_val != b->s_nodes->item)
		{
			rrotate_b(b);
			y++;
		}
		sc->rotations -= (y + 1);
	}
	sc->head_b = b->s_nodes;
	return (0);
}

/* 
	Search stack B for the highest val in its chunk to move to A and,
	Move the found item to A
*/
void	search_and_m(t_stack *b, t_queue *a, t_sort_chunk *sc, t_chunks **chk)
{
	while (chk[sc->t_chks - 1]->data > 0)
	{
		sc->sch_val = sc->d_arr[sc->search_index - chk[sc->t_chks - 1]->data];
		sc->push_to_a_state = 0;
		if (sc->head_b->item == sc->sch_val)
			m_a(a, b, sc, chk);
		else if (sc->head_b->item != sc->sch_val)
			find_val_in_chunk(b, sc);
		if (!sc->push_to_a_state)
		{
			sc->head_b = sc->head_b->next;
			sc->head_b_moves++;
		}
		if (sc->items_at_top_count > 0)
			sc->head_b = b->s_nodes;
		else if (sc->items_at_top_count == 0 && chk[sc->t_chks - 1]->data > 0)
		{
			if (m_f_i_to_a(b, a, sc, chk))
				break ;
		}
	}
}

/* 
	Initialize the pointer to help to sort set of numbers in B chunk
*/
void	init_chunks(t_stack *b, t_sort_chunk *sc, t_chunks **chk)
{
	sc->head_b = b->s_nodes;
	sc->head_b_moves = 0;
	sc->rotations = 0;
	sc->d_arr = gen_descending_chunk(b, chk[sc->t_chks - 1]->data);
	sc->search_index = chk[sc->t_chks - 1]->data;
	sc->items_at_top_count = chk[sc->t_chks - 1]->data;
}

/* 
	Sort the chunks placing the highest val to the top
	the highest val of the chunk is moved to stack A
*/
void	sort_chk_b(t_stack *b, t_queue *a, t_sort_chunk *sc, t_chunks **chk)
{
	while (sc->t_chks > 0)
	{
		sc->median = get_b_limiter(b, chk[sc->t_chks - 1]->data);
		sc->chunk_size = chk[sc->t_chks - 1]->data;
		if (is_chunk_b_ordered(b, sc->chunk_size))
			m_sorted_chk(a, b, sc);
		else
		{
			if (b->size <= 2)
				stack_b_has_two(a, b);
			else if (b->size == 3)
				stack_b_has_three(a, b);
			else
			{
				init_chunks(b, sc, chk);
				search_and_m(b, a, sc, chk);
			}
		}
		sc->t_chks--;
		if (sc->d_arr)
		{
			free(sc->d_arr);
			sc->d_arr = NULL;
		}
	}
}

/* 
	Check the size of B to determine how to sort and move
	items back to A
*/
void	move_chunks_to_a(t_stack *b, t_queue *a, t_chunks **chk, int t_chks)
{
	t_sort_chunk	*sc;

	sc = (t_sort_chunk *) malloc(sizeof(t_sort_chunk));
	if (!sc)
		return ;
	sc->t_chks = t_chks;
	sc->d_arr = NULL;
	if (b->size <= 2)
		stack_b_has_two(a, b);
	if (b->size == 3)
		stack_b_has_three(a, b);
	if (b->size > 3)
		sort_chk_b(b, a, sc, chk);
	free(sc);
}
