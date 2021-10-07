/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:41:44 by jchene            #+#    #+#             */
/*   Updated: 2021/10/07 02:42:22 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_stack	*get_stack(void)
{
	static t_stack	stack;

	if (stack.init == 0)
	{
		ft_bzero(&stack, sizeof(t_stack));
		stack.init = 1;
	}
	return (&stack);
}

void	decode(void)
{
	int		i;
	char	c;
	int		power;

	i = 0;
	c = 0;
	power = 1;
	while (i < 7)
	{
		c = c + ((get_stack()->chr[i] - '0') * power);
		power = power * 2;
		i++;
	}
	write(1, &c, 1);
}

void	get_sig(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (sig == SIGUSR1)
		get_stack()->chr[get_stack()->bit] = '1';
	else if (sig == SIGUSR2)
		get_stack()->chr[get_stack()->bit] = '0';
	else
		return ;
	get_stack()->bit++;
	kill(info->si_pid, SIGUSR1);
	if (get_stack()->bit >= 7)
	{
		get_stack()->bit = 0;
		decode();
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = (void *)get_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	get_stack()->bit = 0;
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
