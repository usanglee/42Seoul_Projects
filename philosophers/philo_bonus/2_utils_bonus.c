/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_utils_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulee <ulee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:33:42 by ulee              #+#    #+#             */
/*   Updated: 2021/10/16 17:43:46 by ulee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_ms_time(void)
{
	struct timeval	te;
	long long		ms;

	gettimeofday(&te, NULL);
	ms = te.tv_sec * 1000 + te.tv_usec / 1000;
	return (ms);
}

void	print_status(t_philo *philo, char *str)
{
	sem_wait(philo->info->print);
	printf("%lld %d %s\n", get_ms_time() - philo->when_start, \
		philo->philo_num, str);
	if (philo->info->death == 0)
		sem_post(philo->info->print);
}
