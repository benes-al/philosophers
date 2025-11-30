/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:56:28 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/30 12:02:09 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = timestamp();
	while (i < table->nbr_of_philos)
	{
		pthread_create(&table->philos[i].thread,
			NULL, routine, &table->philos[i]);
		if (pthread_create(&table->philos[i].thread,
				NULL, routine, &table->philos[i]) != 0)
		{
			cleanup(table);
			ft_error_exit("Failed to creat thread.");
		}
		i++;
	}
}
