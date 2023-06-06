/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_total_chunks_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:37:41 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/11 17:17:08 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
	Find the total number of chunks needed to move numbers 
	from smallest to largest into B
 */
void	get_t_chks(t_stacks *s, t_pswap *p)
{
	int	tmp_size;

	p->temp_stack_a_size = s->stack_a->size;
	p->t_chks = 0;
	while (p->temp_stack_a_size > 3)
	{
		tmp_size = p->temp_stack_a_size - (p->temp_stack_a_size / 2);
		p->temp_stack_a_size = tmp_size;
		p->t_chks++;
	}
}

void	get_t_chks_l(t_stacks *s, t_pswap *p)
{
	int	tmp_size;

	p->temp_stack_a_size = s->stack_a->size;
	p->t_chks = 1;
	while (p->temp_stack_a_size > 3)
	{
		if (s->stack_a->size > 40)
			p->temp_stack_a_size -= LIMIT_100;
		else
		{
			tmp_size = p->temp_stack_a_size - (p->temp_stack_a_size / 2);
			p->temp_stack_a_size = tmp_size;
		}
		p->t_chks++;
	}
}

void	get_t_chks_xl(t_stacks *s, t_pswap *p)
{
	int	tmp_size;

	p->temp_stack_a_size = s->stack_a->size;
	p->t_chks = 0;
	while (p->temp_stack_a_size > 3)
	{
		if (s->stack_a->size > 40)
			p->temp_stack_a_size -= LIMIT_500;
		else
		{
			tmp_size = p->temp_stack_a_size - (p->temp_stack_a_size / 2);
			p->temp_stack_a_size = tmp_size;
		}
		p->t_chks++;
	}
}
