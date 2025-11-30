/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_boolean_simulation_should_end.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:34:48 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/30 01:08:10 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	read_boolean_simulation_should_end(t_philo *philo)
{
	bool	value;

	pthread_mutex_lock(&philo->table->simulation_should_end_mutex);
	value = philo->table->simulation_should_end;
	pthread_mutex_unlock(&philo->table->simulation_should_end_mutex);
	return (value);
}
