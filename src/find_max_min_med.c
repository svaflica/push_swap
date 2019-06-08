/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min_med.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:18:20 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/08 14:18:21 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int		ft_strcmp2(const char *s1, const char *s2)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	if (ft_strlen((const char *)tmp_s1) > ft_strlen((const char *)tmp_s2))
		return (1);
	else if (ft_strlen((const char *)tmp_s1) < ft_strlen((const char *)tmp_s2))
		return (-1);
	while (*tmp_s1 == *tmp_s2 && *tmp_s1 && *tmp_s2)
	{
		tmp_s1++;
		tmp_s2++;
	}
	return ((int)(*tmp_s1 - *tmp_s2));
}

int				ft_find_max(t_stack *a)
{
	t_stack *tmp;
	int		max;

	max = a->num;
	tmp = a->next;
	while (tmp)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int				ft_find_min(t_stack *a)
{
	t_stack *tmp;
	int		min;

	min = a->num;
	tmp = a->next;
	while (tmp)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

double			ft_find_median(char **v, int len)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp2(v[i], v[j]) > 0)
			{
				c = v[i];
				v[i] = v[j];
				v[j] = c;
			}
			j++;
		}
		i++;
	}
	if (len % 2)
		return (ft_atoi(v[len / 2]));
	return ((ft_atoi(v[len / 2]) + ft_atoi(v[len / 2 - 1])) / 2.0);
}
