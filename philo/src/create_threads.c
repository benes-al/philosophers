/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:56:28 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/15 16:45:55 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_table *table)
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
