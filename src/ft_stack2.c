/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:42:19 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/08 14:42:19 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int				ft_is_in_stack(t_stack *a, int num)
{
	t_stack		*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->num == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				ft_stack_push_b(t_stack **beg, t_stack *s)
{
	t_stack *tmp;

	if (s == NULL)
		return (0);
	if (!*beg)
	{
		*beg = s;
		return (1);
	}
	tmp = (*beg);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = s;
	tmp->next->prev = tmp;
	return (1);
}

void			ft_stacks_print(t_stack *a, t_stack *b)
{
	t_stack		*tmp;
	t_stack		*tmp_b;

	tmp = a;
	tmp_b = b;
	while (tmp && tmp_b)
	{
		ft_printf("%-10d%10d\n", tmp->num, tmp_b->num);
		tmp = tmp->next;
		tmp_b = tmp_b->next;
	}
	while (tmp)
	{
		ft_printf("%-10d\n", tmp->num);
		tmp = tmp->next;
	}
	while (tmp_b)
	{
		ft_printf("%-10c%10d\n", ' ', tmp_b->num);
		tmp_b = tmp_b->next;
	}
}

t_stack			*ft_stack_last(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int				ft_error_st(t_pair_stack **p)
{
	(*p)->a ? ft_stack_del(&((*p)->a)) : NULL;
	(*p)->b ? ft_stack_del(&((*p)->b)) : NULL;
	ft_memdel((void **)p);
	write(1, "Error\n", 6);
	return (0);
}
