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

void			ft_stack_print(t_stack *a)
{
	t_stack		*tmp;

	tmp = a;
	while (tmp)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
}
