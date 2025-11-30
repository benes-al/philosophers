/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:04:12 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/30 02:04:13 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fd_putstr(char *message)
{
	int	i;

	i = 0;
	if (!message)
		return ;
	while (message[i])
	{
		write(2, &message[i], 1);
		i++;
	}
}

void	ft_error_exit(char *message)
{
	fd_putstr("Error:");
	fd_putstr(message);
	fd_putstr("\n");
	exit(1);
}
