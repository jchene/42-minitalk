/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:03:29 by jchene            #+#    #+#             */
/*   Updated: 2021/09/30 01:55:14 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstrn(char *str, int n)
{
	int		i;

	i = 0;
	while (i < n)
		ft_putchar(str[i++]);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int nb) {
	if (nb < 0) 
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) 
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)b;
	while (n-- > 0)
		*(ptr++) = 0;
}