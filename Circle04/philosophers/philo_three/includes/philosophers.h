/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:09:55 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 10:16:50 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
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
# define SEMAPHORE -5

typedef struct		s_semaphore
{
	sem_t			*fork_s;
	sem_t			*print_s;
	sem_t			*main_s;
	sem_t			*philo_s;
	sem_t			*eat_s;
}					t_semaphore;

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
	pid_t			*pid;
	t_semaphore		*semaphore;
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
void				philosopher_init(t_philosopher *philo, t_info *info,
		t_semaphore *semaphore);
int					semaphore_init(t_semaphore *semaphore, t_info *info);

/*
**	exit.c
*/
void				destroy_semaphore_philo(t_philosopher *philo);
void				wait_and_exit(t_philosopher *philo);
int					print_error(int error);

/*
**	state.c
*/
void				*change_main_state(void *philo);
void				*change_philo_state(void *philo);
void				*print_state_died(void *philo);
void				*print_state_full(void *philo);
void				philosopher_eat(t_philosopher *philo);

/*
**	utils.c
*/
int					ft_atoi(const char *str);
int					ft_isdigit(int c);

#endif
