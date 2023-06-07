/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:33:50 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/07 06:51:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack_a(t_queue *stack_a)
{
	stack_a->size = 0;
}

t_queue_node	*new_node(t_queue *stack_a, int new_item)
{
	stack_a->node = (t_queue_node *) malloc(sizeof(t_queue_node));
	if (!stack_a->node)
		exit(EXIT_SUCCESS);
	if (!stack_a->node)
		return (NULL);
	stack_a->node->item = new_item;
	stack_a->node->next = NULL;
	return (stack_a->node);
}

void	enqueue(t_queue *stack_a, int val)
{
	t_queue_node	*added_node;

	added_node = new_node(stack_a, val);
	if (stack_a->size == 0)
	{
		stack_a->front = added_node;
		stack_a->back = added_node;
		stack_a->least_item = stack_a->front->item;
	}
	else
	{
		stack_a->before_back = stack_a->back;
		stack_a->back->next = added_node;
		stack_a->back = added_node;
		if (stack_a->back->item < stack_a->least_item)
			stack_a->least_item = stack_a->back->item;
	}
	stack_a->size++;
}

t_queue_node	*dequeue(t_queue *stack_a)
{
	t_queue_node	*dequeued_node;

	if (stack_a->size == 0)
		return (NULL);
	if (stack_a->size == 1)
		stack_a->back = NULL;
	dequeued_node = stack_a->front;
	stack_a->front = stack_a->front->next;
	stack_a->size--;
	return (dequeued_node);
}

// Function to display items in stack A
void	display(t_queue *stack_a)
{
	t_queue_node	*head;

	if (stack_a->size == 0)
		return ;
	head = stack_a->front;

	ft_putstr_fd("Items in Stack A\n", STDOUT_FILENO);
	ft_putstr_fd("\x1b[1;36m", STDOUT_FILENO);
	ft_putstr_fd("-", STDOUT_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDOUT_FILENO);
	while (head)
	{
		ft_putnbr_fd(head->item, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		head = head->next;
	}
	ft_putstr_fd("\x1b[1;36m", STDOUT_FILENO);
	ft_putstr_fd("-", STDOUT_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDOUT_FILENO);
}
