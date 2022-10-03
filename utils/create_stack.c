/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:33:48 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/03 13:29:04 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_stack(t_stack *s)
{
	s->size = 0;
}

t_stack_node	*new_stack_node(int val)
{
	t_stack_node *top_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!top_node)
		return NULL;
	top_node->item = val;
	top_node->next = NULL;
	return top_node;
}

// CHECK IF THE STACK IS EMPTY
int	is_empty(t_stack *s)
{
	if (s->size == 0)
		return 1;
	return 0;
}

// ADD ELEMENTS INTO STACK
void	push(t_stack *s, int new_item)
{
	t_stack_node *pushed_node;

	pushed_node = (t_stack_node *) malloc(sizeof(t_stack_node));
	if (!pushed_node)
		return ;
	else if (is_empty(s))
	{
		s->s_nodes = new_stack_node(new_item);
		free(pushed_node);
	}
	else
	{
		pushed_node->item = new_item;
		pushed_node->next = s->s_nodes;
		s->s_nodes = pushed_node;
	}
	s->size++;
}

// REMOVE ELEMENT FROM THE TOP OF STACK
t_stack_node	*pop(t_stack *s)
{
	t_stack_node	*popped_node;
	t_stack_node	*top_node;

	if (is_empty(s))
	{
		// printf("Stack B is empty\n");
		return 0;
	}
	top_node = s->s_nodes->next;
	popped_node = s->s_nodes;
	s->s_nodes = top_node;
	s->size--;
	return (popped_node);
}