/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:03:28 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/06 15:45:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *  Analyze arguments passed.
 *	If there are no errors, sort the numbers passed.
 *	Before the program exits, deallocate all memory used.
*/
int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	t_pswap		*pswap;

	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	pswap = (t_pswap *) malloc(sizeof(t_pswap));
	if (!stacks || !pswap)
		return (EXIT_SUCCESS);
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (!init_stacks(stacks))
		return (EXIT_SUCCESS);
	parse_args(stacks, argc, argv);
	push_swap(stacks, pswap);
	clean_up(stacks, pswap);
	return (EXIT_SUCCESS);
}
