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

static int 	ft_check_readed(char *str)
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

static char	**ft_read(t_pair_stack *p, char *name)
{
	char		*str;
	char		*buf;
	char 		*tmp;
	char 		**res;
	int 		fd;

	fd = 0;
	if (name)
		if ((fd = open(name, O_RDONLY)) < 0 || read(fd, NULL, 0) == -1)
			return (NULL);
	if (!(buf = ft_strnew(100000)))
	{
		ft_stack_del(&(p->a));
		ft_stack_del(&(p->b));
		return (NULL);
	}
	str = NULL;
	while (read(fd, buf, 100000))
	{
		tmp = str;
		str = ft_strjoin(str, buf);
		tmp ? ft_strdel(&tmp) : NULL;
	}
	fd > 0 ? close(fd) : 0;
	if (!ft_check_readed(str))
		res = ft_strsplit("fuck\n", '\n');
	else
		res = ft_strsplit(str, '\n');
	ft_strdel(&buf);
	ft_strdel(&str);
	return (res);
}

int		main(int c, char **v)
{
	t_pair_stack	*p;
	int				cou;
	char 			*name;

	if (c == 1)
		return (-1);
	name = NULL;
	if (!ft_strcmp(v[1], "-f"))
	{
		name = v[2];
		v += 2;
		c -= 2;
	}
	if (!ft_is_arg_valid(v + 1))
		return(write(1, "Error\n", 6));
	else if (!(p = ft_pair_stack_new()))
		return(write(1, "Error\n", 6));
	while (--c)
	{
		cou = ft_atoi(v[c]);
		if ((cou == -1 && ft_strcmp(v[c], "-1") != 0) ||
			(cou == 0 && ft_strcmp(v[c], "0") != 0) ||
			ft_is_in_stack(p->a, cou))
		{
			ft_stack_del(&(p->a));
			ft_stack_del(&(p->b));
			ft_memdel((void **)&p);
			return (write(1, "Error\n", 6));
		}
		else
			ft_stack_push(&(p->a), ft_stack_new(cou));
	}
	cou = checker(p->a, p->b, ft_read(p, name));
	if (cou == 1)
		write(1, "OK\n", 3);
	else if (cou == 0)
		write(1, "KO\n", 3);
	else if (cou == -1)
		write(1, "Error\n", 6);
	ft_memdel((void **)&p);
	return (0);
}