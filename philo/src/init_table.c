/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:28:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/30 22:13:52 by benes-al         ###   ########.fr       */
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
		pthread_mutex_init(&table->forks[i], NULL);
		{
			cleanup(table);
			ft_error_exit("Failed to init forks mutex.");
		}
		i++;
	}
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
		table->philos[i].last_meal = -1;
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
	pthread_mutex_init(&table->print_state_change_mutex, NULL);
	{
		cleanup(table);
		ft_error_exit("Failed to init print_state_change_mutex mutex.");
	}
	pthread_mutex_init(&table->simulation_should_end_mutex, NULL);
	{
		cleanup(table);
		ft_error_exit("Failed to init simulation_should_end_mutex mutex.");
	}
	pthread_mutex_init(&table->meal_mutex, NULL);
	{
		cleanup(table);
		ft_error_exit("Failed to init meal mutex.");
	}
	init_forks(table);
	init_philos(table);
}





typedef struct s_table
{
    int nbr_of_philos;
    pthread_t *threads;
    t_philo *philos;
    pthread_mutex_t *forks;

    pthread_mutex_t print_mutex;
    pthread_mutex_t sim_mutex;
    pthread_mutex_t meal_mutex;

    int forks_initialized;
    int print_mutex_initialized;
    int sim_mutex_initialized;
    int meal_mutex_initialized;

    int threads_created;

    // ... other fields ...
}   t_table;


int init_table(t_table *table, int argc, char **argv)
{
    table->forks_initialized = 0;
    table->print_mutex_initialized = 0;
    table->sim_mutex_initialized = 0;
    table->meal_mutex_initialized = 0;
    table->threads_created = 0;

    table->nbr_of_philos = atoi(argv[1]);

    table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philos);
    table->threads = malloc(sizeof(pthread_t) * table->nbr_of_philos);
    table->philos = malloc(sizeof(t_philo) * table->nbr_of_philos);

    if (!table->forks || !table->threads || !table->philos)
        return (1);

    // Init forks one by one
    for (int i = 0; i < table->nbr_of_philos; i++)
    {
        if (pthread_mutex_init(&table->forks[i], NULL) != 0)
            return (1);
        table->forks_initialized++;
    }

    // Init other mutexes (each tracked)
    if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
        return (1);
    table->print_mutex_initialized = 1;

    if (pthread_mutex_init(&table->sim_mutex, NULL) != 0)
        return (1);
    table->sim_mutex_initialized = 1;

    if (pthread_mutex_init(&table->meal_mutex, NULL) != 0)
        return (1);
    table->meal_mutex_initialized = 1;

    return (0); // All good
}


void destroy_mutexes(t_table *table)
{
    for (int i = 0; i < table->forks_initialized; i++)
        pthread_mutex_destroy(&table->forks[i]);

    if (table->print_mutex_initialized)
        pthread_mutex_destroy(&table->print_mutex);

    if (table->sim_mutex_initialized)
        pthread_mutex_destroy(&table->sim_mutex);

    if (table->meal_mutex_initialized)
        pthread_mutex_destroy(&table->meal_mutex);
}


void cleanup(t_table *table)
{
    destroy_mutexes(table);

    free(table->forks);
    free(table->threads);
    free(table->philos);
}
