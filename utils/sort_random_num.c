/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_random_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:04:46 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/08 19:13:42 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
	Insertion sort program sorts the numbers in Stack A 
	to realise the limit.

	The limit (median) value is used to determine which numbers
	for a given chunk in stack A to be pushed to Stack B
 */

int	*gen_ascending_chunk(t_queue *stack_a)
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
	insertion_sort_on_a(stack_a, arr);
	return (arr);
}

int	*gen_descending_chunk(t_stack *stack_b, int arr_size)
{
	t_stack_node	*head;
	int				*arr;
	int				i;

	head = stack_b->s_nodes;
	arr = (int *) malloc(sizeof(int) * arr_size);
	if (!arr)
		return (0);
	i = 0;
	while (i < arr_size)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}
	insertion_sort_on_b(arr, arr_size);
	return (arr);
}

int	get_a_limiter(t_queue *stack_a)
{
	t_queue_node	*head;
	int				*arr;
	int				median;
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
	insertion_sort_on_a(stack_a, arr);
	median = arr[stack_a->size / 2];
	free(arr);
	arr = NULL;
	return (median);
}

int	get_b_limiter(t_stack *stack_b, int arr_size)
{
	t_stack_node	*head;
	int				*arr;
	int				median;
	int				i;

	head = stack_b->s_nodes;
	arr = (int *) malloc(sizeof(int) * arr_size);
	if (!arr)
		return (0);
	i = 0;
	while (i < arr_size)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}
	insertion_sort_on_b(arr, arr_size);
	median = arr[arr_size / 2];
	free(arr);
	arr = NULL;
	return (median);
}
