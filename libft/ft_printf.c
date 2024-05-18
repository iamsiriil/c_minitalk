/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:56:49 by toantune          #+#    #+#             */
/*   Updated: 2023/08/09 13:50:33 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...);

// static void	conversionmng(char c, va_list args, int *len)
// {
// 	char	*base_x;
// 	char	*base_xx;

// 	base_x = "0123456789abcdef";
// 	base_xx = "0123456789ABCDEF";
// 	if (c == '%')
// 		ft_putchar_pf('%', len);
// 	else if (c == 'c')
// 		ft_putchar_pf(va_arg(args, int), len);
// 	else if (c == 's')
// 		ft_putstr_pf(va_arg(args, char *), len);
// 	else if (c == 'i' || c == 'd')
// 		ft_putnbr_pf(va_arg(args, int), len);
// 	else if (c == 'u')
// 		ft_putnbrus_pf(va_arg(args, unsigned int), len);
// 	else if (c == 'x')
// 		ft_putnbr_base_pf(va_arg(args, unsigned int), base_x, len);
// 	else if (c == 'X')
// 		ft_putnbr_base_pf(va_arg(args, unsigned int), base_xx, len);
// 	else if (c == 'p')
// 		ft_putnbr_baseus_pf(va_arg(args, unsigned long int), base_x, len);
// }

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		*ptr;

	va_start(args, format);
	ptr = &len;
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			conversionmng(*format, args, ptr);
		}
		else
			ft_putchar_pf(*format, ptr);
		format++;
	}
	va_end(args);
	return (len);
}
