/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:26:08 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/26 17:10:44 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_sort(t_values **stack_a, t_values **stack_b, int high)
{
	int	sl;
	int	tl;

	tl = high - 2;
	sl = high - 1;
	push(stack_b, stack_a, 'a');
	if (get_index(*stack_a, 1) == sl)
		swap(stack_a, 'a');
	if (bottom_stack(*stack_a) == tl)
		reverse_rotate(stack_a, 'a');
}

void	push_back(t_values **stack_a, t_values **stack_b)
{
	int	mid;
	int	high;

	while (stack_len(*stack_b) >= 1)
	{
		high = biggest_index(*stack_b);
		mid = stack_len(*stack_b) / 2;
		if ((high - 1) == top_stack(*stack_b))
			push(stack_b, stack_a, 'a');
		else if ((high - 2) == top_stack(*stack_b))
		{
			push(stack_b, stack_a, 'a');
			rotate(stack_a, 'a');
		}
		else if (high == top_stack(*stack_b))
			push_sort(stack_a, stack_b, high);
		else if (get_position(*stack_b, high) >= mid)
			reverse_rotate(stack_b, 'b');
		else
			rotate(stack_b, 'b');
	}
}

void	big_sort(t_values **stack_a, t_values **stack_b)
{
	int	length;

	length = stack_len(*stack_a);
	if (length <= 100)
	{
		p_s_chunks(stack_a, stack_b, stack_len(*stack_a), 5);
		last_chunk(stack_a, stack_b);
		push_back(stack_a, stack_b);
	}
	if (length > 100)
	{
		p_m_chunks(stack_a, stack_b, stack_len(*stack_a), 13);
		last_chunk(stack_a, stack_b);
		push_back(stack_a, stack_b);
	}
}
