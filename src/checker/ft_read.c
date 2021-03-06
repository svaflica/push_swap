/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:17:30 by djeanna           #+#    #+#             */
/*   Updated: 2019/06/08 15:17:32 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int					ft_check_readed(char *str)
{
	if (!str)
		return (1);
	if (*str == '\n')
		return (0);
	while (*str)
	{
		if (*str == '\n' && *(str + 1) == '\n')
			return (0);
		str++;
	}
	if (*(str - 1) != '\n')
		return (0);
	else
		return (1);
}

static char			**ft_check(char **str)
{
	char **res;

	if (!ft_check_readed(*str))
		res = ft_strsplit("fuck\n", '\n');
	else
		res = ft_strsplit(*str, '\n');
	ft_strdel(str);
	return (res);
}

static char			**ft_dele(t_stack **a, t_stack **b)
{
	ft_stack_del(a);
	ft_stack_del(b);
	return (NULL);
}

char				**ft_read(t_pair_stack *p, char *name)
{
	char		*str;
	char		*buf;
	char		*tmp;
	int			fd;

	fd = 0;
	if (name)
		if ((fd = open(name, O_RDONLY)) < 0 || read(fd, NULL, 0) == -1)
			return (NULL);
	if (!(buf = ft_strnew(10000)))
		return (ft_dele(&(p->a), (&p->b)));
	str = NULL;
	while (read(fd, buf, 10000))
	{
		tmp = str;
		str = ft_strjoin(str, buf);
		tmp ? ft_strdel(&tmp) : NULL;
		ft_bzero(buf, 10000);
	}
	fd > 0 ? close(fd) : 0;
	ft_strdel(&buf);
	return (ft_check(&str));
}
