/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_helper3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:25:52 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/13 17:25:53 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack			*thanks_norm(t_pair_stack *pe, t_stack *tmp_b, int *i)
{
	t_stack		*tmp_a;

	tmp_a = pe->a;
	while (tmp_a)
	{
		if (tmp_a->num > tmp_b->num)
			break ;
		(*i)++;
		tmp_a = tmp_a->next;
	}
	return (tmp_a);
}

t_stack			*thanks_norm2(t_pair_stack *pe, t_stack *tmp_b, int *i)
{
	t_stack		*tmp_a;
	t_stack		*last;

	last = ft_stack_last(pe->a);
	tmp_a = pe->a;
	while (tmp_a)
	{
		if ((tmp_a->prev && tmp_a->prev->num < tmp_b->num && tmp_a->num >
			tmp_b->num) || (!(tmp_a->prev) && last->num < tmp_b->num &&
			tmp_b->num < tmp_a->num))
			break ;
		(*i)++;
		tmp_a = tmp_a->next;
	}
	return (tmp_a);
}

int				ft_is_max_or_min(t_pair_stack *pe, t_stack *tmp_b, int *who_a)
{
	int i;

	if ((i = ft_is_min(pe, tmp_b, who_a)) != -1)
		return (i);
	return (ft_is_max(pe, tmp_b, who_a));
}

int				find_in_a(t_pair_stack *pe, t_stack *tmp_b, t_w *tmp)
{
	t_stack		*tmp_a;
	int			i;

	tmp->who_a = 0;
	if ((i = ft_is_max_or_min(pe, tmp_b, &(tmp->who_a))) != -1)
	{
		tmp->who += (pe->size_a / 2 - i >= 0 ? 3 : -3);
		return (ft_abs(pe->size_a / 2 - ft_abs(pe->size_a / 2 - i)));
	}
	i = 0;
	if (!ft_is_srt(pe->a))
		tmp_a = thanks_norm(pe, tmp_b, &i);
	else
		tmp_a = thanks_norm2(pe, tmp_b, &i);
	tmp->who_a = (tmp_a ? tmp_a->num : 0);
	if (pe->size_a / 2 == i + 1 && pe->size_a % 2)
		tmp->who = 3;
	else
		tmp->who += (pe->size_a / 2 - i >= 0 ? 3 : -3);
	return (ft_abs(pe->size_a / 2 - ft_abs(pe->size_a / 2 - i)));
}

void			ft_shift(t_pair_stack *pe, t_w *w, t_stack **sol)
{
	while (pe->b->num != w->who)
		if (w->where == 2 || w->where == -4)
		{
			rr_f(&(pe->b));
			ft_stack_push_b(sol, ft_stack_new(10));
		}
		else
		{
			r(&(pe->b));
			ft_stack_push_b(sol, ft_stack_new(7));
		}
	if (!(w->who_a == 0 && !ft_is_in_stack(pe->a, 0)))
		while (pe->a->num != w->who_a)
		{
			if (w->where == -4 || w->where == -2)
			{
				rr_f(&(pe->a));
				ft_stack_push_b(sol, ft_stack_new(9));
			}
			else
			{
				r(&(pe->a));
				ft_stack_push_b(sol, ft_stack_new(6));
			}
		}
}
