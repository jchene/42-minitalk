/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:27:11 by jchene            #+#    #+#             */
/*   Updated: 2021/10/06 21:21:13 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			MINITALK_H
# define		MINITALK_H
# include		<stdio.h>
# include		<unistd.h>
# include		<stdlib.h>
# include		<sys/types.h>
# include		<signal.h>

typedef struct	s_stack
{
	int			init;
	char		chr[7];
	int			bit;
}				t_stack;

void			ft_putchar(char c);
int				ft_putstrn(char *str, int n);
int				ft_strlen(char *str);
void			ft_putnbr(int nb);
void			ft_bzero(void *b, size_t n);
#endif