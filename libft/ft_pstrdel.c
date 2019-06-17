/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 23:58:28 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/26 23:58:30 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_pstrdel(void **ap)
{
	/*while (*ap)
		ft_memdel(ap++);
	ft_memdel(ap);
	return (NULL);*/
	int i;

	i = -1;
	while (ap[++i])
	{
		ft_memdel(&ap[i]);
	}
	ft_memdel(ap);
	return (NULL);
}
