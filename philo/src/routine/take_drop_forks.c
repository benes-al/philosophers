/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_drop_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:57:31 by benes-al          #+#    #+#             */
/*   Updated: 2025/12/01 12:32:16 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_state_change(philo, FORKS, CYAN);
		pthread_mutex_lock((philo->right_fork));
		print_state_change(philo, FORKS, CYAN);
	}
	else
	{
		pthread_mutex_lock((philo->right_fork));
		print_state_change(philo, FORKS, CYAN);
		pthread_mutex_lock(philo->left_fork);
		print_state_change(philo, FORKS, CYAN);
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
