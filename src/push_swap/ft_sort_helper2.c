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

static int		ft_three_med(t_stack *a)
{
	if ((a->num > a->next->num && a->num < a->next->next->num) ||
		(a->num < a->next->num && a->num > a->next->next->num))
		return (a->num);
	if ((a->num < a->next->num && a->next->num < a->next->next->num) ||
		(a->num > a->next->num && a->next->num > a->next->next->num))
		return (a->next->num);
	return (a->next->next->num);
}

static void		ft_two_sort(t_pair_stack *pe, t_stack *tmp, t_stack **sol)
{
	if (pe->a->num > pe->a->next->num)
	{
		s(pe->a);
		ft_stack_push_b(sol, ft_stack_new(1));
	}
}

void			ft_sort_hel(t_pair_stack *pe, t_stack **sol)
{
	t_stack		*tmp;

	if ((tmp = ft_is_srt(pe->a)))
		pe->size_a == 3 ? ft_three_sort(pe, tmp, sol,
			ft_three_med(pe->a)) : ft_two_sort(pe, tmp, sol);
}
