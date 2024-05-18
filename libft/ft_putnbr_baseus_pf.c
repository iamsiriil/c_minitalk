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

void	ft_putnbr_baseus_pf(unsigned long int nb, char *base, int *len)
{
	if (!(void *)nb)
		ft_putstr_pf("(nil)", len);
	else
	{
		ft_putchar_pf('0', len);
		ft_putchar_pf('x', len);
		ft_putaddr_pf(nb, base, len);
	}
}
