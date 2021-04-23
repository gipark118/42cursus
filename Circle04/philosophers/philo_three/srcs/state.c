/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:57:50 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 10:09:07 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*change_main_state(void *philo)
{
	t_philosopher *tmp;

	tmp = (t_philosopher *)philo;
	sem_wait(tmp->semaphore->main_s);
	tmp->info->state = DIED;
	return (NULL);
}

void	*change_philo_state(void *philo)
{
	t_philosopher *tmp;

	tmp = (t_philosopher *)philo;
	sem_wait(tmp->semaphore->philo_s);
	tmp->info->state = DIED;
	sem_post(tmp->semaphore->philo_s);
	return (NULL);
}

void	*print_state_full(void *philo)
{
	t_philosopher	*tmp;
	int				i;

	tmp = (t_philosopher *)philo;
	i = 0;
	while (tmp->info->state != DIED && tmp->info->state != FULL)
	{
		sem_wait(tmp->semaphore->eat_s);
		i++;
		if (i == (tmp->info->number_of_philo * tmp->info->must_eat))
		{
			tmp->info->state = FULL;
			sem_post(tmp->semaphore->main_s);
			sem_post(tmp->semaphore->philo_s);
			usleep(70);
			sem_wait(tmp->semaphore->print_s);
			printf("%ld Every philosophers has eaten %d times.\n",
						get_time() - tmp[0].start_time, tmp[0].info->must_eat);
			sem_post(tmp->semaphore->print_s);
			break ;
		}
	}
	return (NULL);
}

void	*print_state_died(void *philo)
{
	t_philosopher	*tmp;

	tmp = (t_philosopher *)philo;
	while (tmp->info->state != DIED && tmp->info->state != FULL)
	{
		if (get_time() - tmp->last_philo > tmp->info->time_to_die)
		{
			print_state(" is died.\n", tmp);
			tmp->info->state = DIED;
			sem_post(tmp->semaphore->main_s);
			sem_post(tmp->semaphore->philo_s);
			sem_post(tmp->semaphore->eat_s);
			break ;
		}
	}
	return (NULL);
}

void	philosopher_eat(t_philosopher *philo)
{
	sem_wait(philo->semaphore->fork_s);
	print_state(" has taken forks.\n", philo);
	print_state(" is eating.\n", philo);
	philo->last_philo = get_time();
	usleep(philo->info->time_to_eat);
	philo->info->num_of_eat++;
	sem_post(philo->semaphore->eat_s);
	sem_post(philo->semaphore->fork_s);
}
