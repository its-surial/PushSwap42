/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 09:58:10 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/28 11:04:13 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	give_index(t_values **mystack, t_values *value)
{
	t_values	*cmp;

	cmp = *mystack;
	value->index = 1;
	while (cmp)
	{
		if (value->value > cmp->value)
			value->index++;
		cmp = cmp->next;
	}
}

void	set_index(t_values *mystack)
{
	t_values	*value;

	value = mystack;
	while (value)
	{
		give_index(&mystack, value);
		value = value->next;
	}
}

void	clear_data(t_values **stack_a, t_values **stack_b)
{
	t_values	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}
	}
	if (*stack_b)
	{
		tmp = *stack_b;
		if (!tmp)
			return ;
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}
	}
}

void	split_it(t_values **mystack, char **argv, int i)
{
	char	**strs;
	int		j;
	int		num;

	j = 0;
	strs = ft_split(argv[i], ' ');
	j = arg_len(strs) - 1;
	while (j >= 0)
	{
		num = ft_atoi(strs[j]);
		push_to_stack(mystack, num);
		free(strs[j]);
		j--;
	}
	free(strs);
}

void	get_data(t_values **mystack, int argc, char **argv)
{
	int			i;
	int			num;

	i = argc - 1;
	while (i > 0)
	{
		if (contains_char(argv[i]))
			error();
		if (space(argv[i]))
			split_it(mystack, argv, i);
		else
		{
			num = ft_atoi(argv[i]);
			push_to_stack(mystack, num);
		}
		i--;
	}
	check_data(*mystack);
}
