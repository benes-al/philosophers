/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:18:25 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/29 17:17:56 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	supervise(t_table *table)
{
	int	philo_index;
	int satisfied_philos;
	
	while (1)
	{
		philo_index = 0;
		satisfied_philos = 0;
		while (philo_index < table->nbr_of_philos)
		{
			if (!is_philo_alive(table, philo_index))
			{
				change_value_simulation_should_end(table);	
				print_state_change(table->philos[philo_index].id, DIED, RED);
				return ;
			}
			if (table->nbr_of_meals_to_eat > 0 && 
				is_philo_satisfied(table, philo_index))
				satisfied_philos++;
			philo_index++;
		}
		if (satisfied_philos == table->nbr_of_philos)
		{
			change_value_simulation_should_end(table);
			return ;
		}
		usleep(1000);
	}
}
