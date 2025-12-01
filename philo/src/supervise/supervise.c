/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:18:25 by benes-al          #+#    #+#             */
/*   Updated: 2025/12/01 12:39:10 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	supervise(t_table *table)
{
	int	i;
	int	satisfied_philos;

	while (1)
	{
		i = -1;
		satisfied_philos = 0;
		while (++i < table->nbr_of_philos)
		{
			if (!is_philo_alive(table, i))
			{
				print_state_change(&table->philos[i], DIED, RED);
				change_boolean_simulation_should_end(table);
				return ;
			}
			if (table->nbr_of_meals_to_eat > 0 && is_philo_satisfied(table, i))
				satisfied_philos++;
		}
		if (satisfied_philos == table->nbr_of_philos)
		{
			change_boolean_simulation_should_end(table);
			return ;
		}
		usleep(1000);
	}
}
