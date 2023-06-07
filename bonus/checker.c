/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:36:50 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/11 11:55:21 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	invalid_instruction(void)
{
	ft_putstr_fd("\x1b[1;31m", STDOUT_FILENO);
	ft_putstr_fd("Error", STDOUT_FILENO);
	ft_putstr_fd("\x1B[0m\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}

void	read_instruction(t_stacks *s, char *line)
{
	if (ft_strncmp(line, "pa\n", 4) == 0)
		push_a(s->stack_b, s->stack_a);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		push_b(s->stack_a, s->stack_b);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		swap_a(s->stack_a);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		swap_b(s->stack_b);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		swap_a_b(s->stack_a, s->stack_b);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		rotate_a(s->stack_a);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		rotate_b(s->stack_b);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		rotate_a_b(s->stack_a, s->stack_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rrotate_a(s->stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrotate_b(s->stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		reverse_a_b(s->stack_a, s->stack_b);
	else
		invalid_instruction();
}

void	checker_init_stacks(t_stacks *stacks)
{
	stacks->stack_a = (t_queue *) malloc(sizeof(t_queue));
	stacks->stack_b = (t_stack *) malloc(sizeof(t_stack));
	if (!stacks->stack_a || !stacks->stack_b)
		exit(EXIT_SUCCESS);
	stacks->stack_a->size = 0;
	stacks->stack_b->size = 0;
	stacks->stack_a->no_print = 1;
	stacks->stack_b->no_print = 1;
}

void	checker(t_stacks *stacks, char *line)
{
	while (line)
	{
		if (ft_strncmp(line, "\n", 2) == 0)
		{
			if (stacks->stack_b->size > 0)
			{
				checker_err_mess();
				exit(EXIT_SUCCESS);
			}
			is_stack_sorted(stacks);
			free(line);
			checker_clean_up(stacks);
			exit(EXIT_SUCCESS);
		}
		read_instruction(stacks, line);
		free(line);
		line = get_next_line(0);
	}
	is_stack_sorted(stacks);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	char		*line;

	if (argc < 2)
		return (EXIT_SUCCESS);
	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
		return (EXIT_SUCCESS);
	checker_init_stacks(stacks);
	parse_args(stacks, argc, argv);
	line = get_next_line(0);
	checker(stacks, line);
	checker_clean_up(stacks);
	return (EXIT_SUCCESS);
}
