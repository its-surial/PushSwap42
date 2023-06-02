/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:43:39 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/28 11:02:49 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	str_check(const char *str)
{
	char	*tmp;
	int		sign;

	sign = 0;
	tmp = (char *)str;
	if (*tmp == '-')
		sign = 1;
	if (*tmp == '-' || *tmp == '+')
		tmp++;
	if (ft_strlen(tmp) > 10 || ft_strlen(tmp) == 0)
		return (1);
	if (ft_strlen(tmp) == 10 && sign == 1 && ft_strcmp(tmp, "2147483648") > 0)
		return (1);
	if (ft_strlen(tmp) == 10 && sign == 0 && ft_strcmp(tmp, "2147483647") > 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *strn)
{
	int	i;
	int	nbr;
	int	sol;

	i = 0;
	nbr = 1;
	sol = 0;
	if (str_check(strn))
		error();
	while (strn[i] == ' ' || strn[i] == '\t' || strn[i] == '\n'
		|| strn[i] == '\r' || strn[i] == '\f' || strn[i] == '\v')
		i++;
	if (strn[i] == '+' || strn[i] == '-')
	{
		if (strn[i] == '-')
			nbr *= -1;
		i++;
	}
	while (strn[i] > 47 && strn[i] < 58)
	{
		sol = sol * 10 + (strn[i] - '0');
		i++;
	}
	return (nbr * sol);
}
