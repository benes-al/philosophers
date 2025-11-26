/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:41:18 by benes-al          #+#    #+#             */
/*   Updated: 2025/11/26 19:12:47 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int 	main(int argc, char **argv)
{
	t_table table;
	
	check_args(argc, argv);
	(void) memset(&table, 0, sizeof(t_table));
	init_table(&table, argc, argv);
	create_threads(&table);
	supervise(&table);
	join_threads(&table);
	cleanup(&table);
	return (0);
}