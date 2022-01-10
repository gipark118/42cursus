/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:02:51 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 08:53:22 by gipark           ###   ########.fr       */
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
	pthread_mutex_lock(&philo->mutex->print_m);
	if (philo->info->state != DIED && philo->info->state != FULL)
	{
		printf("%ld philo%d %s", get_time() - philo->start_time,
				philo->philo_num, str);
	}
	pthread_mutex_unlock(&philo->mutex->print_m);
	return (SUCCESS);
}

void	*check_state(void *philo)
{
	t_philosopher	*tmp;
	pthread_t		died;

	tmp = (t_philosopher *)philo;
	pthread_create(&died, NULL, &print_state_died, (void *)tmp);
	pthread_detach(died);
	tmp->philo_num % 2 ? 0 : usleep(tmp->info->time_to_eat);
	while (tmp->info->state != DIED && tmp->info->state != FULL)
	{
		philosopher_eat(tmp);
		print_state(" is sleeping.\n", tmp);
		usleep(tmp->info->time_to_sleep);
		print_state(" is thinking.\n", tmp);
	}
	return (NULL);
}

int		create_pthread_philo(t_philosopher *philo, t_info *info)
{
	pthread_t	full;
	int			i;

	i = 0;
	while (i < info->number_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, check_state, &philo[i]) < 0)
		{
			print_error(PTHREAD);
			return (FAILURE);
		}
		usleep(20);
		i++;
	}
	pthread_create(&full, NULL, &print_state_full, (void *)philo);
	pthread_detach(full);
	i = 0;
	while (i < info->number_of_philo)
		pthread_join(philo[i++].thread, NULL);
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	t_philosopher	*philo;
	t_mutex			mutex;
	t_info			info;

	if (argc != 5 && argc != 6)
		print_error(NUMBER_OF_ARG);
	else
	{
	    if (info_init(&info, (const char **)argv))
			return (FAILURE);
		if (mutex_init(&mutex, &info))
			return (FAILURE);
		philo = pthread_init(&info, &mutex);
		create_pthread_philo(philo, &info);
		destroy_pthread_philo(philo, &mutex, &info);
	}
	return (SUCCESS);
}
