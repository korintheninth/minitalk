#include <ctype.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	if (argc != 3)
	{
		printf("\nWrong parameters. Usage: %s <PID> <MESSAGE>\n\n", argv[0]);
		return (-1);
	}
	if (!argv[2])
	{
		printf("\nEmpty Message\n\n");
		return (-1);
	}
	i = 0;
	while (argv[i])
	{
		if (!isdigit(argv[i]))
		{
			printf("\nInvalid PID\n\n");
			return(-1);
		}
	}
	char *message = argv[2];
	pid_t id = atoi(argv[1]);

	i = 0;
	while (message[i])
	{
		int j = 0;
		while (j < 7)
		{
			if (message[i] & (1 << j))
				kill(id, SIGUSR1);
			else
				kill(id, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
	}
}
