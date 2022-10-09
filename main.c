/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:03:28 by bogunlan          #+#    #+#             */
/*   Updated: 2022/10/08 23:04:01 by bogunlan         ###   ########.fr       */
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
		return (EXIT_SUCCESS);
	if (!init_stacks(stacks))
		return (EXIT_SUCCESS);
	parse_args(stacks, argc, argv);
	push_swap(stacks, pswap);
	// Show the Stacks After applying the sorting algorithm
/* 
	ft_putstr_fd("\n\x1b[1;33m", STDERR_FILENO);
	printf("\nAfter applying sorting algorithm, We've got:\x1B[0m\n");
	display(stacks->stack_a);
 */
	// clean up used memory
	clean_up(stacks, pswap);
	// system("leaks push_swap");
	return (EXIT_SUCCESS);
}