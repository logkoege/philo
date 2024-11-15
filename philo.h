/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:10:53 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/15 17:35:32 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

// Structure de configuration de la simulation
typedef struct s_config
{
	int	p;					// = 1 so philo est malloc, 0 si non
	int	f;					// = 1 so forks est malloc, 0 si non
	int	num_philosophers;	// Nombre de philosophes
	int	time_to_die;		// Temps avant de mourir
	int	time_to_eat;		// Temps pour manger
	int	time_to_sleep;		// Temps pour dormir
	int	num_meals;			// Nombre de repas
}	t_config;

// Structure représentant un philosophe
typedef struct s_thread
{
	int					id;				// Identifiant du philosophe
	pthread_t			thread;			// Thread du philosophe
	pthread_mutex_t		*left_fork;		// Pointeur vers la fourchette gauche
	pthread_mutex_t		*right_fork;	// Pointeur vers la fourchette droite
	long long			start_time;		// Temps de début
	int					meals_eaten;	// Nombre de repas mangés
	t_config			*config;		// Pointeur vers la configuration
}	t_thread;

// philo_utils.c
int			ft_atoi(char *str);
int			alloc(t_thread **philo, pthread_mutex_t **forks, t_config *config);
void		free_fp(t_thread *philo, pthread_mutex_t *forks, t_config *config);
void		init_thread(t_thread **philo, pthread_mutex_t *forks, t_config *config);

// philo_parsing.c
int			pars_arg(int argc, char **argv, t_config *config);

// init.c
int			init_philo(t_thread *philo, t_config *config, pthread_mutex_t *forks);
int			init_mutex(pthread_mutex_t *forks, int num_philosophers);
void		init_config(t_config *config);
int			init(t_thread *philo, t_config *config, pthread_mutex_t *forks);

//philo_utils2.c
long long	get_time(void)


#endif
