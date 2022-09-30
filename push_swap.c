/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:58:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/09/30 20:14:04 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insertion_sort_on_b(t_stack	*stack_b, int arr_size)
{
	t_stack_node	*head;
	int				*arr;
	int				median;

	head = stack_b->s_nodes;
	arr = (int *) malloc(sizeof(int) * arr_size);
	// arr = (int *) malloc(sizeof(3));
	if (!arr)
		return 0;
	int	i;

	i = 0;
	while (head != NULL/* && (i < 3) */)
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

	// i = 0;
	/* 
		Printing the sorted array created with insertion sort
	 */
	// printf("Sorted Array:\n");
	// while(i < stack_b->size)
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
	median = arr[arr_size/ 2];
	// free(arr);
	// arr = NULL;
	return median;
}


/* 
	Insertion sort program sorts the numbers in Stack A 
	to realise the median.

	The median value is used to determine which numbers
	for a given chunk should be pushed to Stack B

 */


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
	// arr = (int *) malloc(sizeof(3));
	if (!arr)
		return 0;

	i = 0;
	while (head != NULL/* && (i < 3) */)
	{
		arr[i] = head->item;
		head = head->next;
		i++;
	}

	int step;
    int j;
    int key;

    step = 1;
    while (step < chunk_size) // descending order check
    {
        key = arr[step];
        j = step - 1;
        while (key > arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
			return (0);
        }
        arr[j + 1] = key;
        step++;
    }

	i = 0;
	/* 
		Printing the sorted array created with insertion sort
	 */
	printf("Sorted Array:\n");
	while(i < chunk_size)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	// free(arr);
	// arr = NULL;
	return (1);
}

int	is_ordered(t_queue *stack_a)
{
	t_queue_node	*head;
	int				*arr;
	int				i;

	head = stack_a->front;
	arr = (int *) malloc(sizeof(int) * stack_a->size);
	// arr = (int *) malloc(sizeof(3));
	if (!arr)
		return 0;

	i = 0;
	while (head != NULL/* && (i < 3) */)
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
			return (0);
        }
        arr[j + 1] = key;
        step++;
    }

	// i = 0;
	/* 
		Printing the sorted array created with insertion sort
	 */
	// printf("Sorted Array:\n");
	// while(i < stack_a->size)
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
	// free(arr);
	// arr = NULL;
	return (1);
}

int	insertion_sort(t_queue	*stack_a)
{
	t_queue_node	*head;
	int				*arr;
	int				median;

	head = stack_a->front;
	arr = (int *) malloc(sizeof(int) * stack_a->size);
	// arr = (int *) malloc(sizeof(3));
	if (!arr)
		return 0;
	int	i;

	i = 0;
	while (head != NULL/* && (i < 3) */)
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

	// i = 0;
	/* 
		Printing the sorted array created with insertion sort
	 */
	// printf("Sorted Array:\n");
	// while(i < stack_a->size)
	// {
	// 	printf("%d\n", arr[i]);
	// 	i++;
	// }
	median = arr[stack_a->size/ 2];
	// free(arr);
	// arr = NULL;
	return median;
}


/*
	Algorithm to sort Array of numbers goes here
*/
 
 /// int				first_num_position;
// int				second_num_position;
// int				num_position;
// int				move_couts;
// t_queue_node	*head;

// -1 2 3 4 10 11 12 13 14 15

