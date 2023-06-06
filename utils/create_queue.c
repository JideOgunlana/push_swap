/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:33:50 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/11 15:38:28 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack_a(t_queue *stack_a)
{
	stack_a->size = 0;
}

/* 
	Create a new node to add to the queue
*/
t_queue_node	*new_node(t_queue *stack_a, int new_item)
{
	stack_a->node = (t_queue_node *) malloc(sizeof(t_queue_node));
	if (!stack_a->node)
		return (NULL);
	stack_a->node->item = new_item;
	stack_a->node->next = NULL;
	return (stack_a->node);
}

/* 
	Add a node to the end of a queue
 */
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

/* 
	Remove a node at the front of a queue
 */
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

/*
	display items in stack A
*/
void	display(t_queue *stack_a)
{
	t_queue_node	*head;

	if (stack_a->size == 0)
		return ;
	head = stack_a->front;
	ft_putstr_fd("\x1b[1;36m", STDOUT_FILENO);
	ft_putstr_fd("-------------------------------", STDOUT_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDOUT_FILENO);
	ft_putstr_fd("Items in Stack A\n", STDOUT_FILENO);
	while (head)
	{
		ft_putnbr_fd(head->item, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		head = head->next;
	}
}
