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

int		ft_is_arg_valid(char **arg)
{
	char **tmp;
	char *tmp2;

	tmp = arg;
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
			if (!ft_isdigit(*tmp2))
				return (0);
			tmp2++;
		}
		tmp++;
	}
	return (1);
}
