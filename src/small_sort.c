/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:02:02 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/26 17:44:09 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_it(t_values **stack_a, t_values **stack_b)
{
	int	low;

	while (stack_a)
	{
		low = lowest_index(*stack_a);
		if (stack_len(*stack_a) == 3)
			break ;
		if (low == top_stack(*stack_a))
			push(stack_a, stack_b, 'b');
		else if (low == bottom_stack(*stack_a))
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	}
}

void	sort_of_3(t_values **stack_a)
{
	int	top;
	int	middle;
	int	last;

	top = top_stack(*stack_a);
	middle = get_index(*stack_a, 1);
	last = bottom_stack(*stack_a);
	if (top > middle && middle < last && top < last)
		swap(stack_a, 'a');
	else if (top > middle && middle > last && top > last)
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (top > middle && middle < last && top > last)
		rotate(stack_a, 'a');
	else if (top < middle && middle > last && top > last)
		reverse_rotate(stack_a, 'a');
	else if (top < middle && middle > last && top < last)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
}

void	sort_of_5(t_values **stack_a, t_values **stack_b)
{
	if (stack_len(*stack_a) == 5)
	{
		sort_it(stack_a, stack_b);
		sort_of_3(stack_a);
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	else
	{
		sort_it(stack_a, stack_b);
		sort_of_3(stack_a);
		push(stack_b, stack_a, 'a');
	}
}
