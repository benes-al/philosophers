/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:20:01 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/15 18:14:07 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philos)
{
	t_philo *philo;
	
	philo = (t_philo *) philos;
	while(timestamp < philo->table->start_time)
		usleep(50);
	
	return (NULL);
}
