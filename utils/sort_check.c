/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:09:24 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/11 17:28:14 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
	Helper fxn for is_chunk_b_ordered
	Check chunk in B is in descending order
 */
int	check_order_in_b(int *arr, int chunk_size)
{
	int	step;
	int	j;
	int	key;

	step = 1;
	while (step < chunk_size)
	{
		key = arr[step];
		j = step - 1;
		while (key > arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
			free(arr);
			return (0);
		}
		arr[j + 1] = key;
		step++;
	}
	return (1);
}

/* 
	Check for ordering in chunks in B
 */
int	is_chunk_b_ordered(t_stack *stack_b, int chunk_size)
{
	t_stack_node	*head;
	int				*arr;
	int				i;

	head = stack_b->s_nodes;
	arr = (int *) malloc(sizeof(int) * chunk_size);
	if (!arr)
		return (0);
	i = 0;
	while (i < chunk_size)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}
	if (!check_order_in_b(arr, chunk_size))
		return (0);
	free(arr);
	arr = NULL;
	return (1);
}

/*
	Helper fxn for is_chunk_a_ordered
	Checking the whole of stack A is in ascending order
 */
int	check_order_in_a(int *arr, t_queue *stack_a)
{
	int	step;
	int	j;
	int	key;

	step = 1;
	while (step < stack_a->size)
	{
		key = arr[step];
		j = step - 1;
		while (key < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
			free(arr);
			return (0);
		}
		arr[j + 1] = key;
		step++;
	}
	return (1);
}

/*
	Check for ordering of all numbers in A
*/
int	is_chunk_a_ordered(t_queue *stack_a)
{
	t_queue_node	*head;
	int				*arr;
	int				i;

	head = stack_a->front;
	arr = (int *) malloc(sizeof(int) * stack_a->size);
	if (!arr)
		return (0);
	i = 0;
	while (head != NULL)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}
	if (!check_order_in_a(arr, stack_a))
		return (0);
	free(arr);
	arr = NULL;
	return (1);
}
