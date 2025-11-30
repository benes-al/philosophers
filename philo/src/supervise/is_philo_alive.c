/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_alive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:10:23 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/30 11:54:35 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_philo_alive(t_table *table, int philo_index)
{
	long	last_meal;

	pthread_mutex_lock(&table->meal_mutex);
	last_meal = table->philos[philo_index].last_meal;
	pthread_mutex_unlock(&table->meal_mutex);
	if (timestamp() - last_meal >= table->time_to_die)
		return (0);
	else
		return (1);
}
