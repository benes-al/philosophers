/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:41:18 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/13 18:30:09 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_table
{
	int				nbr_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nbr_of_meals_to_eat;
	long			start_time;
	int				simulation_should_end;
	pthread_mutex_t	monitoring_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
}				t_table;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			last_meal;
	int				meals_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
}	t_philo;

long	timestamp(void)
{
	struct timeval	current_time;
	
	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	cleanup(t_table *table)
{
	destroy_mutexes(table);
	free(table->forks);
	free(table->philos);
}

void init_philo(t_table *table)
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

void init_fork(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philos);
	if(!table->forks)
		ft_error_exit("malloc forks failure");
	while(i < table->nbr_of_philos)
		pthread_mutex_init(&table->forks[i++], NULL);
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
	pthread_mutex_init(&table->monitoring_mutex, NULL);
	pthread_mutex_init(&table->last_meal_mutex, NULL);
	init_forks(table);
	init_philos(table);
}
int 	main(int argc, char **argv)
{
	t_table table;
	
	check_args(argc, argv);
	(void) memset(&table, 0, sizeof(t_table));

	init_table(&table, argc, argv);
	
	return (0);
}
