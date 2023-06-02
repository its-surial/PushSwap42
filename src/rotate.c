/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkumar <surkumar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:39:30 by lgollong          #+#    #+#             */
/*   Updated: 2023/05/16 16:37:31 by surkumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rotate_it(t_values **mystack)
{
	t_values	*tmp;
	int			head;

	if (!*mystack)
		return ;
	tmp = *mystack;
	head = tmp->index;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next != NULL)
	{
		tmp->index = tmp->next->index;
		tmp = tmp->next;
	}
	tmp->index = head;
}

void	rotate(t_values **mystack, char s)
{
	rotate_it(mystack);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(s, 1);
	ft_putchar_fd('\n', 1);
}

void	r_both(t_values **stack_a, t_values **stack_b)
{
	rotate_it(stack_a);
	rotate_it(stack_b);
	ft_putstr_fd("rr\n", 1);
}
