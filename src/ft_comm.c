/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 00:08:46 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/27 00:08:47 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			s(t_stack *a)
{
	if (!a || !a->next)
		return ;
	ft_swap(&(a->num), &(a->next->num));
}

void			ss(t_stack *a, t_stack *b)
{
	s(a);
	s(b);
}

void			p(t_stack **a, t_stack **b)
{
	if (b && *b)
		ft_stack_push(a, ft_stack_new(ft_stack_pop(b)));
}
