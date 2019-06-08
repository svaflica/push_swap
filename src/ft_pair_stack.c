/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:27:05 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/30 11:27:06 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_pair_stack			*ft_pair_stack_new(void)
{
	t_pair_stack	*p;

	if (!(p = (t_pair_stack *)malloc(sizeof(t_pair_stack))))
		return (NULL);
	p->a = NULL;
	p->b = NULL;
	return (p);
}
