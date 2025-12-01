/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:28:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/12/01 12:41:06 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philos);
	if (!table->forks)
		ft_error_exit("malloc forks failure");
	while (i < table->nbr_of_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			cleanup(table);
			ft_error_exit("Failed to init forks mutex.");
		}
		table->forks_initialized++;
		i++;
	}
}

static void	init_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->print_state_change_mutex, NULL) != 0)
	{
		cleanup(table);
		ft_error_exit("Failed to init print_state_change_mutex mutex.");
	}
	table->print_state_change_mutex_initialized = 1;
	if (pthread_mutex_init(&table->simulation_should_end_mutex, NULL) != 0)
	{
		cleanup(table);
		ft_error_exit("Failed to init simulation_should_end_mutex mutex.");
	}
	table->simulation_should_end_mutex_initialized = 1;
	if (pthread_mutex_init(&table->meal_mutex, NULL) != 0)
	{
		cleanup(table);
		ft_error_exit("Failed to init meal mutex.");
	}
	table->meal_mutex_initialized = 1;
}

static void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philos);
	if (!table->philos)
	{
		cleanup(table);
		ft_error_exit("malloc philos failure");
	}
	while (i < table->nbr_of_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].last_meal = 0;
		table->philos[i].meals_eaten = 0;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork
			= &table->forks[(i + 1) % (table->nbr_of_philos)];
		table->philos[i].table = table;
		i++;
	}
}

void	init_table(t_table *table, int argc, char **argv)
{
	table->nbr_of_philos = atoi(argv[1]);
	table->time_to_die = atoi(argv[2]);
	table->time_to_eat = atoi(argv[3]);
	table->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		table->nbr_of_meals_to_eat = atoi(argv[5]);
	else
		table->nbr_of_meals_to_eat = -1;
	init_mutexes(table);
	init_forks(table);
	init_philos(table);
}
