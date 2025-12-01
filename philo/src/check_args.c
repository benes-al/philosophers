/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:37:16 by benes-al          #+#    #+#             */
/*   Updated: 2025/12/01 12:40:15 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_argc(const int argc)
{
	if (argc < 5 || argc > 6)
		ft_error_exit("invalid number of arguments");
}

static void	check_argv(const int argc, const char **argv)
{
	if (atoi_mod(argv[1]) < 0 || atoi_mod(argv[2]) < 0
		|| atoi_mod(argv[3]) < 0 || atoi_mod(argv[4]) < 0)
		ft_error_exit("invalid argument");
	if (argc == 6 && atoi_mod(argv[5]) < 0)
		ft_error_exit("invalid argument");
}

static void	check_argv_values(const int argc, const char **argv)
{
	if (atoi_mod(argv[1]) < 1 || atoi_mod(argv[2]) < 1
		|| atoi_mod(argv[3]) < 1 || atoi_mod(argv[4]) < 1)
		ft_error_exit("invalid value");
	if (argc == 6 && atoi_mod(argv[5]) == 0)
		return ;
}

void	check_args(int argc, char **argv)
{
	check_argc(argc);
	check_argv(argc, (const char **)argv);
	check_argv_values(argc, (const char **)argv);
}
