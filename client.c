/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:36:54 by aaljazza          #+#    #+#             */
/*   Updated: 2025/01/12 09:50:35 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// .-----------------------------------------------------.
// |                                                     |
// | ===== Send an encrypted message to the server ===== |
// |          based on each bit of every letter.         |
// |                                                     |
// |    *** Send the signal ==> SIGUSR1:                 |
// |        - If the least significant bit (LSB) is 0.   |
// |                                                     |
// |    *** Send the signal ==> SIGUSR2:                 |
// |        - If the least significant bit (LSB) is 1.   |
// |                                                     |
// |    *** Send the signal ==> SIGUSR1:                 |
// |        - 8 times after the message ends to signal   |
// |          the termination of the message.            |
// |                                                     |
// |    *** No value returned.                           |
// |                                                     |
// .-----------------------------------------------------.
void	send_signals_to_server(int pid, char *message)
{
	int	letter;
	int	i;

	letter = 0;
	while (message[letter])
	{
		i = -1;
		while (++i < 8)
		{
			if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 0)
				kill (pid, SIGUSR1);
			if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 1)
				kill (pid, SIGUSR2);
			usleep (50);
		}
		letter++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill (pid, SIGUSR1);
		usleep (50);
	}
}

// .-------------------------------------------------------.
// |                                                       |
// |   *** Use server_pid to send the message to the       |
// |       server:                                         |
// |       - Use ft_atoi to convert argv[1] into an int.   |
// |                                                       |
// |   *** Display error messages for:                     |
// |       - Incorrect number of arguments.                |
// |       - Invalid arguments.                            |
// |                                                       |
// .-------------------------------------------------------.
int	main(int argc, char **argv)
{
	int			server_pid;
	char		*message;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			ft_printf("Please provide a valid PID.\n");
			return (0);
		}
		message = argv[2];
		if (message[0] == '\0')
		{
			ft_printf("[ERROR]: The message cannot be empty.\n");
			return (0);
		}
		send_signals_to_server(server_pid, message);
	}
	else
		ft_printf("The format is:\n ./client <PID> <Message>\n");
	return (0);
}
