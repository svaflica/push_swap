/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 23:28:43 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/26 23:28:44 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int		ft_find_comm2(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strcmp(str, "rb"))
		r(b);
	else if (!ft_strcmp(str, "rr"))
		rr(a, b);
	else if (!ft_strcmp(str, "rra"))
		rr_f(a);
	else if (!ft_strcmp(str, "rrb"))
		rr_f(b);
	else if (!ft_strcmp(str, "rrr"))
		rrr(a, b);
	else
	{
		*a != NULL ? ft_stack_del(a) : NULL;
		*b != NULL ? ft_stack_del(b) : NULL;
		return (-1);
	}
	return (1);
}

static int		ft_find_comm(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strcmp(str, "sa"))
		s(*a);
	else if (!ft_strcmp(str, "sb"))
		s(*b);
	else if (!ft_strcmp(str, "ss"))
		ss(*a, *b);
	else if (!ft_strcmp(str, "pa"))
		p(a, b);
	else if (!ft_strcmp(str, "pb"))
		p(b, a);
	else if (!ft_strcmp(str, "ra"))
		r(a);
	else
		return (ft_find_comm2(a, b, str));
	return (1);
}

int				checker(t_stack *a, t_stack *b, char **str, int deb)
{
	char	**tmp;
	int		res;

	if (str == NULL)
		return (ft_is_sorted(&a));
	tmp = str;
	if (deb)
	{
		ft_printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\nBegin debag\n");
		ft_stacks_print(a, b);
		ft_printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	}
	while (*tmp)
	{
		if (ft_find_comm(&a, &b, *tmp) == -1)
		{
			a != NULL ? ft_stack_del(&a) : NULL;
			b != NULL ? ft_stack_del(&b) : NULL;
			ft_pstrdel((void **)str);
			return (-1);
		}
		if (deb)
		{
			while (read(1, NULL, 5) == 1)
				NULL;
			ft_printf("\n%s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", *tmp);
			ft_stacks_print(a, b);
			ft_printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		}
		tmp++;
	}
	res = 1;
	if (b || !ft_is_sorted(&a))
		res = 0;
	a != NULL ? ft_stack_del(&a) : NULL;
	b != NULL ? ft_stack_del(&b) : NULL;
	ft_pstrdel((void **)str);
	return (res);
}
