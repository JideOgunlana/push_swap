/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:03:28 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/07 18:02:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Analyze arguments passed
	If there are no Errors, create chunks and sort the numbers
*/
int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	t_pswap		*pswap;

	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	pswap = (t_pswap *) malloc(sizeof(t_pswap));
	if (!stacks || !pswap)
		return (0);
	if (argc < 2)
	{
		ft_putstr_fd("Usage: ./push_swap ARGS\n", STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	if (!init_stacks(stacks))
		return (EXIT_SUCCESS);
	parse_args(stacks, argc, argv);
	push_swap(stacks, pswap);
	clean_up(stacks, pswap);
	return (EXIT_SUCCESS);
}
