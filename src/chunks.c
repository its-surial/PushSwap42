/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkumar <surkumar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:10:14 by lgollong          #+#    #+#             */
/*   Updated: 2023/06/02 00:21:32 by surkumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	last_chunk(t_values **stack_a, t_values **stack_b)
{
	int	mid;
	int	low;

	while (stack_len(*stack_a) >= 2)
	{
		low = lowest_index(*stack_a);
		if (low == top_stack(*stack_a))
			push(stack_a, stack_b, 'b');
		mid = stack_len(*stack_a) / 2;
		if (get_position(*stack_a, low) < mid)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
}

void	p_m_chunks(t_values **stack_a, t_values **stack_b, int s_len, int len)
{
	int		chunk;
	int		tmp1;
	int		tmp2;
	int		i;

	i = 1;
	chunk = (s_len / len) * 2;
	tmp1 = chunk;
	tmp2 = tmp1 / 2;
	while (chunk < s_len - tmp2)
	{
		while (i <= chunk)
		{
			if (top_stack(*stack_a) <= chunk)
			{
				push(stack_a, stack_b, 'b');
				if (top_stack(*stack_b) <= chunk - tmp2)
					rotate(stack_b, 'b');
				i++;
			}
			else
				rotate(stack_a, 'a');
		}
		chunk += tmp1;
	}
}

void	p_s_chunks(t_values **stack_a, t_values **stack_b, int s_len, int len)
{
	int		chunk;
	int		tmp;
	int		i;

	i = 1;
	chunk = s_len / len;
	tmp = chunk;
	chunk += tmp;
	while (chunk < s_len)
	{
		while (i <= chunk)
		{
			if (top_stack(*stack_a) <= chunk)
			{
				push(stack_a, stack_b, 'b');
				if (top_stack(*stack_b) <= chunk - tmp)
					rotate(stack_b, 'b');
				i++;
			}
			else
				rotate(stack_a, 'a');
		}
		chunk += tmp;
	}
}
