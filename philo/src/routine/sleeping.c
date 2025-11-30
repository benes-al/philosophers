/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:20:19 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/29 18:09:15 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	long	time_to_sleep;
	long	time_to_eat;
	long	time_to_die;
	
	time_to_sleep = philo->table->time_to_sleep;
	time_to_eat = philo->table->time_to_eat;
	time_to_die = philo->table->time_to_die;
	if(time_to_eat + time_to_sleep > time_to_die)
		time_to_sleep = time_to_die - time_to_eat; 
	print_state_change(philo, SLEEPING, BLUE);
	usleep(time_to_sleep * 1000);
}
