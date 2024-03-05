#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal)

{
	static int i = 0;
	static char c = 0;
	if (i < 7)
		if (signal == SIGUSR1)
			c |= 1 << i;
	i++;
	if (i == 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	printf("%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
