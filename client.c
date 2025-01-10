#include "minitalk.h"

void	send_signals_to_server(int pid, char *message)
/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\\/\/\
|                                                     |
| ===== Send an encrypted message to the server ===== |
|          based on each bit of every letter.         |
|                                                     |
|    *** Send the signal ==> SIGUSR1:                 |
|        - If the least significant bit (LSB) is 0.   |
|                                                     |
|    *** Send the signal ==> SIGUSR2:                 |
|        - If the least significant bit (LSB) is 1.   |
|                                                     |
|    *** Send the signal ==> SIGUSR1:                 |
|        - 8 times after the message ends to signal   |
|          the termination of the message.            |
|                                                     |
|    *** No value returned.                           |
|                                                     |
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
{
	int	letter;
	int	i;

	letter = 0;
	while (message[letter])
	{
		i = -1;
		while (++i < 8)
		{
			if (((unsigned char)(message[letter] >> ( 7 - i )) & 1) == 0)
				kill (pid, SIGUSR1);
			if (((unsigned char)(message[letter] >> (7 - i)) & 1 ) == 1)
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

int	main(int argc, char **argv)
/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\\/\/\/|
|                                                       |
|   *** Use server_pid to send the message to the       |
|       server:                                         |
|       - Use ft_atoi to convert argv[1] into an int.   |
|                                                       |
|   *** Display error messages for:                     |
|       - Incorrect number of arguments.                |
|       - Invalid arguments.                            |
|                                                       |
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
{

	int	server_pid;
	char	*message;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
            ft_printf("[ERROR]: Invalid PID input. Please provide a valid PID.\n");
	    	return (0);
		}
		message = argv[2];
		if (message[0] == '\0')
		{
			ft_printf("[ERROR]: The message cannot be empty. Please provide a valid message.\n");
			return (0);
		}
		send_signals_to_server(server_pid, message);
	}
	else
		ft_printf("Please use the following format:\n ./client <PID> <Message>\n");
	return (0);
}
