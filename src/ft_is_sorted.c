/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:55:07 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/01 17:55:10 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_is_sorted(t_stack **a)
{
	int tmp;
	int tmp2;

	if (!*a || !(*a)->next)
		return (1);
	tmp = ft_stack_pop(a);
	tmp2 = ft_stack_pop(a);
	while (*a)
	{
		if (tmp > tmp2)
			return (0);
		tmp = tmp2;
		tmp2 = ft_stack_pop(a);
	}
	return (tmp < tmp2);
}
