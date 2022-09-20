/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:58:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/09/20 17:13:37 by bogunlan         ###   ########.fr       */
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
		// system("leaks a.out");
		return 0;
	}
	ft_putstr_fd("\n\n\x1b[1;32m", STDERR_FILENO);
	ft_putstr_fd("Hurray!! No errors, at least for now.", STDERR_FILENO);
	printf("\x1B[0m\n\n\n");



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

	display(stack_a);
	printf("Size of stack A: %d\n", stack_a->size);
	printf("Least Element of stack A: %d\n", stack_a->least_item);
	// Algorithm to sort Array of numbers goes here
	int				first_num_position;
	int				second_num_position;
	int				num_position;
	int				move_couts;
	t_queue_node	*head;
	// int				median;


	head = stack_a->front;
	first_num_position = 0;
	second_num_position = 0;
	num_position = 0;
	move_couts = 0;
	
	if (stack_a->size >= 10 && stack_a->size <= 100)
	{
		int	*chunks;

		chunks = (int *) malloc(stack_a->size / 4);
	}
	while (head)
	{
		// median = stack_a->size / 2;
		if (head->item >= stack_a->least_item
			&& head->item <= stack_a->least_item + 4
			)
		{
			// if (!first_num_position)
			// {
				// first_num_position = num_position;
				// head = head->next;
				// while (head)
				// {
				// 	num_position++;
				// 	if (head->item >= stack_a->least_item
				// 	&& head->item <= stack_a->least_item + 4
				// 	)
				// 	{
				// 		second_num_position = num_position;
				// 		break ;
				// 	}
				// 	head = head->next;
				// }
			// }
			if (first_num_position)
			{
				second_num_position = num_position;
				if (first_num_position > (stack_a->size - second_num_position + 1))
				{
					int	repeat = stack_a->size - second_num_position + 1;
					int	rr_count = 0;
					while (rr_count < repeat)
					{
						rrotate_a(stack_a);
						rr_count++;
						move_couts++;
					}
					push_b(stack_a, stack_b);
					move_couts++;
				}
				else if (first_num_position < (stack_a->size - second_num_position + 1))
				{
					int	repeat = first_num_position;
					int	r_count = 0;
					while (r_count < repeat)
					{
						rotate_a(stack_a);
						r_count++;
						move_couts++;
					}
					push_b(stack_a, stack_b);
					move_couts++;
				}
				else if (first_num_position == (stack_a->size - second_num_position + 1)
						&& first_num_position <= 1
				)
				{
					swap_a(stack_a);
					push_b(stack_a, stack_b);
					int	repeat = first_num_position;
					int	rr_count = 0;
					while (rr_count < repeat)
					{
						rrotate_a(stack_a);
						rr_count++;
						move_couts++;
					}
					push_b(stack_a, stack_b);
					move_couts += 2;
				}
				else
				{
					int	repeat = first_num_position;
					int	r_count = 0;
					while (r_count < repeat)
					{
						rotate_a(stack_a);
						r_count++;
						move_couts++;
					}
					push_b(stack_a, stack_b);
					move_couts++;
				}
				printf("Element in front of stack A is now: %d\n", stack_a->front->item);
				first_num_position = second_num_position - move_couts;
				num_position = first_num_position - 1;
				move_couts = 0;
				break ;
			}
			if (!first_num_position && !second_num_position)
			{
				first_num_position = num_position;
			}
		}
		num_position++;
		head = head->next;
	}
	printf("head is at position: %d\n", num_position);
	printf("First number is at position: %d\n", first_num_position);
	printf("Second num is at position: %d\n", second_num_position);
	

	ft_putstr_fd("\n\x1b[1;33m", STDERR_FILENO);
	printf("\nAfter applying sorting algorithm, We've got:\x1B[0m\n");
	display(stack_a);
	print_stack(stack_b);
	// system("leaks a.out");
	return 0;
}
