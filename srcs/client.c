/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:42:47 by jchene            #+#    #+#             */
/*   Updated: 2021/10/15 16:22:04 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	*msg_status(void)
{
	static int	status;

	return (&status);
}

void	response(int sig)
{
	(void)sig;
	(*msg_status()) = 1;
}

void	ft_wait(void)
{
	while ((*msg_status() != 1))
		sleep (1);
}

void	encode(int c, pid_t pid)
{
	int			power;
	int			old_c;

	old_c = c;
	while (c > 0)
	{
		usleep(1);
		if (c % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		ft_wait();
		(*msg_status() = 0);
		c = c / 2;
	}
	power = 64;
	while ((old_c < power) && (power > 0))
	{
		usleep(1);
		kill(pid, SIGUSR2);
		ft_wait();
		(*msg_status() = 0);
		power = power / 2;
	}
}

int	main(int argc, char **argv)
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
	pid = small_atoi(argv[1]);
	(*msg_status()) = 0;
	signal(SIGUSR1, response);
	while (i < len)
		encode((int)argv[2][i++], pid);
	return (0);
}
