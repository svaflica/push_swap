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

	tmp = a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static t_stack	*ft_is_srt_b(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->num < tmp->next->num)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static t_stack	*ft_stack_last(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void			ft_sort(t_pair_stack *pe, double med, t_stack **sol)
{
	t_stack		*tmp;
	t_stack		*last;

	tmp = ft_is_srt(pe->a);
	last = ft_stack_last(pe->a);
	if (tmp)
	{
		if (last->num <= med)
		{
			rr_f(&(pe->a));
			last = ft_stack_last(pe->a);
			ft_stack_push_b(sol, ft_stack_new(9));
			//write(1, "rra\n", 4);
		}
		else if (tmp == pe->a && tmp->num > last->num)
		{
			r(&(pe->a));
			last = ft_stack_last(pe->a);
			//write(1, "ra\n", 3);
			ft_stack_push_b(sol, ft_stack_new(6));
		}
		else if (tmp == pe->a && tmp->num > tmp->next->num)
		{
			s(pe->a);
			//write(1, "sa\n", 3);
			ft_stack_push_b(sol, ft_stack_new(1));
		}
		else if (tmp->num > tmp->next->num)
		{
			p(&(pe->b), &(pe->a));
			//write(1, "pb\n", 3);
			ft_stack_push_b(sol, ft_stack_new(5));
		}
		ft_sort(pe, med, sol);
	}
	else if (pe->b)
	{
		tmp = ft_is_srt_b(pe->b);
		last = ft_stack_last(pe->b);
		if (tmp)
		{
			if (last->num > med)
			{
				rr_f(&(pe->b));
				last = ft_stack_last(pe->b);
				//write(1, "rrb\n", 4);
				ft_stack_push_b(sol, ft_stack_new(10));
			}
			if (tmp == pe->b && tmp->num < last->num)
			{
				r(&(pe->b));
				last = ft_stack_last(pe->b);
				//write(1, "rb\n", 3);
				ft_stack_push_b(sol, ft_stack_new(7));
			}
			else if (tmp == pe->b && tmp->num < tmp->next->num)
			{
				s(pe->b);
				//write(1, "sb\n", 3);
				ft_stack_push_b(sol, ft_stack_new(2));
			}
			else if (tmp->num <= tmp->next->num)
			{
				p(&(pe->a), &(pe->b));
				//write(1, "pa\n", 3);
				ft_stack_push_b(sol, ft_stack_new(4));
			}
		}
		else
			{
			p(&(pe->a), &(pe->b));
			//write(1, "pa\n", 3);
			ft_stack_push_b(sol, ft_stack_new(4));
		}
		ft_sort(pe, med, sol);
	}
}

void 	ft_bitch_sort(t_pair_stack *pe, int max, int min, double med, t_stack **sol)
{
	t_stack		*tmp;
	t_stack		*last;

	while (pe->a->next && (pe->a->next->next))
	{
		if (pe->a->num != max && pe->a->num != min)
		{
			p(&(pe->b), &(pe->a));
			ft_stack_push_b(sol, ft_stack_new(5));
		}
		else
			{
			r(&(pe->a));
			ft_stack_push_b(sol, ft_stack_new(6));
		}
	}
	if (pe->a->num < pe->a->next->num)
	{
		ft_stack_push_b(sol, ft_stack_new(6));
		r(&(pe->a));
	}
	while ((tmp = ft_is_srt_b(pe->b)))
	{
		last = ft_stack_last(pe->b);
		if (last->num > med)
		{
			rr_f(&(pe->b));
			last = ft_stack_last(pe->b);
			//write(1, "rrb\n", 4);
			ft_stack_push_b(sol, ft_stack_new(10));
		}
		else if (tmp == pe->b && tmp->num < last->num)
		{
			r(&(pe->b));
			last = ft_stack_last(pe->b);
			//write(1, "rb\n", 3);
			ft_stack_push_b(sol, ft_stack_new(7));
		}
		else if (tmp == pe->b && tmp->num < tmp->next->num)
		{
			s(pe->b);
			//write(1, "sb\n", 3);
			ft_stack_push_b(sol, ft_stack_new(2));
		}
		else if (tmp->num <= tmp->next->num)
		{
			p(&(pe->a), &(pe->b));
			//write(1, "pa\n", 3);
			ft_stack_push_b(sol, ft_stack_new(4));
		}
	}
	while (pe->b)
	{
		p(&(pe->a), &(pe->b));
		ft_stack_push_b(sol, ft_stack_new(4));
	}
	if (pe->a->num > ft_stack_last(pe->a)->num)
	{
		ft_stack_push_b(sol, ft_stack_new(9));
		rr_f(&(pe->a));
	}
}