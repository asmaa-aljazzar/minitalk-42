
# ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"
void    send_signals_to_server(int pid, char *message);
void    signal_handler(int signal_number);
char    *add_letter_to_string(char const *str, int const letter);
int ft_power_recursion(int base, int power);

#endif
