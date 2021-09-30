/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:41:44 by jchene            #+#    #+#             */
/*   Updated: 2021/09/30 04:27:05 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

t_stack		*get_stack(void)
{
    static t_stack    stack;

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
	if (c == 0)
		write(1, "\n", 1);
	else
		write(1, &c, 1);
}

void	get_sig(int sig)
{
	(void)sig;
	if (sig == 10)
		get_stack()->chr[get_stack()->bit] = '1';
	else
		get_stack()->chr[get_stack()->bit] = '0';
	get_stack()->bit++;
	if (get_stack()->bit >= 7)
	{
		get_stack()->bit = 0;
		decode();
	}
}

int		main(void)
{
	struct		sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &get_sig;
	get_stack()->bit = 0;
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1);
}