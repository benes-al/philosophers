/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value_simulation_should_end.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:37:04 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/29 16:44:59 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_value_simulation_should_end(t_table *table)
{
	pthread_mutex_lock(&table->simulation_should_end_mutex);
	table->simulation_should_end = 1;
	pthread_mutex_unlock(&table->simulation_should_end_mutex);
}
