/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:47:03 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/20 18:36:10 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pars_arg(int argc, char **argv)
{
	int	i;
	int	ii;

	ii = 1;
	if (argc < 4 || argc > 5)
	{
		printf("Error -> invalid number of argc (must be 4 or 5)");
		printf(" not -> (%d)\n", argc);
		return (1);
	}
	while (ii < argc)
	{
		i = ft_atoi(argv[ii]);
		if (i > 0)
			ii++;
		else
		{
			printf("Error -> invalid argc value (must be > 0)");
			printf(" not -> (%d)\n", i);
			return (1);
		}
	}
	return (0);
}
