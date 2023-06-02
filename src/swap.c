/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:56:09 by lgollong          #+#    #+#             */
/*   Updated: 2022/08/02 19:34:25 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap_it(t_values **mystack)
{
	int	tmp;

	if (!*mystack)
		return ;
	if (stack_len(*mystack) == 1)
		return ;
	tmp = (*mystack)->index;
	(*mystack)->index = (*mystack)->next->index;
	(*mystack)->next->index = tmp;
}

void	swap(t_values **mystack, char s)
{
	swap_it(mystack);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(s, 1);
	ft_putchar_fd('\n', 1);
}

void	s_both(t_values **stack_a, t_values **stack_b)
{
	swap_it(stack_a);
	swap_it(stack_b);
	ft_putstr_fd("ss\n", 1);
}
