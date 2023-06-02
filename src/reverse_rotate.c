/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:51:17 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/26 19:20:27 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	reverse_rotate_it(t_values **mystack)
{
	t_values	*first;
	t_values	*back;
	t_values	*head;

	first = *mystack;
	back = *mystack;
	head = *mystack;
	if (!*mystack)
		return ;
	while (first->next != NULL)
	{
		first = first->next;
		if (first->next != NULL)
			back = back->next;
	}
	if (first->next == NULL)
	{
		first->next = head;
		back->next = NULL;
	}
	*mystack = first;
}

void	reverse_rotate(t_values **mystack, char s)
{
	reverse_rotate_it(mystack);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(s, 1);
	ft_putchar_fd('\n', 1);
}

void	rr_both(t_values **stack_a, t_values **stack_b)
{
	reverse_rotate_it(stack_a);
	reverse_rotate_it(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
