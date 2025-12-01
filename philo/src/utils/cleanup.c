/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:29:27 by benes-al          #+#    #+#             */
/*   Updated: 2025/12/01 12:39:34 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutexes(t_table *table)
{
	int	fork_index;

	fork_index = 0;
	if (table->print_state_change_mutex_initialized == 1)
		pthread_mutex_destroy(&table->print_state_change_mutex);
	if (table->simulation_should_end_mutex_initialized == 1)
		pthread_mutex_destroy(&table->simulation_should_end_mutex);
	if (table->meal_mutex_initialized == 1)
		pthread_mutex_destroy(&table->meal_mutex);
	while (fork_index < table->nbr_of_philos
		&& fork_index < table->forks_initialized)
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
