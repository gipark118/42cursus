/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 08:56:56 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 09:08:36 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*print_state_full(void *philo)
{
	t_philosopher	*tmp;
	int				i;

	tmp = (t_philosopher *)philo;
	while (tmp[0].info->state != FULL && tmp[0].info->state != DIED)
	{
		i = 0;
		while (i < tmp[0].info->number_of_philo && tmp[0].info->state != FULL &&
				tmp[0].info->state != DIED)
		{
			if (tmp[i].info->num_of_eat ==
					(tmp[0].info->number_of_philo * tmp[0].info->must_eat))
			{
				tmp[i].info->state = FULL;
				sem_wait(tmp[i].semaphore->print_s);
				printf("%ld Every philosophers has eaten %d times.\n",
						get_time() - tmp[0].start_time, tmp[0].info->must_eat);
				sem_post(tmp[i].semaphore->print_s);
			}
			i++;
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
		}
	}
	return (NULL);
}

void	philosopher_eat(t_philosopher *philo)
{
	sem_wait(philo->semaphore->fork_s);
	print_state(" has taken forks.\n", philo);
	philo->last_philo = get_time();
	print_state(" is eating.\n", philo);
	usleep(philo->info->time_to_eat);
	sem_wait(philo->semaphore->eat_s);
	philo->info->num_of_eat++;
	sem_post(philo->semaphore->eat_s);
	sem_post(philo->semaphore->fork_s);
}
