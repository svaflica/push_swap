/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:24:57 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/13 16:31:14 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack			*ft_is_srt(t_stack *a)
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

void			ft_three_sort(t_pair_stack *pe, t_stack *tmp,
								t_stack **sol, int med)
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

int				ft_is_srt_num(t_stack *a)
{
	t_stack	*tmp;
	int		i;
	int		i_no_s;

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

int				ft_is_min(t_pair_stack *pe, t_stack *tmp_b, int *who_a)
{
	int			min;
	t_stack		*tmp;
	int			min_i;
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
