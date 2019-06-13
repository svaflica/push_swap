/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comm_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:19:11 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/06 16:19:12 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_comm_go2(t_stack **sol, int a)
{
	if (!a && (*sol)->num == 2)
		write(1, "sb\n", 3);
	else if ((*sol)->num == 4)
		write(1, "pa\n", 3);
	else if ((*sol)->num == 5)
		write(1, "pb\n", 3);
	else if (!a && (*sol)->num == 6)
		write(1, "ra\n", 3);
	else if (!a && (*sol)->num == 7)
		write(1, "rb\n", 3);
	else if (!a && (*sol)->num == 9)
		write(1, "rra\n", 4);
	else if (!a && (*sol)->num == 10)
		write(1, "rrb\n", 4);
	if (!a)
	{
		ft_comm_go(&((*sol)->next));
		ft_memdel((void **)sol);
	}
	else
	{
		ft_comm_go(&((*sol)->next->next));
		ft_memdel((void **)&((*sol)->next));
		ft_memdel((void **)sol);
	}
}

void			ft_comm_go(t_stack **sol)
{
	int a;

	if (!*sol)
		return ;
	a = 0;
	if ((*sol)->next)
	{
		a = 1;
		if (((*sol)->num == 1 && (*sol)->next->num == 2) ||
			((*sol)->num == 2 && (*sol)->next->num == 1))
			write(1, "ss\n", 3);
		else if (((*sol)->num == 6 && (*sol)->next->num == 7) ||
				((*sol)->num == 7 && (*sol)->next->num == 6))
			write(1, "rr\n", 3);
		else if (((*sol)->num == 9 && (*sol)->next->num == 10) ||
				((*sol)->num == 10 && (*sol)->next->num == 9))
			write(1, "rrr\n", 4);
		else
			a = 0;
	}
	if (!a && (*sol)->num == 1)
	{
		write(1, "sa\n", 3);
		ft_comm_go(&((*sol)->next));
		ft_memdel((void **)sol);
	}
	else
		ft_comm_go2(sol, a);
}
