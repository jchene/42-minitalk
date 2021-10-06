/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:42:47 by jchene            #+#    #+#             */
/*   Updated: 2021/10/06 22:01:02 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void			nothing(int sig)
{
	(void)sig;
}

void			encode(int c, pid_t pid)
{
	int			power;
	int			old_c;

	old_c = c;
	while (c > 0)
	{
		usleep(250);
		if (c % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		c = c / 2;
	}
	power = 64;
	while ((old_c < power) && (power > 0))
	{
		usleep(250);
		kill(pid, SIGUSR2);
		pause();
		power = power / 2;
	}
}

int			main(int argc, char **argv)
{
	pid_t	pid;
	int		len;
	int		i;

	if (argc != 3)
		return (ft_putstrn("Wrong number of arguments!\n", 27));
	len = ft_strlen(argv[2]);
	if (len == 0)
		return (ft_putstrn("Empty string!\n", 14));
	i = 0;
	pid = atoi(argv[1]);
	signal(SIGUSR1, nothing);
	while (i < len)
		encode((int)argv[2][i++], pid);
	return (0);
}