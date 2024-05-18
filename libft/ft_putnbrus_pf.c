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

void	ft_putnbrus_pf(unsigned int nbr, int *len)
{
	if (nbr > 9)
	{
		ft_putnbr_pf(nbr / 10, len);
		ft_putnbr_pf(nbr % 10, len);
	}
	else
		ft_putchar_pf(nbr + '0', len);
}
