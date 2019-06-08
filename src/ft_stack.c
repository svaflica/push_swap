/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:57:22 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 20:57:23 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack			*ft_stack_new(size_t size)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->num = size;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int				ft_stack_push(t_stack **beg, t_stack *s)
{
	if (s == NULL)
		return (0);
	s->next = *beg;
	*beg != NULL ? (*beg)->prev = s : NULL;
	s->prev = NULL;
	*beg = s;
	return (1);
}

int				ft_stack_pop(t_stack **s)
{
	int			res;
	t_stack		*tmp;

	if (s == NULL || *s == NULL)
		return (0);
	res = (*s)->num;
	tmp = (*s);
	*s = (*s)->next;
	if (*s != NULL)
		(*s)->prev = NULL;
	ft_memdel((void **)&tmp);
	return (res);
}

void			ft_stack_del(t_stack **s)
{
	if (s && *s)
	{
		ft_stack_del(&((*s)->next));
		ft_memdel((void **)s);
	}
}
