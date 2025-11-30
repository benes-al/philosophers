/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:29:27 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/30 02:03:24 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_table *table)
{
	int	fork_index;

	fork_index = 0;
	pthread_mutex_destroy(&table->simulation_should_end_mutex);
	pthread_mutex_destroy(&table->print_state_change_mutex);
	pthread_mutex_destroy(&table->meal_mutex);
	while (fork_index < table->nbr_of_philos)
	{
		pthread_mutex_destroy(&table->forks[fork_index]);
		fork_index++;
	}
}

void	cleanup(t_table *table)
{
	destroy_mutexes(table);
	free(table->forks);
	free(table->philos);
}
