/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:56:28 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/15 18:15:33 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_table *table)
{
	int i;

	i = 0;
	table->start_time = timestamp() + 10;
	while (i < table->nbr_of_philos)
	{
		pthread_create(&table->philos[i].thread, NULL, routine, &table->philos[i]);
		i++;
	}
}
