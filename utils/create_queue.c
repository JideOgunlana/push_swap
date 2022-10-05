/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:33:50 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/05 16:23:07 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_queue(t_queue *stack_a)
{
	stack_a->size = 0;
}

t_queue_node    *new_node(t_queue *stack_a, int new_item)
{
    stack_a->node = (t_queue_node *) malloc(sizeof(t_queue_node));
    if (!stack_a->node)
        return NULL;
    stack_a->node->item = new_item;
    stack_a->node->next = NULL;
    return stack_a->node;
}

void    enqueue(t_queue *stack_a, int val)
{
    t_queue_node  *added_node;
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
    t_queue_node *dequeued_node;

    if (stack_a->size == 0)
    {
        //// printf("Stack A is empty\n");
        return (NULL);
    }
    if (stack_a->size == 1)
    {
        stack_a->back = NULL;
    }
    dequeued_node = stack_a->front;
    stack_a->front = stack_a->front->next;
    //  // printf("Removed: %d\n", dequeued_node->item);
    stack_a->size--;
    return (dequeued_node);
}

void    display(t_queue *stack_a)
{
    t_queue_node *head;
    if (stack_a->size == 0)
        return ;
    head = stack_a->front;
    // printf("\nElements in Stack A\n");
    while (head)
    {
        printf("%d\n", head->item);
        head = head->next;
    }
}
