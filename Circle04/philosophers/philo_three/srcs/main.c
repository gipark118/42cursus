/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:34:56 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 10:17:55 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000L + time.tv_usec / 1000L);
}

int		print_state(const char *str, t_philosopher *philo)
{
	sem_wait(philo->semaphore->print_s);
	if (philo->info->state != DIED && philo->info->state != FULL)
	{
		printf("%ld philo%d %s", get_time() - philo->start_time,
				philo->philo_num, str);
	}
	sem_post(philo->semaphore->print_s);
	return (SUCCESS);
}

void	check_state(t_philosopher *philo)
{
	pthread_t	died;
	pthread_t	state;

	pthread_create(&died, NULL, &print_state_died, (void *)philo);
	pthread_detach(died);
	pthread_create(&state, NULL, &change_philo_state, (void *)philo);
	pthread_detach(state);
	while (philo->info->state != DIED && philo->info->state != FULL)
	{
		philosopher_eat(philo);
		print_state(" is sleeping.\n", philo);
		usleep(philo->info->time_to_sleep);
		print_state(" is thinking.\n", philo);
	}
}

int		create_process_philo(t_philosopher *philo, t_info *info)
{
	pthread_t	full;
	pthread_t	state;
	int			i;

	i = 0;
	while (i < info->number_of_philo)
	{
		if ((philo->pid[i] = fork()) == FAILURE)
			return (FAILURE);
		if (philo->pid[i++] == 0)
		{
			philo->philo_num = i;
			check_state(philo);
			exit(EXIT_SUCCESS);
		}
	}
	pthread_create(&full, NULL, &print_state_full, (void *)philo);
	pthread_create(&state, NULL, &change_main_state, (void *)philo);
	pthread_join(full, NULL);
	pthread_join(state, NULL);
	wait_and_exit(philo);
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	t_philosopher	philo;
	t_semaphore		semaphore;
	t_info			info;

	if (argc != 5 && argc != 6)
		print_error(NUMBER_OF_ARG);
	else
	{
		if (info_init(&info, (const char **)argv))
			return (FAILURE);
		if (semaphore_init(&semaphore, &info))
		{
			print_error(SEMAPHORE);
			return (FAILURE);
		}
		philosopher_init(&philo, &info, &semaphore);
		create_process_philo(&philo, &info);
		destroy_semaphore_philo(&philo);
	}
	return (SUCCESS);
}
