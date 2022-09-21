/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:58:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/09/21 21:45:10 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insertion_sort(t_queue	*stack_a)
{
	t_queue_node	*head;
	int				*arr;
	int				median;

	head = stack_a->front;
	arr = (int *) malloc(sizeof(stack_a->size));
	// arr = (int *) malloc(sizeof(3));
	if (!arr)
		return 0;
	int	i;

	i = 0;
	while (head /* && (i < 3) */)
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

	i = 0;
	printf("Sorted Array:\n");
	while(i < stack_a->size)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	median = arr[stack_a->size/ 2];
	free(arr);
	return median;
}


int	insertion_sort_on_b(t_stack	*stack_b)
{
	t_stack_node	*head;
	int				*arr;
	int				median;

	head = stack_b->s_nodes;
	// arr = (int *) malloc(sizeof(stack_b->size));
	arr = (int *) malloc(sizeof(3));
	if (!arr)
		return 0;
	int	i;

	i = 0;
	while (head && (i < 3))
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}

	int step;
    int j;
    int key;

    step = 1;
    while (step < 3)
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

	i = 0;
	printf("Sorted Array:\n");
	while(i < 3)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	median = arr[3 / 2];
	free(arr);
	return median;
}



// 
int main(int argc, char *argv[])
{
	t_queue	*stack_a;
	t_stack	*stack_b;
	char	**split;
	int		i;
	int		j;
	int		median;

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
	// int				first_num_position;
	// int				second_num_position;
	// int				num_position;
	// int				move_couts;
	// t_queue_node	*head;
	median = insertion_sort(stack_a);
	t_queue_node *head;
	head = stack_a->front;
	int head_moves = 0;
	// int	found_val = 0;
	while (head)
	{
		if (head->item < median)
		{
			while (head_moves > 0)
			{
				rotate_a(stack_a);
				head_moves--;
			}
			push_b(stack_a, stack_b);
			head_moves = -1;
		}
		head = head->next;
		head_moves++;
	}
	// while(stack_a->size > 3)
	// {
	// 	median = insertion_sort(stack_a);
	// 	if (stack_a->front->item < median)
	// 	{
	// 		push_b(stack_a, stack_b);
	// 	}
	// 	else
	// 	{
	// 		rotate_a(stack_a);
	// 	}
	// }
	// printf("Median value: %d\n", median); 

	

	ft_putstr_fd("\n\x1b[1;33m", STDERR_FILENO);
	printf("\nAfter applying sorting algorithm, We've got:\x1B[0m\n");
	display(stack_a);
	print_stack(stack_b);
	// while(stack_b->size > 3)
	// {
	// 	median = insertion_sort_on_b(stack_b);
	// 	if (stack_b->s_nodes->item > median)
	// 	{
	// 		push_a(stack_b, stack_a);
	// 	}
	// 	else
	// 	{
	// 		rotate_b(stack_b);
	// 	}
	// }

	// display(stack_a);
	// print_stack(stack_b);
	system("leaks a.out");
	return 0;
}
