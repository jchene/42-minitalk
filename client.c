/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:42:47 by jchene            #+#    #+#             */
/*   Updated: 2021/09/30 04:30:18 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	encode(int c, pid_t pid)
{
	int		power;
	int		old_c;

	old_c = c;
	while (c > 0)
	{
		if (c % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c / 2;
		pause();
	}
	power = 64;
	while ((old_c < power) && (power > 0))
	{
		kill(pid, SIGUSR2);
		power = power / 2;
		pause();
	}
}

int		main(int argc, char **argv)
{
	pid_t	pid;
	int		len;
	int		i;

	(void)argc;
	i = 0;
	ft_putnbr(getpid());
	ft_putchar('\n');
	pid = atoi(argv[1]);
	len = ft_strlen(argv[2]);
	while (i < len)
		encode((int)argv[2][i++], pid);
	encode('\0', pid);
	return (0);
}