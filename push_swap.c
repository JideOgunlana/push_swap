/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:58:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/06 00:36:03 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_queue	*stack_a;
	t_stack	*stack_b;
	char	**split;
	int		i;
	int		j;
	int		median;
	long long	val_ret;

	split = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	stack_a = (t_queue *) malloc(sizeof(t_queue));
	stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return 0;
	create_queue(stack_a);
	create_stack(stack_b);
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (ft_strlen(argv[i]) > 0)
				split = ft_split(argv[i], ' ');
			if (split)
			{
				j = 0;
				while (split[j] != NULL)
				{
					if (check_passed_vals(split[j]))
					{
						ft_putstr_fd("\x1b[1;31m", STDERR_FILENO);
						ft_putstr_fd("Error\n", STDERR_FILENO);
						ft_putstr_fd("Contains value that is not a number", STDERR_FILENO);
						ft_putstr_fd("\x1B[0m\n", STDERR_FILENO);
						ft_free(split);
						// system("leaks push_swap");
						return 0;
					}
					j++;
				}
			}
			else if (check_passed_vals(argv[i]))
			{
				ft_putstr_fd("\x1b[1;31m", STDERR_FILENO);
				ft_putstr_fd("Error\n", STDERR_FILENO);
				ft_putstr_fd("Contains value that is not a number", STDERR_FILENO);
				ft_putstr_fd("\x1B[0m\n", STDERR_FILENO);
				free(stack_a);
				// system("leaks push_swap");
				return 0;
			}
			if (split)
			{
				j = 0;
				while (split[j] != NULL)
				{
					val_ret = ft_atoi(split[j]);
					if (val_ret < INT32_MIN || val_ret > INT32_MAX)
					{
						printf("Error\n");
						exit(0);
					}
					enqueue(stack_a, val_ret);
					j++;
				}
				split = ft_free(split);
			}
			else
			{
				val_ret = ft_atoi(split[j]);
				if (val_ret < INT32_MIN || val_ret > INT32_MAX)
				{
					printf("Error\n");
					exit(0);
				}
				enqueue(stack_a, val_ret);
			}
			i++;
		}
	}
	if (check_duplicates(stack_a))
	{
		ft_putstr_fd("\x1b[1;31m", STDERR_FILENO);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("\x1B[0m\n", STDERR_FILENO);
		if (split)
			ft_free(split);
		// system("leaks push_swap");
		return 0;
	}

	t_chunks	**chunks;
	t_chunks	*set;
	int			total_chunks;
	int			temp_stack_a_size;

	temp_stack_a_size = stack_a->size;
	// if (temp_stack_a_size > 40)
	// 	total_chunks = 1;
	// else
		total_chunks = 0;
	while (temp_stack_a_size > 3)
	{
		if (stack_a->size > 40)
		{
			temp_stack_a_size -= LIMIT;
		}
		else
		{
			temp_stack_a_size = temp_stack_a_size - (temp_stack_a_size / 2);
		}
		total_chunks++;
	}
	// // // printf("Total chunks to create: %d\n", total_chunks);
	set = (t_chunks *)malloc(sizeof(t_chunks));
	chunks = (t_chunks **)malloc(sizeof(set) * total_chunks);
	if (!chunks || !set)
		return 0;
	if (is_ordered(stack_a))
	{
		system("leaks push_swap");
		return 0;
	}
	else
	{
		int set_count = 0;
		while (stack_a->size > 3)
		{
			chunks[set_count] = get_chunk_set(stack_a, set_count);
			move_chunks_to_b(stack_a, stack_b, chunks[set_count]->data);
			set_count++;
		}

		if (!is_ordered(stack_a))
		{
			median = insertion_sort(stack_a);
			if (stack_a->size < 3)
			{
				if (stack_a->front->item == median)
				{
					swap_a(stack_a);
				}
			}
			else
			{
				if (stack_a->front->item == median)
				{
					if (stack_a->front->next->item < median)
					{
						swap_a(stack_a);
					}
					else
					{
						rrotate_a(stack_a);
					}
				}
				else if (stack_a->front->item > median)
				{
					rotate_a(stack_a);
					if (stack_a->front->item == median)
					{
						swap_a(stack_a);
					}
				}
				else
				{
					swap_a(stack_a);
					rotate_a(stack_a);
				}
			}
		}
		while (stack_b->size > 0)
		{
			move_chunks_to_a(stack_b, stack_a, chunks, total_chunks);
		}
	}

/* 
	Show the Stacks After applying the sorting algorithm
 */

	// ft_putstr_fd("\n\x1b[1;33m", STDERR_FILENO);
	// printf("\nAfter applying sorting algorithm, We've got:\x1B[0m\n");
	display(stack_a);
	system("leaks push_swap");
	return 0;
}
