/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:56:28 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/15 15:51:30 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philo.h"

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>


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

	long			start_time;

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

void	*routine(void *philos)
{
	t_philo *philo;
	
	philo = (t_philo *)philos;
	philo->start_time = timestamp();
	return (NULL);
}
void	create_thread(t_table *table)
{
	int i;

	i = 0;
	//philo->start_time = timestamp(void) + 10
	while (i < table->nbr_of_philos)
	{
		pthread_create(&table->philos[i].thread, NULL, routine, &table->philos[i]);
		i++;
	}
	
}
void join_thread(t_table *table)
{
	int i;
	
	i = 0;
	while(i < table->nbr_of_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;	
	}
}

int 	main(int argc, char **argv)
{
	t_table table;
	int i = 0;
	//check_args(argc, argv);
	(void) memset(&table, 0, sizeof(t_table));
	table.nbr_of_philos = 200;
	//init_table(&table, argc, argv);
	table.philos = malloc(sizeof(t_philo) * 200);
	create_thread(&table);
	join_thread(&table);
	while(i < table.nbr_of_philos)
	{
		printf("philo %i was created at: %ld\n", i, table.philos[i++].start_time);
	}
	return (0);
}