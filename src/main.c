/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkumar <surkumar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:21:17 by surkumar          #+#    #+#             */
/*   Updated: 2023/06/02 17:09:08 by surkumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_values	*stack_a;
	t_values	*stack_b;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	get_data(&stack_a, argc, argv);
	set_index(stack_a);
	sort_stack(&stack_a, &stack_b);
	clear_data(&stack_a, &stack_b);
	return (0);
}
