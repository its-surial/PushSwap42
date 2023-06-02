/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkumar <surkumar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:21:50 by lgollong          #+#    #+#             */
/*   Updated: 2023/05/23 15:51:35 by surkumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	get_index(t_values *mystack, int count)
{
	int	i;

	i = 0;
	if (!mystack)
		return (0);
	while (mystack)
	{
		if (i == count)
			break ;
		mystack = mystack->next;
		i++;
	}
	return (mystack->index);
}

int	get_position(t_values *mystack, int index)
{
	int	i;

	i = 0;
	if (!mystack)
		return (0);
	while (mystack)
	{
		if (mystack->index == index)
			break ;
		mystack = mystack->next;
		i++;
	}
	return (i);
}

int	stack_len(t_values *mystack)
{
	int	i;

	i = 0;
	if (!mystack)
		return (0);
	while (mystack)
	{
		mystack = mystack->next;
		i++;
	}
	return (i);
}

int	sorted(t_values *mystack)
{
	int	tmp1;
	int	tmp2;
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!mystack)
		return (0);
	while (i < stack_len(mystack) && j < stack_len(mystack))
	{
		tmp1 = get_index(mystack, i);
		tmp2 = get_index(mystack, j);
		if (tmp1 < tmp2)
		{
			i++;
			j++;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}
