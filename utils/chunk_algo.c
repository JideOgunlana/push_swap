/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:43:14 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/06 15:47:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* 
 *	Assign the size of numbers for each chunk (batch) needed by the push_swap program to sort the random numbers passed
 */
t_chunks	*get_chk_set_xl(t_queue *stack_a, int set_count)
{
	t_chunks	*set;

	set = (t_chunks *)malloc(sizeof(t_chunks));
	if (!set)
		exit(EXIT_SUCCESS);
	if (stack_a->size > 5)
		set->data = LIMIT_500;
	else
		set->data = stack_a->size / 2;
	set->key = set_count;
	return (set);
}

t_chunks	*get_chunk_set_l(t_queue *stack_a, int set_count)
{
	t_chunks	*set;

	set = (t_chunks *)malloc(sizeof(t_chunks));
	if (!set)
		exit(EXIT_SUCCESS);
	if (stack_a->size > 11)
		set->data = LIMIT_100;
	else
		set->data = stack_a->size / 2;
	set->key = set_count;
	return (set);
}

t_chunks	*get_chunk_set(t_queue *stack_a, int set_count)
{
	t_chunks	*set;

	set = (t_chunks *)malloc(sizeof(t_chunks));
	if (!set)
		exit(EXIT_SUCCESS);
	set->data = stack_a->size / 2;
	set->key = set_count;
	return (set);
}
