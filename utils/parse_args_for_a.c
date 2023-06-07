/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_for_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:07:58 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/08 18:42:18 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
	Check for a value that is not an integer
 */
void	check_split_arg(t_stacks *stacks)
{
	int	j;

	j = 0;
	while (stacks->split[j] != NULL)
	{
		if (check_invalid_vals(stacks->split[j]))
		{
			error_message();
			ft_free(stacks->split);
			exit(0);
		}
		j++;
	}
}

void	check_arg(t_stacks *stacks, char *argv[])
{
	if (stacks->split)
		check_split_arg(stacks);
	else if (check_invalid_vals(argv[stacks->i]))
	{
		error_message();
		free(stacks->stack_a);
		exit(0);
	}
}

/* 
	put values into stack A
 */
void	enqueue_stack_a(t_stacks *stacks)
{
	if (stacks->split)
	{
		check_split_arg_is_int(stacks);
		stacks->split = ft_free(stacks->split);
	}
	else
		check_arg_is_int(stacks);
}

/* 
	Check numbers are in INT range
 */
void	check_split_arg_is_int(t_stacks *stacks)
{
	int	j;

	j = 0;
	while (stacks->split[j] != NULL)
	{
		stacks->ret_val = ft_atoi(stacks->split[j]);
		if (stacks->ret_val < INT32_MIN || stacks->ret_val > INT32_MAX)
		{
			error_message();
			exit(0);
		}
		enqueue(stacks->stack_a, stacks->ret_val);
		j++;
	}
}

void	check_arg_is_int(t_stacks *stacks)
{
	int	j;

	j = 0;
	stacks->ret_val = ft_atoi(stacks->split[j]);
	if (stacks->ret_val < INT32_MIN || stacks->ret_val > INT32_MAX)
	{
		error_message();
		exit(0);
	}
	enqueue(stacks->stack_a, stacks->ret_val);
}
