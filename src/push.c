/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkumar <surkumar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:09:46 by lgollong          #+#    #+#             */
/*   Updated: 2023/05/22 20:27:46 by surkumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_it(t_values **src, t_values **dest)
{
	t_values	*tmp;
	t_values	*item;

	if (!*src)
		return ;
	item = (*src)->next;
	tmp = *src;
	tmp->next = *dest;
	*dest = tmp;
	*src = item;
}

void	push(t_values **src, t_values **dest, char s)
{
	push_it(src, dest);
	ft_putchar_fd('p', 1);
	ft_putchar_fd(s, 1);
	ft_putchar_fd('\n', 1);
}
