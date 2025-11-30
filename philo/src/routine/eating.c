/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:20:28 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/30 11:58:12 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	long	time_to_eat;
	long	time_to_die;

	time_to_eat = philo->table->time_to_eat;
	time_to_die = philo->table->time_to_die;
	if (time_to_eat > time_to_die)
		time_to_eat = time_to_die;
	take_forks(philo);
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&philo->table->meal_mutex);
	print_state_change(philo, EATING, GREEN);
	usleep(time_to_eat * 1000);
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->table->meal_mutex);
	drop_forks(philo);
}
