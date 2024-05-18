/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:02:21 by toantune          #+#    #+#             */
/*   Updated: 2023/04/18 14:18:26 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_pf(unsigned int nb, char *base, int *len)
{
	if (nb == 0)
	{
		ft_putchar_pf('0', len);
		return ;
	}
	else if (nb != 0)
	{
		if (nb / ft_strlen(base) != 0)
			ft_putnbr_base_pf(nb / ft_strlen(base), base, len);
		ft_putchar_pf(base[nb % ft_strlen(base)], len);
	}
}
