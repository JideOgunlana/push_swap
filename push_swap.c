/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:58:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/09/16 00:31:47 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_passed_vals(char *str)
{
	int	i;

	printf("string: %s\n", str);
	i = 0;
	if (str[i] == 0) // can be compared to '\0' as well
		return (1);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && !ft_atoi(&str[i]))
			return (1);
		i++;
	}
	return 0;
}

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
						ft_putstr_fd("Contains value that is not a number", STDERR_FILENO);
						// need to free splitted vals;
						ft_free(split);
						system("leaks a.out");
						return 0;
					}
					j++;
				}
			}
			else if (check_passed_vals(argv[i]))
			{
				ft_putstr_fd("Contains value that is not a number", STDERR_FILENO);
				// free nodes in stack_a too before freeing the queue
				// but I think it's not needed here as the program exits succesfully and frees the memory itself
				// free(stack_a);
				// system("leaks a.out");
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
				ft_free(split);
				split = NULL;
			}
			else
				enqueue(stack_a, ft_atoi(argv[i]));
			i++;
		}
	}
	ft_putstr_fd("Items in queue\n", STDOUT_FILENO);
	display(stack_a);
	// swap_a(stack_a);
	// rotate_a(stack_a);
	// printf("________________________ After swap_a fxn and rotate() call ____________________\n\n");
	// display(stack_a);
	// push_b(stack_a, stack_b);
	// push_b(stack_a, stack_b);
	// push_b(stack_a, stack_b);
	// push_b(stack_a, stack_b);
	// printf("________________________ Second stack ____________________\n\n");
	// print_stack(stack_b);
	// printf("________________________ Pushing back to stack a ________________\n\n");
	// push_a(stack_b, stack_a);
	// display(stack_a);
	// print_stack(stack_b);
	// rrotate_b(stack_b);
	// printf("________________________ After rotate_b() ________________\n\n");
	// print_stack(stack_b);

	// printf("________________________ After reversing both a and b ________________\n\n");
	// reverse_a_b(stack_a, stack_b);
	// display(stack_a);
	// print_stack(stack_b);
	// swap_a_b(stack_a, stack_b);
	// printf("________________________ After swap_a () and swap_b() ________________\n\n");
	// display(stack_a);
	// print_stack(stack_b);


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