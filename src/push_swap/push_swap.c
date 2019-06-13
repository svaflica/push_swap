/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:09:10 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/27 17:09:11 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int		ft_stack_full(t_pair_stack **p, char **v, int c)
{
	int cou;

	while (--c)
	{
		cou = ft_atoi(v[c]);
		if ((cou == -1 && ft_strcmp(v[c], "-1") != 0) ||
			(cou == 0 && ft_strcmp(v[c], "0") != 0) ||
			ft_is_in_stack((*p)->a, cou))
		{
			ft_stack_del(&((*p)->a));
			ft_stack_del(&((*p)->b));
			ft_memdel((void **)p);
			write(1, "Error\n", 6);
			return (0);
		}
		else
			ft_stack_push(&((*p)->a), ft_stack_new(cou));
	}
	return (1);
}

int				main(int c, char **v)
{
	t_pair_stack	*p;
	t_stack			*sol;

	if (c == 1)
		return (-1);
	if (!(ft_is_arg_valid(v + 1) && (p = ft_pair_stack_new())))
		return (write(1, "Error\n", 6));
	sol = NULL;
	if (!ft_stack_full(&p, v, c))
		return (0);
	c--;
	p->size_b = 0;
	p->size_a = c;
	ft_bitch_sort(p, &sol);
	ft_stack_del(&(p->a));
	p->b ? ft_stack_del(&(p->b)) : NULL;
	ft_memdel((void **)&p);
	sol != NULL ? ft_comm_go(&sol) : NULL;
	return (0);
}
