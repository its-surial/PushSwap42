/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:31:21 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/28 11:00:45 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_to_stack(t_values **mystack, int value)
{
	t_values	*newnode;

	newnode = (t_values *)malloc(sizeof(t_values));
	if (!newnode)
		return ;
	newnode->value = value;
	newnode->next = *mystack;
	*mystack = newnode;
}

void	check_data(t_values *mystack)
{
	t_values	*tmp1;
	t_values	*tmp2;
	int			check;

	tmp1 = mystack;
	while (tmp1)
	{
		check = 0;
		tmp2 = tmp1;
		while (tmp2)
		{
			if (tmp2->value == tmp1->value)
			{
				check++;
				if (check >= 2)
					error();
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	contains_char(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] > 47 && str[i] < 58)))
			return (1);
		i++;
	}
	return (0);
}

int	arg_len(char **strs)
{
	int	i;

	if (!strs)
		return (0);
	i = 0;
	while (i[strs])
		i++;
	return (i);
}

int	space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
