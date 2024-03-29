/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:36:27 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/07 06:53:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *s)
{
	t_stack_node	*head;

	head = s->s_nodes;
	ft_putstr_fd("\nItems in Stack B\n", STDOUT_FILENO);
	ft_putstr_fd("\x1b[1;33m", STDOUT_FILENO);
	ft_putstr_fd("-\n", STDOUT_FILENO);
	ft_putstr_fd("\x1B[0m", STDOUT_FILENO);
	if (is_empty(s))
		ft_putstr_fd("Stack is empty\n", STDOUT_FILENO);
	while (head != NULL)
	{
		ft_putnbr_fd(head->item, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		head = head->next;
	}
	ft_putstr_fd("\x1b[1;33m", STDOUT_FILENO);
	ft_putstr_fd("-\n", STDOUT_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDOUT_FILENO);
}

void	peek(t_stack *s)
{
	if (is_empty(s))
	{
		ft_putstr_fd("Stack is empty\n", STDOUT_FILENO);
		return ;
	}
	ft_putstr_fd("Element on top of stack:\n", STDOUT_FILENO);
	ft_putnbr_fd(s->s_nodes->item, STDOUT_FILENO);
}
