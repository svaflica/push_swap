/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 12:23:26 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/02 12:23:28 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void			ft_pa(t_pair_stack *pe, t_stack **sol)
{
	p(&(pe->a), &(pe->b));
	ft_stack_push_b(sol, ft_stack_new(4));
	pe->size_b--;
	pe->size_a++;
}

void			find_who_and_where(t_pair_stack *pe, t_w *w,
									t_stack **sol, int max_num)
{
	t_stack *tmp_b;
	int		num;
	int		i;
	t_w		tmp;

	tmp_b = pe->b;
	i = 0;
	while (tmp_b)
	{
		tmp.who = (pe->size_b / 2 - i >= 0 ? 1 : -1);
		num = pe->size_b / 2 - ft_abs(pe->size_b / 2 - i) +
				find_in_a(pe, tmp_b, &tmp);
		if (max_num > num)
		{
			w->who_a = tmp.who_a;
			w->where = tmp.who;
			w->who = tmp_b->num;
			max_num = num;
		}
		tmp_b = tmp_b->next;
		i++;
	}
	ft_shift(pe, w, sol);
	ft_pa(pe, sol);
}

static void		ft_pb(t_pair_stack *pe, t_stack **sol)
{
	p(&(pe->b), &(pe->a));
	ft_stack_push_b(sol, ft_stack_new(5));
	pe->size_b++;
	pe->size_a--;
}

void			ft_bitch_sort(t_pair_stack *pe, t_stack **sol)
{
	t_w			w;

	while (ft_is_srt(pe->a) && pe->size_a > 3)
		ft_pb(pe, sol);
	ft_sort_hel(pe, sol);
	while (pe->b)
		find_who_and_where(pe, &w, sol, INT32_MAX);
	w.who = ft_is_srt_num(pe->a);
	while (ft_is_srt(pe->a))
	{
		if (w.who == -1)
		{
			r(&(pe->a));
			ft_stack_push_b(sol, ft_stack_new(6));
		}
		else if (w.who == 1)
		{
			rr_f(&(pe->a));
			ft_stack_push_b(sol, ft_stack_new(9));
		}
		else
			break ;
	}
}
