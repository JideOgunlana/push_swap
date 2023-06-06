/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:11:37 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/06 15:47:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
 *	Print OK if requirements to sort stack A is accomplished
*/
void	checker_pass_mess(void)
{
	ft_putstr_fd("\x1b[1;32m", STDOUT_FILENO);
	ft_putstr_fd("OK", STDOUT_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDOUT_FILENO);
}

/* 
 *	Print KO if requirements to sort stack A is not accomplished
*/
void	checker_err_mess(void)
{
	ft_putstr_fd("\x1b[1;31m", STDOUT_FILENO);
	ft_putstr_fd("KO", STDOUT_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDOUT_FILENO);
}

/* 
 *	Check stack A if it is sorted in ascending order
*/
void	checker_is_stack_sorted(t_stacks *stacks)
{
	if (is_chunk_a_ordered(stacks->stack_a))
		checker_pass_mess();
	else
		checker_err_mess();
}

/* 
 *	Deallocate all memory used by the checker program
*/
void	checker_clean_up(t_stacks *stacks)
{
	t_queue_node	*tmp_a;
	t_stack_node	*tmp_b;

	while (stacks->stack_a->front)
	{
		tmp_a = stacks->stack_a->front;
		stacks->stack_a->front = stacks->stack_a->front->next;
		free(tmp_a);
	}
	while (stacks->stack_b->s_nodes)
	{
		tmp_b = stacks->stack_b->s_nodes;
		stacks->stack_b->s_nodes = stacks->stack_b->s_nodes->next;
		free(tmp_b);
	}
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}
