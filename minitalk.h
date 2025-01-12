/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:06:54 by aaljazza          #+#    #+#             */
/*   Updated: 2025/01/12 10:09:00 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

void	send_signals_to_server(int pid, char *message);
void	signal_handler(int signal_number);
char	*add_letter_to_string(char const *str, int const letter);
int		ft_power_recursion(int base, int power);

#endif
