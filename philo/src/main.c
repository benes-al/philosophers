/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:41:18 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/14 14:18:08 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int 	main(int argc, char **argv)
{
	t_table table;
	
	check_args(argc, argv);
	(void) memset(&table, 0, sizeof(t_table));

	init_table(&table, argc, argv);
	
	return (0);
}
