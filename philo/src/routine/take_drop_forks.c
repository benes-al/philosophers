/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_drop_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:57:31 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/26 22:31:52 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_state_change(philo, FORKS, WHITE);
		pthread_mutex_lock((philo->right_fork));
		print_state_change(philo, FORKS, WHITE);
	}
	else
	{
		pthread_mutex_lock((philo->right_fork));
		print_state_change(philo, FORKS, WHITE);
		pthread_mutex_lock(philo->left_fork);
		print_state_change(philo, FORKS, WHITE);
	}
}

void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock((philo->right_fork));
	}
	else
	{
		pthread_mutex_unlock((philo->right_fork));
		pthread_mutex_unlock(philo->left_fork);
	}
}
