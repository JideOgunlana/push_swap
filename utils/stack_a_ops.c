/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:41:30 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/09 02:00:00 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_queue *stack_a)
{
	t_queue_node	*first;
	t_queue_node	*second;

	if (stack_a->size < 2)
		return ;
	first = stack_a->front;
	second = stack_a->front->next;
	first->next = second->next;
	stack_a->front = second;
	stack_a->front->next = first;
	if (stack_a->no_print)
		return ;
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	rotate_a(t_queue *stack_a)
{
	t_list	**lst;
	t_list	*first;

	if (stack_a->size < 2)
		return ;
	first = (t_list *) dequeue(stack_a);
	first->next = NULL;
	stack_a->back = (t_queue_node *) first;
	lst = (t_list **) &stack_a->front;
	ft_lstadd_back(lst, first);
	stack_a->size++;
	if (stack_a->no_print)
		return ;
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rrotate_a(t_queue *stack_a)
{
	t_list			*head;
	t_list			*lst;
	t_list			*new_back;
	t_queue_node	*prev_back;

	if (stack_a->size < 2)
		return ;
	lst = (t_list *) stack_a->front;
	head = lst;
	while (head->next != NULL)
	{
		new_back = (t_list *)head;
		head = head->next;
	}
	stack_a->back = (t_queue_node *) new_back;
	prev_back = (t_queue_node *) ft_lstlast(lst);
	prev_back->next = stack_a->front;
	stack_a->front = prev_back;
	stack_a->back->next = NULL;
	if (stack_a->no_print)
		return ;
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	push_b(t_queue *stack_a, t_stack *stack_b)
{
	t_queue_node	*removed_node;

	removed_node = dequeue(stack_a);
	if (!removed_node)
		return ;
	push(stack_b, removed_node->item);
	free(removed_node);
	if (stack_a->no_print)
		return ;
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
