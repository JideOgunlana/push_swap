/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:28:21 by bogunlan          #+#    #+#             */
/*   Updated: 2022/09/22 21:11:48 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_passed_vals(char *str)
{
	int	i;

	// printf("[ERROR_CHECKERS.C] string: %s\n", str);
	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && !ft_atoi(&str[i]))
			return (1);
		i++;
	}
	return 0;
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
