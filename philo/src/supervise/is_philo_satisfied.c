/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_satisfied.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:41:06 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/30 11:55:20 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_philo_satisfied(t_table *table, int philo_index)
{
	int	meals_eaten;

	pthread_mutex_lock(&table->meal_mutex);
	meals_eaten = table->philos[philo_index].meals_eaten;
	pthread_mutex_unlock(&table->meal_mutex);
	if (meals_eaten == table->nbr_of_meals_to_eat)
		return (1);
	else
		return (0);
}
