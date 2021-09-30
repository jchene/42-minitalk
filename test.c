#include "./minitalk.h"

int		main(int argc, char **argv)
{
	kill(atoi(argv[1]), SIGUSR2);
	return (0);
}