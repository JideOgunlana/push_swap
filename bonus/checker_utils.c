/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:11:37 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/09 21:10:14 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	checker_pass_mess(void)
{
	ft_putstr_fd("\x1b[1;32m", STDOUT_FILENO);
	ft_putstr_fd("OK", STDOUT_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDOUT_FILENO);
}

void	checker_err_mess(void)
{
	ft_putstr_fd("\x1b[1;31m", STDOUT_FILENO);
	ft_putstr_fd("KO", STDOUT_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDOUT_FILENO);
}

void	is_stack_sorted(t_stacks *stacks)
{
	if (is_ordered(stacks->stack_a))
		checker_pass_mess();
	else
		checker_err_mess();
}

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
