/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:37:05 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/30 01:47:03 by benes-al         ###   ########.fr       */
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
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

/******************************************************************************/
/*                               MACROS                                       */
/******************************************************************************/

# define FORKS    "has taken a fork"
# define EATING   "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED     " died"

/******************************************************************************/
/*                               ENUMS                                        */
/******************************************************************************/

typedef enum 
{
	RED			= 31,
	GREEN		= 32,
	BLUE		= 34,
	SOME		= 0,
	WHITE		= 37,
	YELLOW		= 93,
}	AnsiColor;

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
	pthread_mutex_t	simulation_should_end_mutex;
	pthread_mutex_t	print_state_change_mutex;
	pthread_mutex_t	meal_mutex;
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
/*                               UTILS                                        */
/******************************************************************************/

int		atoi_mod(const char *argv);
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
void	create_threads(t_table *table);

/******************************************************************************/
/*                                 ROUTINE                                    */
/******************************************************************************/

void	*routine(void *philos);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	print_state_change(t_philo *philo, char *message, int ansi_color);
bool	read_boolean_simulation_should_end(t_philo *philo);

/******************************************************************************/
/*                                 SUPERVISE                                  */
/******************************************************************************/

void	supervise(t_table *table);
bool	is_philo_satisfied(t_table *table, int philo_index);
bool	is_philo_alive(t_table *table, int philo_index);
void	change_boolean_simulation_should_end(t_table *table);

/******************************************************************************/
/*                                 CLEANUP                                    */
/******************************************************************************/

void	cleanup(t_table *table);
void	join_threads(t_table *table);

#endif