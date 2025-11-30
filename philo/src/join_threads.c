/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:21:28 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/30 12:03:55 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		if (pthread_join(table->philos[i].thread, NULL) != 0)
		{
			cleanup(table);
			ft_error_exit("Failed to join thread.");
		}
		i++;
	}
}
