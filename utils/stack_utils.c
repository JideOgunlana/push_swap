/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:36:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/09/29 14:43:14 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *s)
{
	t_stack_node *head;

	head = s->s_nodes;
	printf("\nElements in stack B:\n");
	if (is_empty(s))
	{
		printf("Stack B is empty\n");
		return ;
	}
	while (head != NULL)
	{
		printf("%d\n", head->item);
		head = head->next;
	}
}

void	peek(t_stack *s)
{
	if (is_empty(s))
	{
		printf("Stack is empty\n");
		return ;
	}
	printf("Element on top of stack: %d\n", s->s_nodes->item);
}