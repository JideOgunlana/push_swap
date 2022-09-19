/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:37:59 by bogunlan          #+#    #+#             */
/*   Updated: 2022/09/17 19:19:31 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_b(t_stack *stack_b)
{
	// t_list	*head;
	t_list	**lst;
	t_list	*first;

	if (stack_b->size < 2)
		return ;
	first = (t_list *) pop(stack_b);
	first->next = NULL;
	lst = (t_list **) &stack_b->s_nodes;
	ft_lstadd_back(lst, first);
	stack_b->size++;
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rrotate_b(t_stack *stack_b)
{
	t_list	*head;
	t_list	*lst;
	t_list	**lst_dp;
	t_list	*new_back;

	if (stack_b->size < 2)
		return ;
	lst = (t_list *) stack_b->s_nodes;
	lst_dp = (t_list **) &stack_b->s_nodes;
	head = lst;
	while (head->next != NULL)
	{
		new_back = (t_list *)head;
		head = head->next;
	}
	ft_lstadd_front(lst_dp, ft_lstlast(lst));
	new_back->next = NULL;
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	swap_b(t_stack *stack_b)
{
	t_stack_node *first;
	t_stack_node *second;

	if (stack_b->size < 2)
		return ;
	first = stack_b->s_nodes;
	second = stack_b->s_nodes->next;
	first->next = second->next;
	stack_b->s_nodes = second;
	stack_b->s_nodes->next = first;
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	push_a(t_stack *stack_b, t_queue *stack_a)
{
	t_list	*removed_node;
	t_list	**lst;

	removed_node = (t_list *) pop(stack_b);
	if (!removed_node)
		return ;
	lst = (t_list **) &stack_a->front;
	ft_lstadd_front(lst, removed_node);
	stack_a->size++;
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}