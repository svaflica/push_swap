/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:19:47 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/08 10:58:18 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_dig(int n, int base)
{
	int res;

	res = 0;
	while (n)
	{
		res++;
		n /= base;
	}
	return (res);
}

static void		turn_into_char(char *res, int n, int base, int num_d)
{
	char	*buf;
	int		sign;

	buf = "0123456789abcdef";
	sign = 1;
	if (n < 0)
		sign = -1;
	res[num_d--] = '\0';
	while (n)
	{
		res[num_d--] = buf[(n % base) * sign];
		n /= base;
	}
}

char			*ft_itoa_base(int n, int base)
{
	char	*res;
	int		num_d;

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 || n == 0)
		res = ft_itoa(n);
	else
	{
		num_d = num_dig(n, base);
		if (!(res = (char *)malloc(sizeof(char) * (num_d + 1))))
			return (NULL);
		turn_into_char(res, n, base, num_d);
	}
	return (res);
}
