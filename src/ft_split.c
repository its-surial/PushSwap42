/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:25:26 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/12 11:11:43 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

unsigned int	ft_word_count(char const *s, char c)
{
	unsigned int	counter;
	unsigned int	i;
	unsigned int	j;

	counter = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && j == 0)
		{
			counter++;
			j = 1;
		}
		else if (s[i] == c)
			j = 0;
		i++;
	}
	return (counter);
}

unsigned int	ft_letter_count(const char *s, char c, unsigned int i)
{
	unsigned int	k;

	k = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		k++;
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		l;
	unsigned int		wrd_amt;
	char				**strb;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wrd_amt = ft_word_count(s, c) + 1;
	strb = (char **)malloc(sizeof(char *) * wrd_amt);
	if (!strb)
		return (NULL);
	while (i < ft_strlen(s) && j < wrd_amt - 1)
	{
		while (s[i] == c)
			i++;
		l = ft_letter_count(s, c, i);
		strb[j++] = ft_substr(s, i, l);
		i = i + l;
		s++;
	}
	strb[j] = NULL;
	return (strb);
}
