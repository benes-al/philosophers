/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:20:01 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/29 14:13:00 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philos)
{
	t_philo *philo;

	philo = (t_philo *) philos;
	if (philo->table->nbr_of_philos == 1)
	{
		print_state_change(philo, FORKS, WHITE);
		return(NULL);
	}
	while (!read_value_simulation_should_end(&philo->table))
	{
		eating(philo);
		if (read_value_simulation_should_end(&philo->table))
			return (NULL);
		sleeping(philo);
		if (read_value_simulation_should_end(&philo->table))
			return (NULL);
		thinking(philo);
		if (read_value_simulation_should_end(&philo->table))
			return (NULL);
		if (philo->id % 2 != 0 && philo->table->nbr_of_philos % 2 != 0)
			usleep(1000);
	}
	return (NULL);
}
