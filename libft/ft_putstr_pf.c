/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:16:34 by toantune          #+#    #+#             */
/*   Updated: 2023/04/18 13:23:07 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_pf(char *str, int *len)
{
	if (!str)
		ft_putstr_pf("(null)", len);
	else
	{
		while (*str)
		{
			ft_putchar_pf(*str, len);
			str++;
		}
	}
}
