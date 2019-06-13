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

static t_stack	*ft_is_srt(t_stack *a)
{
	t_stack *tmp;

	if (!a)
		return (NULL);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static int		ft_is_srt_num(t_stack *a)
{
	t_stack *tmp;
	int 	i;
	int 	i_no_s;

	if (!a)
		return (0);
	i = 0;
	i_no_s = -1;
	tmp = a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			i_no_s = i;
		i++;
		tmp = tmp->next;
	}
	if (i_no_s == -1)
		return (0);
	if (i_no_s >= i / 2)
		return (1);
	return (-1);
}

static t_stack	*ft_stack_last(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int		ft_three_med(t_stack *a)
{
	if ((a->num > a->next->num && a->num < a->next->next->num) ||
		(a->num < a->next->num && a->num > a->next->next->num))
		return (a->num);
	if ((a->num < a->next->num && a->next->num < a->next->next->num) ||
		(a->num > a->next->num && a->next->num > a->next->next->num))
		return (a->next->num);
	return (a->next->next->num);
}

void	ft_three_sort(t_pair_stack *pe, t_stack *tmp, t_stack **sol, int med)
{
	t_stack *last;

	last = ft_stack_last(pe->a);
	while (tmp)
	{
		if (tmp == pe->a && tmp->num > tmp->next->num)
		{
			s(pe->a);
			ft_stack_push_b(sol, ft_stack_new(1));
		}
		else if (last->num <= med)
		{
			rr_f(&(pe->a));
			last = ft_stack_last(pe->a);
			ft_stack_push_b(sol, ft_stack_new(9));
		}
		else if (tmp == pe->a && tmp->num > last->num)
		{
			r(&(pe->a));
			last = ft_stack_last(pe->a);
			ft_stack_push_b(sol, ft_stack_new(6));
		}
		tmp = ft_is_srt(pe->a);
	}
}

int		ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

int 	ft_is_min(t_pair_stack *pe, t_stack *tmp_b, int *who_a)
{
	int			min;
	t_stack		*tmp;
	int 		min_i;
	int			i;

	tmp = pe->a;
	i = 0;
	min = INT32_MAX;
	while (tmp)
	{
		if (tmp->num <= min)
		{
			min_i = i;
			*who_a = tmp->num;
			min = tmp->num;
		}
		tmp = tmp->next;
		i++;
	}
	if (tmp_b->num <= min)
		return (min_i);
	return (-1);
}

int 	ft_is_max(t_pair_stack *pe, t_stack *tmp_b, int *who_a)
{
	int			max;
	t_stack		*tmp;
	int 		max_i;
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
	if (max_tmp->next)
	{
		max_i++;
		*who_a = max_tmp->next->num;
	}
	else
		{
		max_i = 0;
		*who_a = pe->a->num;
	}
	if (tmp_b->num >= max)
		return (max_i);
	return (-1);
}

int		find_in_a(t_pair_stack *pe, t_stack *tmp_b, int *who, int *who_a)
{
	t_stack		*tmp_a;
	t_stack		*last;
	int			i;

	tmp_a = pe->a;
	last = ft_stack_last(pe->a);
	*who_a = 0;
	if ((i = ft_is_min(pe, tmp_b, who_a)) != -1 || (i = ft_is_max(pe, tmp_b, who_a)) != -1)
	{
		*who += (pe->size_a / 2 - i >= 0 ? 3 : -3);
		return (ft_abs(pe->size_a / 2 - ft_abs(pe->size_a / 2 - i)));
	}
	i = 0;
	if (!ft_is_srt(pe->a))
	{
		while (tmp_a)
		{
			if (tmp_a->num > tmp_b->num)
				break ;
			i++;
			tmp_a = tmp_a->next;
		}
	}
	else
	{
		while (tmp_a)
		{
			if ((tmp_a->prev && tmp_a->prev->num < tmp_b->num && tmp_a->num > tmp_b->num) ||
				(!(tmp_a->prev) && last->num < tmp_b->num && tmp_b->num < tmp_a->num))
				break ;
			i++;
			tmp_a = tmp_a->next;
		}
	}
	*who_a = (tmp_a ? tmp_a->num : 0);
	if (pe->size_a / 2 == i + 1 && pe->size_a % 2)
		*who = 3;
	else
		*who += (pe->size_a / 2 - i >= 0 ? 3 : -3);
	return (ft_abs(pe->size_a / 2 - ft_abs(pe->size_a / 2 - i)));
}

void	find_who_and_where(t_pair_stack *pe, int who, int where, int who_a, t_stack **sol) {
	t_stack *tmp_b;
	int wh;
	int max_num;
	int num;
	int i;
	int wh_a;

	max_num = INT32_MAX;
	tmp_b = pe->b;
	i = 0;
	while (tmp_b) {
		wh = (pe->size_b / 2 - i >= 0 ? 1 : -1);
		num = pe->size_b / 2 - ft_abs(pe->size_b / 2 - i) + find_in_a(pe, tmp_b, &wh, &wh_a);
		if (max_num > num) {
			who_a = wh_a;
			where = wh;
			who = tmp_b->num;
			max_num = num;
		}
		i++;
		tmp_b = tmp_b->next;
	}
	while (pe->b->num != who)
		if (where == 2 || where == -4)
		{
			rr_f(&(pe->b));
			ft_stack_push_b(sol, ft_stack_new(10));
		} else
			{
			r(&(pe->b));
			ft_stack_push_b(sol, ft_stack_new(7));
		}
	if (!(who_a == 0 && !ft_is_in_stack(pe->a, 0)))
		while (pe->a->num != who_a)
		{
			if (where == -4 || where == -2)
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
	p(&(pe->a), &(pe->b));
	ft_stack_push_b(sol, ft_stack_new(4));
	pe->size_b--;
	pe->size_a++;
}

void 	ft_bitch_sort(t_pair_stack *pe, t_stack **sol)
{
	t_stack		*tmp;
	int			who;
	int			where;
	int			who_a;

	while (ft_is_srt(pe->a) && pe->size_a > 3)
	{
		p(&(pe->b), &(pe->a));
		ft_stack_push_b(sol, ft_stack_new(5));
		pe->size_b++;
		pe->size_a--;
	}
	if ((tmp = ft_is_srt(pe->a)))
		ft_three_sort(pe, tmp, sol, ft_three_med(pe->a));
	while (pe->b)
		find_who_and_where(pe, who, where, who_a, sol);
	who = ft_is_srt_num(pe->a);
	while (ft_is_srt(pe->a))
	{
		if (who == -1)
		{
			r(&(pe->a));
			ft_stack_push_b(sol, ft_stack_new(6));
		}
		else if (who == 1)
		{
			rr_f(&(pe->a));
			ft_stack_push_b(sol, ft_stack_new(9));
		}
		else
			break ;
	}
}