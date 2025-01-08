#include "minitalk.h"

void    send_signals(int pid, char *message)
{
    ft_printf("int pid = %d, message = %s\n", pid, message);
}
int     main()
{
    send_signals(5, "hi");
    return 0;
}