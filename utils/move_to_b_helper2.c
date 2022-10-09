/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:39:20 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/09 01:51:14 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 

 */
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
