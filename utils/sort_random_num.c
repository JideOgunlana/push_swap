/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_random_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:04:46 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/07 04:38:31 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
	Insertion sort program sorts the numbers in Stack A 
	to realise the median.

	The median value is used to determine which numbers
	for a given chunk should be pushed to Stack B

 */

int	*gen_ascending_chunk(t_queue *stack_a)
{
	t_queue_node	*head;
	int				*arr;

	head = stack_a->front;
	arr = (int *) malloc(sizeof(int) * stack_a->size);
	if (!arr)
		return 0;
	int	i;

	i = 0;
	while (head != NULL)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}

	int step;
    int j;
    int key;

    step = 1;
    while (step < stack_a->size)
    {
        key = arr[step];
        j = step - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        step++;
    }

	return (arr);
}

int	insertion_sort(t_queue	*stack_a)
{
	t_queue_node	*head;
	int				*arr;
	int				median;

	head = stack_a->front;
	arr = (int *) malloc(sizeof(int) * stack_a->size);
	if (!arr)
		return 0;
	int	i;

	i = 0;
	while (head != NULL)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}

	int step;
    int j;
    int key;

    step = 1;
    while (step < stack_a->size)
    {
        key = arr[step];
        j = step - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        step++;
    }
	// if (stack_a->size > 40)
	// {
	// 	int limiter = stack_a->size - LIMIT;
	// 	median = arr[stack_a->size - limiter];
	// 	// // printf("stack A size: %d\tmedian: %d",stack_a->size,  median);
	// 	// exit(0);
	// }
	// else
		median = arr[stack_a->size / 2];
	free(arr);
	arr = NULL;
	return median;
}

int	insertion_sort_on_b(t_stack	*stack_b, int arr_size)
{
	t_stack_node	*head;
	int				*arr;
	int				median;
	head = stack_b->s_nodes;
	arr = (int *) malloc(sizeof(int) * arr_size);
	if (!arr)
		return 0;
	int	i;

	i = 0;
	while (i < arr_size)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}

	int step;
    int j;
    int key;

    step = 1;
    while (step < arr_size)
    {
        key = arr[step];
        j = step - 1;
        while (key > arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        step++;
    }

	median = arr[arr_size/ 2];
	free(arr);
	arr = NULL;
	return median;
}

/* 
	Checking chunk in descending order
 */
int is_chunk_ordered(t_stack *stack_b, int chunk_size)
{
	t_stack_node	*head;
	int				*arr;
	int				i;

	head = stack_b->s_nodes;
	arr = (int *) malloc(sizeof(int) * chunk_size);
	if (!arr)
		return 0;

	i = 0;
	while (i < chunk_size)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}

	int step;
    int j;
    int key;

    step = 1;
	// // // printf("chunk size: %d\n", chunk_size);
    while (step < chunk_size) // descending order check
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
	free(arr);
	arr = NULL;
	return (1);
}

int	is_ordered(t_queue *stack_a)
{
	t_queue_node	*head;
	int				*arr;
	int				i;

	head = stack_a->front;
	arr = (int *) malloc(sizeof(int) * stack_a->size);
	if (!arr)
		return 0;

	i = 0;
	while (head != NULL)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}

	int step;
    int j;
    int key;

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
	free(arr);
	arr = NULL;
	return (1);
}

int	*gen_descending_chunk(t_stack *stack_b, int arr_size)
{
	t_stack_node	*head;
	int				*arr;
	int				i;

	head = stack_b->s_nodes;
	arr = (int *) malloc(sizeof(int) * arr_size);
	if (!arr)
		return 0;

	i = 0;
	while (i < arr_size)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}

	int step;
    int j;
    int key;

    step = 1;
    while (step < arr_size)
    {
        key = arr[step];
        j = step - 1;
        while (key > arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        step++;
    }
	return (arr);
}
