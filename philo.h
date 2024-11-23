/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:10:53 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/23 18:09:00 by logkoege         ###   ########.fr       */
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

// Struct config
typedef struct s_config
{
	int				check_meals;		// Compteur de repas
	int				dead;				// Bool pour la mort des philo
	int				j;					// Sert a rien pour l'instant
	int				i;					// Compteur pour les pthread_join
	int				p;					// = 1 so philo est malloc, 0 si non
	int				f;					// = 1 so forks est malloc, 0 si non
	int				num_philosophers;	// Nombre de philo
	int				time_to_die;		// Temps avant de mourir
	int				time_to_eat;		// Temps pour manger
	int				time_to_sleep;		// Temps pour dormir
	long long		last_meal;			// Dernier repas mangé (temps)
	pthread_mutex_t	status;				// Autre mutex pour les repas
	pthread_mutex_t	printf;				// Mutex pour les printf
	pthread_mutex_t	dead_mutex;			// Mutex pour la mort
	pthread_mutex_t	meal;				// Mutex pour les repas
	int				num_meals;			// Nombre de repas
	long long		start_time;			// Debut de la sumilation
}	t_config;

// Struct philo
typedef struct s_thread
{
	int				id;				// Identifiant du philosophe
	pthread_t		thread;			// Thread du philosophe
	pthread_mutex_t	*left_fork;		// Fourchette gauche
	pthread_mutex_t	*right_fork;	// Fourchette droite
	int				meals_eaten;	// Nombre de repas mangés
	t_config		*config;		// Pointeur vers la config
}	t_thread;

// philo_utils.c
int			ft_atoi(char *str);
int			alloc(t_thread **philo, pthread_mutex_t **forks, t_config *config);
void		free_fp(t_thread *philo, pthread_mutex_t *forks, t_config *config);
void		init_thread(t_thread **philo, pthread_mutex_t *forks,
				t_config *config);
void		*philo_routine(void *arg);

// philo_parsing.c
int			pars_arg(int argc, char **argv, t_config *config);
int			if_1_philo(t_config *config);
int			fork_muting(t_thread *philo);

// init.c
int			init_philo(t_thread *philo, t_config *config,
				pthread_mutex_t *forks);
int			init_mutex(pthread_mutex_t *forks, int num_philosophers);
void		init_config(t_config *config);
int			init(t_thread *philo, t_config *config, pthread_mutex_t *forks);

//philo_utils2.c
long long	get_time(void);
int			ft_usleep(long int time);
int			is_alive(t_thread *philo);
void		while_dead_0(t_thread *philo, t_config *config);
//int			nb_of_meal(t_thread *philo);

// philo_things.c
int			philo_eating(t_thread *philo);
int			philo_sleeping(t_thread *philo);
int			philo_thinking(t_thread *philo);
int			philo_is_alive(t_thread **philo);
int			printf_lock(t_thread *philo, char *msg);

#endif