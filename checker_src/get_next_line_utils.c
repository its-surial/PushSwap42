/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:04:58 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/26 20:46:43 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	char			*dest;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (*s1 != '\0')
	{
		dest[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t			i;
	size_t			n;
	char			*ptr;

	i = 0;
	n = 0;
	while (s[n] != '\0')
		n++;
	ptr = (char *)malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	size_t			l;
	unsigned char	cc;
	char			*ptr;

	i = 0;
	l = ft_strlen(str);
	cc = (unsigned char)c;
	ptr = (char *)str;
	while (i < l + 1)
	{
		if (ptr[i] == cc)
		{
			return (ptr + i);
		}
		i++;
	}
	return (NULL);
}
