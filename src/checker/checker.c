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

static void		ft_skip_ws(char *v, int *len)
{
	while (v[*len] == ' ' && *len)
		(*len)--;
}

static int		is_val(char *v, int val)
{
	while (*v == ' ')
		v++;
	if (val == -1)
	{
		if (*v == '-' && *(v + 1) == '1' && (*(v + 2) == ' ' || *(v + 2) == 0))
			return (1);
		return (0);
	}
	if (*v == '0' && (*(v + 1) == ' ' || *(v + 1) == 0))
		return (1);
	return (0);
}

static void		ft_skip_num(char *v, int *len)
{
	while (v[*len] == ' ' && *len)
		(*len)--;
	while ((*len))
	{
		if (!(ft_isdigit(v[*len]) || v[*len] == '-' || v[*len] == '+'))
			break;
		(*len)--;
	}
}

static int		ft_stack_full(t_pair_stack **p, char **v, int c)
{
	int cou;
	int len;

	while (--c)
	{
		len = ft_strlen(v[c]) - 1;
		while (len > 0)
		{
			ft_skip_num(v[c], &len);
			cou = ft_atoi(&v[c][len]);
			if ((cou == -1 && !is_val(&v[c][len], cou)) ||
				(cou == 0 && !is_val(&v[c][len], cou)) ||
				ft_is_in_stack((*p)->a, cou))
			{
				ft_stack_del(&((*p)->a));
				ft_stack_del(&((*p)->b));
				ft_memdel((void **) p);
				write(1, "Error\n", 6);
				return (0);
			}
			else
				ft_stack_push(&((*p)->a), ft_stack_new(cou));
			ft_skip_ws(v[c], &len);
		}
		if (ft_isdigit(v[c][len]) && (v[c][len + 1] == ' ' || v[c][len + 1] == 0))
		{
			cou = ft_atoi(v[c]);
			if (ft_is_in_stack((*p)->a, cou)) {
				ft_stack_del(&((*p)->a));
				ft_stack_del(&((*p)->b));
				ft_memdel((void **) p);
				write(1, "Error\n", 6);
				return (0);
			} else
				ft_stack_push(&((*p)->a), ft_stack_new(cou));
		}
	}
	return (1);
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
	if (!ft_strcmp(v[1], "-f"))
	{
		name = v[2];
		v += 2;
		*c -= 2;
	}
	else if (!ft_strcmp(v[1], "-d"))
	{
		*deb = 1;
		(*c)--;
		v += 1;
	}
	return (name);
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
	cou = checker(p->a, p->b, ft_read(p, name), deb);
	if (cou == 1)
		write(1, "OK\n", 3);
	else if (cou == 0)
		write(1, "KO\n", 3);
	else if (cou == -1)
		write(1, "Error\n", 6);
	ft_memdel((void **)&p);
	return (0);
}
