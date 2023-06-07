/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:06:07 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/08 20:43:20 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*insertion_sort_on_a(t_queue *stack_a, int *arr)
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
		}
		arr[j + 1] = key;
		step++;
	}
	return (arr);
}

void	*insertion_sort_on_b(int *arr, int arr_size)
{
	int	step;
	int	j;
	int	key;

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
