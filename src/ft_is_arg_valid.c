/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:22:13 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/27 16:22:15 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int		ft_help(char **tmp, char *tmp2)
{
	while (*tmp)
	{
		tmp2 = *tmp;
		if (*tmp2 == '-' || *tmp2 == '+')
		{
			tmp2++;
			if (!ft_isdigit(*tmp2))
				return (0);
		}
		while (*tmp2)
		{
			if ((*tmp2 == '-' || *tmp2 == '+') && !ft_isdigit(*(tmp2 - 1)))
			{
				tmp2++;
				if (!ft_isdigit(*tmp2))
					return (0);
			}
			else if (!ft_isdigit(*tmp2) && *tmp2 != ' ')
				return (0);
			tmp2++;
		}
		tmp++;
	}
	return (1);
}

int				ft_is_arg_valid(char **arg)
{
	char **tmp;
	char *tmp2;

	tmp = arg;
	return (ft_help(tmp, tmp2));
}

void			ft_delet(t_stack **a, t_stack **b, char **str)
{
	*a != NULL ? ft_stack_del(a) : NULL;
	*b != NULL ? ft_stack_del(b) : NULL;
	ft_pstrdel((void **)str);
}
