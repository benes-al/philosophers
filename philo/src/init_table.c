/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:28:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/27 19:31:47 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void init_fork(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philos);
	if(!table->forks)
		ft_error_exit("malloc forks failure");
	while(i < table->nbr_of_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		{
			cleanup(table);
			ft_exit_error("Failed to init forks mutex.");
		}	
		i++;
	}
}

static void init_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philos);
	if(!table->philos)
	{
		cleanup(table);
		ft_error_exit("malloc philos failure");
	}	
	while(i < table->nbr_of_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].last_meal = -1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork =
			&table->forks[(i + 1) % (table->nbr_of_philos)];
		table->philos[i].table = table;
		i++;			
	}
}

void init_table(t_table *table, int argc, char **argv)
{
	table->nbr_of_philos = argv[1];
	table->time_to_die = argv[2];
	table->time_to_eat = argv[3];
	table->time_to_sleep = argv[4];
	if	(argc == 6)
		table->nbr_of_meals_to_eat = argv[5];
	else
		table->nbr_of_meals_to_eat = -1;
	pthread_mutex_init(&table->print_state_change_mutex, NULL);
	{
		cleanup(table);
		ft_exit_error("Failed to init print_state_change_mutex mutex.");
	}
	pthread_mutex_init(&table->simulation_should_end_mutex, NULL);
	{
		cleanup(table);
		ft_exit_error("Failed to init simulation_should_end_mutex mutex.");
	}
	pthread_mutex_init(&table->meal_mutex, NULL);
	{
		cleanup(table);
		ft_exit_error("Failed to init meal mutex.");
	}
	init_forks(table);
	init_philos(table);
}
