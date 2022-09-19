/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:58:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/09/19 00:13:56 by bogunlan         ###   ########.fr       */
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
	ft_putstr_fd("Items in STACK A\n\n", STDOUT_FILENO);
	display(stack_a);
	printf("\n");

	// Creating a simple algorithm to
	// understand how to sort a
	// small set of data with STACK A & STACK B
	// This algo. works with 3 to 4 elements in STACK 

	// dividing STACK A into a smaller (into half)
	// and passing the remaining half to STACK B
	if (stack_a->size >= 3 && stack_a->size <= 4)
	{
		t_queue_node	*head;
		int				median;
		int				count;

		head = stack_a->front;
		median = stack_a->size / 2;
		count = 0;
		
		while (head && count < median)
		{
			push_b(stack_a, stack_b);
			head = head->next;
			count++;
		}
	}
	int	step1 = 1;
	int	step2 = 1;
	int	step3 = 1;
	if (stack_a->size <= 2 && stack_b->size <= 2)
	{
		while (step1 || step2 || step3)
		{
			printf("Elements in STACK A:\n");
			display(stack_a);
			print_stack(stack_b);
			// check elements in STACK B if any operation
			// should be carried out to sort this half

			if (stack_b->size > 1)
			{
				if (stack_b->s_nodes->item < stack_b->s_nodes->next->item)
				{
					swap_b(stack_b);
					step1 = 1;
				}
				else
				{
					step1 = 0;
				}
			}
			// Comparing top elements in both stacks
			if (stack_a->size > 1 && stack_b->size > 1)
			{
				if (stack_a->front->item < stack_b->s_nodes->item)
				{
					push_a(stack_b, stack_a);
					swap_a(stack_a);
					push_b(stack_a, stack_b);
					step2 = 1;
				}
				else
				{
					step2 = 0;
				}
			}

			// check elements in STACK A if any operation
			// should be carried out to sort this half
			if (stack_a->size > 1)
			{
				if (stack_a->front->item > stack_a->front->next->item)
				{
					swap_a(stack_a);
					step3 = 1;
				}
				else
				{
					step3 = 0;
				}
			}
		}
	}

	// After sorting both stacks push back elements in stack B into stack A
	i = 0;
	while (i <= stack_b->size)
	{
		push_a(stack_b, stack_a);
		i++;
	}
	printf(" ******************************************************************\n");
ft_putstr_fd("\n\x1b[1;32m", STDERR_FILENO);
printf("\t\t                               \n");
printf("\t\t           :::      ::::::::   \n");
printf("\t\t         :+:      :+:    :+:   \n");
printf("\t\t       +:+ +:+         +:+     \n");
printf("\t\t     +#+  +:+       +#+        \n");
printf("\t\t   +#+#+#+#+#+   +#+           \n");
printf("\t\t        #+#    #+#             \n");
printf("\t\t       ###   ########.hn  \n");
printf("\x1B[0m\n");
printf(" \n******************************************************************\n");

	printf("Elements in STACK A:\n");
	display(stack_a);
	print_stack(stack_b);
	// system("leaks a.out");
	return 0;
}