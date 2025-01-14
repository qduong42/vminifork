/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:30:34 by vsimeono          #+#    #+#             */
/*   Updated: 2022/07/20 10:10:34 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
#define SIGNALS_H

#include "../minishell.h"
#include "../libft/libft.h"
#include <signal.h>
#include <readline/readline.h>
#include <string.h>

typedef struct s_data t_data;

// /* Global Variable */
// extern int	g_pid;

void	handler(int	signum);
void	signal_check(t_data *data);

#endif