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

static char		*ft_hmm2(char **v, int *deb, int *c)
{
	char *name;

	name = NULL;
	if (!ft_strcmp(v[1], "-f"))
	{
		name = v[2];
		*c -= 2;
	}
	else if (!ft_strcmp(v[1], "-d"))
	{
		*deb = 1;
		(*c)--;
	}
	return (name);
}

static char		*ft_hmm(char **v, int *c, int *deb)
{
	char *name;

	name = NULL;
	*deb = 0;
	if (!ft_strcmp(v[1], "-f"))
	{
		name = v[2];
		v += 2;
		*c -= 2;
	}
	else if (!ft_strcmp(v[1], "-d"))
	{
		*deb = 1;
		v += 1;
		(*c)--;
	}
	name = (!name ? ft_hmm2(v, deb, c) : NULL);
	return (name);
}

static void		res(int cou)
{
	if (cou == 1)
		write(1, "OK\n", 3);
	else if (cou == 0)
		write(1, "KO\n", 3);
	else if (cou == -1)
		write(1, "Error\n", 6);
}

int				main(int c, char **v)
{
	t_pair_stack	*p;
	int				cou;
	int				deb;
	char			*name;

	if (c == 1)
		return (-1);
	name = ft_hmm(v, &c, &deb);
	if (name)
		v += 2;
	if (deb)
		v += 1;
	if (!(ft_is_arg_valid(v + 1) && (p = ft_pair_stack_new()) && c != 1))
		return (write(1, "Error\n", 6));
	if (!ft_stack_full(&p, v, c))
		return (0);
	res(checker(&(p->a), &(p->b), ft_read(p, name), deb));
	p->a ? ft_stack_del(&(p->a)) : NULL;
	p->b ? ft_stack_del(&(p->b)) : NULL;
	p ? ft_memdel((void **)&p) : NULL;
	return (0);
}
