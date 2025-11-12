/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:41:18 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/12 22:25:50 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "philo.h"
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

void init_table(t_table *table, int argc, char **argv)
{
	table->nbr_of_philos = argv[1];
	table->time_to_die = argv[2];
	table->time_to_eat = argv[3];
	table->time_to_sleep = argv[4];
	if	(argc == 6)
		table->nbr_of_meals_to_eat = argv[5];
	
		
	
}
int 	main(int argc, char **argv)
{
	
		
	t_table table;
	
	check_args(argc, argv);
	(void) memset(&table, 0, sizeof(t_table));

	init_table(&table, argc, argv);
	
	return (0);
}
