/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comm2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:28:13 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/08 14:28:14 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			r(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp = ft_stack_new(ft_stack_pop(a));
	tmp2 = *a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->prev = tmp2;
}

void			rr(t_stack *a, t_stack *b)
{
	r(&a);
	r(&b);
}

void			rr_f(t_stack **a)
{
	t_stack *tmp;
	t_stack *pr_tmp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	pr_tmp = tmp->prev;
	ft_stack_push(a, tmp);
	if (pr_tmp)
		pr_tmp->next = NULL;
}

void			rrr(t_stack *a, t_stack *b)
{
	rr_f(&a);
	rr_f(&b);
}
