/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:11:37 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/09 04:30:10 by bogunlan         ###   ########.fr       */
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
