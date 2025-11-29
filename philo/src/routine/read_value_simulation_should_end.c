/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_value_simulation_should_end.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:34:48 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/29 14:31:41 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief  Safely checks whether the simulation should end.
///         The value of `simulation_should_end` is protected by a mutex so
///         that all threads can read it without causing a data race.
/// @param  table Pointer to the main simulation structure containing the flag.
/// @return 1 if the simulation should end, otherwise 0.
bool	read_boolean_simulation_should_end(t_table *table)
{
	bool	value;

	pthread_mutex_lock(&table->simulation_should_end_mutex);
		value = table->simulation_should_end;
	pthread_mutex_unlock(&table->simulation_should_end_mutex);
	return (value);
}
