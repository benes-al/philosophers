/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:22:16 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/26 20:56:43 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state_change(t_philo *philo, char *message, int ansi_color)
{
	long time;
	
	pthread_mutex_lock(&philo->table->print_mutex);
	if(!simulation_should_end(philo->table))
	{
		time = timestamp() - philo->table->start_time;	
		printf("\033[1;%dm%ld %d %s\033[0;0m\n",
			ansi_color, time,message);		
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}
