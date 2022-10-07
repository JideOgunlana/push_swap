/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:28:21 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/07 16:53:31 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_invalid_vals(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && !ft_atoi(&str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicates(t_queue *stack_a)
{
	t_queue_node	*head;
	t_queue_node	*j;

	head = stack_a->front;
	while (head)
	{
		j = head->next;
		while (j)
		{
			if (head->item == j->item)
				return (1);
			j = j->next;
		}
		head = head->next;
	}
	return (0);
}

void	error_message(void)
{
	ft_putstr_fd("\x1b[1;31m", STDERR_FILENO);
	ft_putstr_fd("Error", STDERR_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDERR_FILENO);
}
