/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:37:05 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/15 15:59:00 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/******************************************************************************/
/*                              Standard libraries                            */
/******************************************************************************/

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

/******************************************************************************/
/*                               MACROS                                       */
/******************************************************************************/

/******************************************************************************/
/*                               STRUCTS                                      */
/******************************************************************************/

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


/******************************************************************************/
/*                               ENUMS                                        */
/******************************************************************************/

typedef enum 
{
	RED          = 31,
    GREEN        = 32,
    BLUE         = 34,
	SOME		 = 0,
    WHITE        = 37,
    BRIGHT_YELLOW  = 93,
}	AnsiColor;

/******************************************************************************/
/*                               UTILS                                        */
/******************************************************************************/

int		atoi_mod(const char *argv);
void	cleanup(t_table *table);
void	ft_error_exit(char *message);
long	timestamp(void);

/******************************************************************************/
/*                               PARSER                                       */
/******************************************************************************/

void	check_args(int argc, char **argv);

/******************************************************************************/
/*                                 INIT                                       */
/******************************************************************************/

void	init_table(t_table *table, int argc, char **argv);



#endif PHILO_H