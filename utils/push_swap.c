/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:58:27 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/09 01:10:30 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parse_args(t_stacks *stacks, int argc, char *argv[])
{
	stacks->i = 1;
	while (stacks->i < argc)
	{
		if (ft_strlen(argv[stacks->i]) > 0)
		{
			stacks->split = ft_split(argv[stacks->i], ' ');
		}
		check_arg(stacks, argv);
		enqueue_stack_a(stacks);
		stacks->i++;
	}
	if (check_duplicates(stacks->stack_a))
	{
		error_message();
		exit(EXIT_SUCCESS);
	}
}

int	init_stacks(t_stacks *stacks)
{
	stacks->stack_a = (t_queue *) malloc(sizeof(t_queue));
	stacks->stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stacks->stack_a || !stacks->stack_b)
		return (0);
	init_stack_a(stacks->stack_a);
	init_stack_b(stacks->stack_b);
	stacks->split = NULL;
	return (1);
}

void	push_swap(t_stacks *stacks, t_pswap *pswap)
{
	if (stacks->stack_a->size == 500)
	{
		get_t_chks_xl(stacks, pswap);
		init_temp_stack(pswap);
		is_sort_needed_xl(stacks, pswap);
	}
	else if (stacks->stack_a->size == 100)
	{
		get_t_chks_l(stacks, pswap);
		init_temp_stack(pswap);
		is_sort_needed_l(stacks, pswap);
	}
	else
	{
		get_t_chks(stacks, pswap);
		init_temp_stack(pswap);
		is_sort_needed(stacks, pswap);
	}
}

void	clean_up(t_stacks *stacks, t_pswap *pswap)
{
	int				i;
	t_queue_node	*temp;

	i = 0;
	while (stacks->stack_a->front)
	{
		temp = stacks->stack_a->front;
		stacks->stack_a->front = stacks->stack_a->front->next;
		free(temp);
	}
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
	free(pswap->set);
	while (i < pswap->set_count)
	{
		free(pswap->chunks[i]);
		i++;
	}
	free(pswap->chunks);
	free(pswap);
}
