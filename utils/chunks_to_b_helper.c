/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_to_b_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:43:28 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/08 19:42:56 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_temp_chunk(t_tmp_chk *temp)
{
	temp->r = 0;
	temp->rr = 0;
	temp->first = 0;
	temp->last = 0;
	temp->total_r = 0;
	temp->total_rr = 0;
}

void	init_ch_help(t_ch_help *helper, int chunk_size, t_queue *stack_a)
{
	helper->head_a_moves = 0;
	helper->hold_chunk_size = chunk_size;
	helper->head_a = stack_a->front;
}

void	ra(t_queue *stack_a, t_tmp_chk *temp)
{
	while (temp->r > 0)
	{
		rotate_a(stack_a);
		temp->r--;
	}
}

void	rra(t_queue *stack_a, t_tmp_chk *temp)
{
	while (temp->rr > 0)
	{
		rrotate_a(stack_a);
		temp->rr--;
	}
}

void	free_stack_helper(t_tmp_chk *temp, t_ch_help *helper)
{
	free(temp);
	free(helper);
}
