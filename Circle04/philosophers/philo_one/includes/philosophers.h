/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:48:10 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 10:13:24 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define ACTIVITY 0
# define DIED 1
# define FULL 2

# define SUCCESS 0
# define FAILURE -1

# define NUMBER_OF_ARG -1
# define NUMERIC_ARG -2
# define MALLOC -3
# define PTHREAD -4
# define MUTEX -5

typedef struct		s_mutex
{
	pthread_mutex_t	*fork_m;
	pthread_mutex_t print_m;
	pthread_mutex_t state_m;
	pthread_mutex_t eat_m;
}					t_mutex;

typedef struct		s_info
{
	int				number_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	int				state;
	long			num_of_eat;
}					t_info;

typedef struct		s_philosopher
{
	pthread_t		thread;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	t_mutex			*mutex;
	t_info			*info;
	int				philo_num;
	long			last_philo;
	long			start_time;
}					t_philosopher;

/*
**	main.c
*/
long				get_time(void);
int					print_state(const char *str, t_philosopher *philo);

/*
**	init.c
*/
int					info_init(t_info *info, const char **argv);
t_philosopher		*pthread_init(t_info *info, t_mutex *mutex);
int					mutex_init(t_mutex *mutex, t_info *info);

/*
**	exit.c
*/
void				destroy_pthread_philo(t_philosopher *philo,
		t_mutex *mutex, t_info *info);
int					print_error(int error);

/*
**	state.c
*/
void				philosopher_eat(t_philosopher *philo);
void				*print_state_died(void *philo);
void				*print_state_full(void *philo);

/*
**	utils.c
*/
int					ft_atoi(const char *str);
int					ft_isdigit(int c);

#endif
