/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:27:03 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/17 17:27:05 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	while (*v && *v != ' ')
	{
		if (*v != '0')
			return (0);
		v++;
	}
	return (1);
}

static void		ft_skip_num(char *v, int *len)
{
	while (v[*len] == ' ' && *len)
		(*len)--;
	while ((*len))
	{
		if (!(ft_isdigit(v[*len]) || v[*len] == '-' || v[*len] == '+'))
			break ;
		(*len)--;
	}
}

static int		ft_stack_add(t_pair_stack **p, char **v, int c, int *len)
{
	int cou;

	if (ft_isdigit(v[c][*len]) &&
		(v[c][*len + 1] == ' ' || v[c][*len + 1] == 0))
	{
		cou = ft_atoi(v[c]);
		if (ft_is_in_stack((*p)->a, cou))
		{
			ft_stack_del(&((*p)->a));
			ft_stack_del(&((*p)->b));
			ft_memdel((void **)p);
			write(1, "Error\n", 6);
			return (0);
		}
		else
			ft_stack_push(&((*p)->a), ft_stack_new(cou));
		(*p)->size_a++;
	}
	return (1);
}

int				ft_stack_full(t_pair_stack **p, char **v, int c)
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
				return (ft_error_st(p));
			else
				ft_stack_push(&((*p)->a), ft_stack_new(cou));
			ft_skip_ws(v[c], &len);
			(*p)->size_a++;
		}
		if (!ft_stack_add(p, v, c, &len))
			return (0);
	}
	return (1);
}