void	stack_b_has_two(t_queue *stack_a, t_stack *stack_b)
{
	int	k;

	k = 0;
	if (is_chunk_ordered(stack_b, 2))
	{
		printf("Chunk is ordered\n");
		while (k < 2)
		{
			printf("Total elements in 1 chunk %d\n", 2);
			push_a(stack_b, stack_a);
			k++;
		}
	}
	else
	{
		swap_b(stack_b);
		while (k < 2)
		{
			push_a(stack_b, stack_a);
			k++;
		}
		printf("Size of stack B is: %d\n", stack_b->size);
	}
}
void	stack_b_has_three(t_queue *stack_a, t_stack *stack_b)
{
	int	median;
	int	k;

	k = 0;
	median = insertion_sort_on_b(stack_b, 3);
	if (!is_chunk_ordered(stack_b, 3))
	{
		if (stack_b->s_nodes->item == median)
		{
			if (stack_b->s_nodes->next->item > median)
				swap_b(stack_b);
			else
				rrotate_b(stack_b);
			while (k < stack_b->size)
			{
				push_a(stack_b, stack_a);
				k++;
			}
		}
		else if (stack_b->s_nodes->item < median)
		{
			rotate_b(stack_b);
			if (stack_b->s_nodes->item == median)
				swap_b(stack_b);
			while (k < stack_b->size)
			{
				push_a(stack_b, stack_a);
				k++;
			}
		}
		else
		{
			push_a(stack_b, stack_a);
			swap_b(stack_b);
			while (k < stack_b->size)
			{
				push_a(stack_b, stack_a);
				k++;
			}
		}
	}
	else
	{
		while (k < stack_b->size)
		{
			push_a(stack_b, stack_a);
			k++;
		}
	}
}
void	move_chunks_to_b(t_queue *stack_a, t_stack *stack_b)
{
	int		median;
	t_queue_node *head_a;
	int head_a_moves;

	
	median = insertion_sort(stack_a);
	head_a = stack_a->front;
	head_a_moves = 0;

	while (head_a)
	{
		if (head_a->item < median)
		{
			while (head_a_moves > 0)
			{
				rotate_a(stack_a);
				head_a_moves--;
			}
			push_b(stack_a, stack_b);
			head_a_moves = -1;
		}
		head_a = head_a->next;
		head_a_moves++;
	}
}
void	stack_b_has_chunks()
{
	
}

void	move_chunks_to_a(t_stack *stack_b, t_queue *stack_a, t_chunks **chunks, int total_chunks)
{
	int	median;

	print_stack(stack_b);
	if (stack_b->size <= 2)
	{
		printf("\nSorting stack B having only 2 or less items\n");
		stack_b_has_two(stack_a, stack_b);
	}
	if (stack_b->size == 3)
	{
		printf("\nSort ing stack B having only 3 items\n");
		stack_b_has_three(stack_a, stack_b);
	}
	if (stack_b->size > 3)
	{
		printf("\nSorting stack B having chunks\n");
		printf("Total chunks: %d\n", total_chunks);
		while (total_chunks > 0)
		{
			median = insertion_sort_on_b(stack_b, chunks[total_chunks - 1]->data);
			int chunk_size = chunks[total_chunks - 1]->data;
			if (is_chunk_ordered(stack_b, chunk_size))
			{
				while (chunk_size > 0)
				{
					push_a(stack_b, stack_a);
					chunk_size--;
				}
			}
			else
			{
				printf("Chunk size is: %d\n\n", chunk_size);
				if (chunk_size <= 2)
				{
					stack_b_has_two(stack_a, stack_b);
				}
				else if (chunk_size == 3)
				{
					stack_b_has_three(stack_a, stack_b);
				}
				else
				{
					printf("Chunk size is large\n");
					print_stack(stack_b);
					t_stack_node	*head_b;
					int				rotations;
					int				head_b_moves;
					int				temp;
					int				push_to_a_state;
					int				pushed_items_count;

					pushed_items_count = 0;
					head_b = stack_b->s_nodes;
					head_b_moves = 0;
					rotations = 0;
					while (chunks[total_chunks - 1]->data > 0)
					{
						push_to_a_state = 0;
						printf("Head b item is: %d\n", head_b->item);
						if (head_b->item < median && pushed_items_count < median + 1 && stack_b->s_nodes->item < median)
						{
							rotations++;
							printf("Rotations: %d\n", rotations);
						}
						if (head_b->item < median && pushed_items_count >= median + 1
							&& chunks[total_chunks - 1]->data > 1)
						{
							if (head_b->item < head_b->next->item)
							{
								if (head_b_moves > 0)
								{
									rotations += head_b_moves;
								}
							}
						}
						if (head_b->item > median)
						{
							temp = head_b->item;
							if (temp < head_b->next->item)
							{
								temp = head_b->next->item;
								rotations += head_b_moves;
							}
						}
						if (head_b->item == median && pushed_items_count == median)
						{
							int	temp_rotations = rotations;
							while (temp_rotations > 0)
							{
								rotate_b(stack_b);
								temp_rotations--;
							}
							push_a(stack_b, stack_a);
							chunks[total_chunks - 1]->data--;
							pushed_items_count++;
							while (rotations > 0)
							{
								rrotate_b(stack_b);
								rotations--;
							}
							head_b = stack_b->s_nodes;
							push_to_a_state = 1;
							head_b_moves = 0;
						}
						if (head_b_moves == (chunks[total_chunks - 1]->data - 1))
						{
							int	temp_rotations = rotations;
							while (temp_rotations > 0)
							{
								rotate_b(stack_b);
								temp_rotations--;
							}
							push_a(stack_b, stack_a);
							chunks[total_chunks - 1]->data--;
							pushed_items_count++;
							while (rotations > 0)
							{
								rrotate_b(stack_b);
								rotations--;
							}
							head_b = stack_b->s_nodes;
							push_to_a_state = 1;
							head_b_moves = 0;
						}
						if (!push_to_a_state)
						{
							head_b = head_b->next;
							head_b_moves++;
						}
					}
				}
			}
			total_chunks--;
		}
		
		
	}
}

