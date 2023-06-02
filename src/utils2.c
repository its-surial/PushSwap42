/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:04:02 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/26 17:44:34 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	biggest_index(t_values *mystack)
{
	int	i;
	int	big;
	int	index;

	big = 0;
	i = 0;
	while (i < stack_len(mystack))
	{
		index = get_index(mystack, i);
		if (index > big)
			big = index;
		i++;
	}
	return (big);
}

int	lowest_index(t_values *mystack)
{
	int	i;
	int	low;
	int	index;

	i = 0;
	low = biggest_index(mystack);
	while (i < stack_len(mystack))
	{
		index = get_index(mystack, i);
		if (index < low)
			low = index;
		i++;
	}
	return (low);
}

int	top_stack(t_values *mystack)
{
	if (mystack)
		return (mystack->index);
	return (0);
}

int	bottom_stack(t_values *mystack)
{
	if (!mystack)
		return (0);
	while (mystack->next)
	{
		mystack = mystack->next;
	}
	return (mystack->index);
}
