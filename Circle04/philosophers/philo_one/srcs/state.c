/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:30:27 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 08:58:13 by gipark           ###   ########.fr       */
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
				pthread_mutex_lock(&tmp[i].mutex->print_m);
				printf("%ld Every philosophers has eaten %d times.\n",
						get_time() - tmp[0].start_time, tmp[0].info->must_eat);
				pthread_mutex_lock(&tmp->mutex->state_m);
				tmp[i].info->state = FULL;
				pthread_mutex_unlock(&tmp->mutex->state_m);
				pthread_mutex_unlock(&tmp[i].mutex->print_m);
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
			print_state(" is died\n", tmp);
			pthread_mutex_lock(&tmp->mutex->state_m);
			tmp->info->state = DIED;
			pthread_mutex_unlock(&tmp->mutex->state_m);
			break ;
		}
	}
	return (NULL);
}

void	philosopher_eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->fork_r);
	pthread_mutex_lock(philo->fork_l);
	print_state(" has taken forks\n", philo);
	philo->last_philo = get_time();
	print_state(" is eating\n", philo);
	usleep(philo->info->time_to_eat);
	pthread_mutex_lock(&philo->mutex->eat_m);
	philo->info->num_of_eat++;
	pthread_mutex_unlock(&philo->mutex->eat_m);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}
