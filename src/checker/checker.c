/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:48:41 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/26 17:48:43 by djeanna          ###   ########.fr       */
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

static void		ft_for_file(char **name, char *v, int *c)
{
	*name = v;
	*c -= 2;
}

int				main(int c, char **v)
{
	t_pair_stack	*p;
	int				cou;
	char			*name;

	if (c == 1)
		return (-1);
	name = NULL;
	if (!ft_strcmp(v[1], "-f"))
	{
		ft_for_file(&name, v[2], &c);
		v += 2;
	}
	if (!(ft_is_arg_valid(v + 1) && (p = ft_pair_stack_new()) && c != 1))
		return (write(1, "Error\n", 6));
	if (!ft_stack_full(&p, v, c))
		return (0);
	cou = checker(p->a, p->b, ft_read(p, name));
	if (cou == 1)
		write(1, "OK\n", 3);
	else if (cou == 0)
		write(1, "KO\n", 3);
	else if (cou == -1)
		write(1, "Error\n", 6);
	ft_memdel((void **)&p);
	return (0);
}
