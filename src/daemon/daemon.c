#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "../config/config.h"
#include "../server/server.h"
/*
static void signal_handler(int s)
{
	switch (s)
	{
		case SIGINT:

	}
}*/

int start_daemon( struct config *config) // config valid
{
	pid_t pid_daemon = fork();
	if (pid_daemon )
}
