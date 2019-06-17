/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:25:32 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/15 17:26:03 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char *s, char c)
{
	int res;
	int mark;

	res = 0;
	mark = 0;
	while (*s != '\0')
	{
		if (*s != c && !mark)
		{
			mark = 1;
			res++;
		}
		else if (*s == c)
			mark = 0;
		s++;
	}
	return (res);
}

static int	ft_word_len(char *s, char c)
{
	int res;

	res = 1;
	while (*s != c && *s != '\0')
	{
		s++;
		res++;
	}
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	if ((temp = (char**)malloc(8 * (ft_word_count((char*)s, c) + 1))))
	{
		while (*s != '\0')
		{
			if ((char)*s != c)
			{
				j = 0;
				if (!(temp[i] = (char*)malloc(ft_word_len((char*)s, c))))
					return (NULL);
				while ((char)*s != c && *s != '\0')
					temp[i][j++] = *s++;
				temp[i++][j] = '\0';
			}
			s = ((char)*s == c && (char)*s != '\0' ? ++s : s);
		}
		temp[i] = 0;
	}
	return (&temp[0]);
}
