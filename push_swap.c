/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:58:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/09/16 21:37:25 by bogunlan         ###   ########.fr       */
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
			if (ft_strlen(argv[i]) > 1)
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
						printf("\x1B[0m\n");
						ft_free(split);
						system("leaks a.out");
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
				printf("\x1B[0m\n");
				free(stack_a);
				return 0;
			}
			if (split)
			{
				j = 0;
				while (split[j] != NULL)
				{
					enqueue(stack_a, ft_atoi(split[j]));
					j++;
				}
				split = ft_free(split);
			}
			else
				enqueue(stack_a, ft_atoi(argv[i]));
			i++;
		}
	}
	if (check_duplicates(stack_a))
	{
		ft_putstr_fd("\x1b[1;31m", STDERR_FILENO);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		printf("*************************************************************************\n");
		printf("**************************** Duplicates found ***************************\n");
		printf("*************************************************************************");
		printf("\x1B[0m\n");
		if (split)
			ft_free(split);
		system("leaks a.out");
		return 0;
	}
	ft_putstr_fd("\n\n\x1b[1;32m", STDERR_FILENO);
	ft_putstr_fd("Hurray!! No errors, at least for now.", STDERR_FILENO);
	printf("\x1B[0m\n\n\n");
	ft_putstr_fd("Items in queue\n", STDOUT_FILENO);
	display(stack_a);
	// this is like an algo to use swap_a()
/* 	if (stack_a->size > 1)
	{
		t_queue_node *head;
		int	median = stack_a->size / 2;
		int	i;

		i = 0;
		head = stack_a->front;
		while (head  && i < median)
		{
			if (stack_a->front->item > stack_a->front->next->item)
				swap_a(stack_a);
			head = head->next;
			i++;
		}
	} */

	swap_a(stack_a);
	display(stack_a);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	// push_b(stack_a, stack_b);
	print_stack(stack_b);
	// rotate_a_b(stack_a, stack_b); // Not needed as it takes more moves
	// reverse_a_b(stack_a, stack_b);
	print_stack(stack_b);
	swap_a(stack_a);
	// printf("Stack size: %d\n", stack_b->size);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
	printf("________________________ Example ________________\n\n");

	display(stack_a);
	
	system("leaks a.out");
	return 0;
}