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

void	ft_putaddr_pf(unsigned long int nb, char *base, int *len)
{
	if (nb > 15)
	{
		ft_putaddr_pf(nb / 16, base, len);
		ft_putaddr_pf(nb % 16, base, len);
	}
	else
		ft_putchar_pf(base[nb], len);
}
