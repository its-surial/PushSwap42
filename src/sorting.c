/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:08:02 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/26 17:44:18 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_stack(t_values **stack_a, t_values **stack_b)
{
	int	length;

	length = stack_len(*stack_a);
	if (length == 1)
		return ;
	if (sorted(*stack_a))
		return ;
	else if (length == 2)
		swap(stack_a, 'a');
	else if (length == 3)
		sort_of_3(stack_a);
	else if (length == 4 || length == 5)
		sort_of_5(stack_a, stack_b);
	else if (length > 5)
		big_sort(stack_a, stack_b);
}
