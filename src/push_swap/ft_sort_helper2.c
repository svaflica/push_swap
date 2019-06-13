/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_helper2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:31:22 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/13 16:31:23 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void		ft_help(int *who_a, int *max_i, t_stack *max_tmp, t_stack *beg)
{
	if (max_tmp->next)
	{
		(*max_i)++;
		*who_a = max_tmp->next->num;
	}
	else
	{
		(*max_i) = 0;
		*who_a = beg->num;
	}
}

int				ft_is_max(t_pair_stack *pe, t_stack *tmp_b, int *who_a)
{
	int			max;
	t_stack		*tmp;
	int			max_i;
	int			i;
	t_stack		*max_tmp;

	tmp = pe->a;
	i = 0;
	max = INT32_MIN;
	while (tmp)
	{
		if (tmp->num >= max)
		{
			max_i = i;
			*who_a = tmp->num;
			max_tmp = tmp;
			max = tmp->num;
		}
		tmp = tmp->next;
		i++;
	}
	ft_help(who_a, &max_i, max_tmp, pe->a);
	if (tmp_b->num >= max)
		return (max_i);
	return (-1);
}
