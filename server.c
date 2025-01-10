
#include "minitalk.h"
void signal_handler(int signal_number)
/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/|
|                                                       |
|    *** If SIGUSR1:                                    |
|        - Do nothing.                                  |
|        - Simply increase the counter to move to       |
|          the next bit.                                |
|                                                       |
|    *** If SIGUSR2:                                    |
|        - This bit is needed. Using the counter,       |
|          determine its position as a power of 2       |
|          within the 7 bits for each character.        |
|        - Add this value to the result.                |
|                                                       |
|    *** At the end of the letter:                      |
|        - Add the letter to the final string.          |
|        - If the end of the string is reached, print   |
|          the final string and reset all variables.    |
|                                                       |
|    *** No return value.                               |
|                                                       |
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
{
    static int bit_counter = 0;
    static int result = 0;
    static char *final;

    if (!final)
        final = ft_strdup("");
    if (signal_number == SIGUSR1)
        result = result + 0;
    else if (signal_number == SIGUSR2)
        result = result + (ft_power_recursion(2, (7 - bit_counter)));
    bit_counter++;
    if (bit_counter == 8)
    {
        final = add_letter_to_string(final, result);
        if (result == '\0')
        {
            ft_printf("%s\n", final);
            final = NULL;
        }
        bit_counter = 0;
        result = 0;
    }
}

char *add_letter_to_string(char const *str, int const letter)
/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\\/\/\/|
|                                                       |
|   ** Set the letter inside the final string           |
|      buffer to print it latter.                       |
|   ** Free the old value of the full string.           |
|   ** Return the new full string.                      |
|                                                       |
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
{
    char *newstr;
    int i;
    int j;

    i = 0;
    j = 0;
    newstr = malloc((ft_strlen(str) + 2 ) * sizeof(char));
    if (!newstr)
        return (NULL);
    while (str[i])
        newstr[j++] = str[i++];
    newstr[j++] = letter;
    newstr[j] = '\0';
    free ((void *)(str));
    return (newstr);
}

int ft_power_recursion(int base, int power)
/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/|
|                                                       |
|   *** Calculates the power of a given number.         |
|   *** Returns the result of the calculation.          |
|                                                       |
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
{
    int result;

    if (power == 0)
        return (1);
    else if (power < 0)
        return (0);
    else 
        result = base * ft_power_recursion(base, power -1);
    return (result);
}

int main (void)
/*\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/|
|                                                           |
|      *** Use server_pid so the client can send            |
|         a message to the server.                          |
|      *** The while loop waits indefinitely for signals.   |
|      *** No return value because of the infinite loop,    |
|         and the process will terminate via signals.       |
|                                                           |
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
{
    struct sigaction    server_action;
    ft_printf("Welcome to **aaljazza server** :) \n");
    ft_printf("Server pid = %d\n", getpid());
    server_action.sa_handler = signal_handler;
    server_action.sa_flags = 0;
    sigaction(SIGUSR1, &server_action, NULL);
    sigaction(SIGUSR2, &server_action, NULL);
    while (1)
        usleep(50);
}