t_chunks	*get_chunk_set(t_queue *stack_a, int set_count)
{
	t_chunks	*set;

	set = (t_chunks *)malloc(sizeof(t_chunks));
	set->data = stack_a->size / 2;
	set->key = set_count;

	return set;
}

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

	/* 
		Fun Message
	 */
/* 	ft_putstr_fd("\n\n\x1b[1;32m", STDERR_FILENO);
	ft_putstr_fd("Hurray!! No errors, at least for now.", STDERR_FILENO);
	printf("\x1B[0m\n\n\n"); */


/* 
	Show the stack before the algorithm to sort it is applied
 */
/* 

	display(stack_a);
	printf("Size of stack A: %d\n", stack_a->size);
	printf("Least Element of stack A: %d\n", stack_a->least_item);

	15 / 2 => 8 items left in stack A
	8 / 2  => 4 items left in stack A
	4 / 2 =>  2 items left in stack A
*/
	printf("%d : returned val from ordered\n", is_ordered(stack_a));
	t_chunks	**chunks;
	t_chunks	*set;
	int			total_chunks;
	int			stack_size;

	total_chunks = 0;
	stack_size = stack_a->size;
	while (stack_size > 3)
	{
		stack_size = stack_size - (stack_size >> 1);
		total_chunks++;
	}
	printf("Total chunks to create: %d\n", total_chunks);
	// exit(0);
	set = (t_chunks *)malloc(sizeof(t_chunks));
	chunks = (t_chunks **)malloc(sizeof(set) * total_chunks);
	if (!chunks || !set)
		return 0;
	if (is_ordered(stack_a))
	{
		printf("Stack A is already ordered\n");
		return 0;
	}
	else
	{
		int set_count = 0;
		while (stack_a->size > 3)
		{
			// set->data = stack_a->size / 2;
			// set->key = set_count;
			chunks[set_count] = get_chunk_set(stack_a, set_count);
			move_chunks_to_b(stack_a, stack_b);
			set_count++;
		}

		i = 0;
		while (i < total_chunks)
		{
			printf("Chunk index %d  ", chunks[i]->key);
			printf("size of chunk: %d\n",chunks[i]->data);
			i++;
		}
		if (is_ordered(stack_a))
		{
			printf("After moving items to stack B\n");
			printf("Size of stack A is: %d\n", stack_a->size);
			printf("Stack A is ordered\n");
		}
		else
		{
			printf("After moving items to stack B\n");
			printf("Size of stack A is: %d\n", stack_a->size);
			printf("Stack A is not ordered! Do ordering\n");
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
				if (!is_ordered(stack_a))
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
					printf("Size of stack A is: %d\n", stack_a->size);
					printf("Stack A is not ordered! Do ordering\n");
				}
			}
		}
		// Displays the two stacks A and B after creating chunks in B
		// display(stack_a);
		// print_stack(stack_b);
		if (stack_b->size > 0)
			printf("---------Moving items back to A--------\n");
		while (stack_b->size > 0)
		{
			move_chunks_to_a(stack_b, stack_a, chunks, total_chunks);
		}
		// while (stack_b->size != 0)
		// {
		// 	rrotate_b(stack_b);
		// 	push_a(stack_b, stack_a);
		// }
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


/* 
	Show the Stacks After applying the sorting algorithm
 */

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
	// system("leaks a.out");
	return 0;
}
