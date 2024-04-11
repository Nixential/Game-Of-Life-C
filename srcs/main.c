#include "../incs/gol.h"

int **map = NULL;
int **buffer = NULL;
int num_cols = 0;
int num_rows = 0;

void free_array(int **array, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		free(array[i]);
	}
	free(array);
}

void signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (map != NULL)
		{
			free_array(map, num_rows);
		}
		if (buffer != NULL)
		{
			free_array(buffer, num_rows);
		}
		exit(0);
	}
}

int main(int argc, char **argv)
{
	// Set up signal handler
	signal(SIGINT, signal_handler);

	if (argc == 1)
	{
		num_cols = 9;
		num_rows = 9;
	}
	else if (argc == 3)
	{
		num_cols = atoi(argv[1]);
		num_rows = atoi(argv[2]);
	}
	else if (argc == 2)
	{
		parse_file_to_2d_array(argv[1], &map, &num_rows, &num_cols);
	}
	else
	{
		printf("Invalid input");
		return (1);
	}

	if (map == NULL)
	{
		map = init_array(num_rows, num_cols);
		seed_array(map, num_rows, num_cols);
	}
	buffer = init_array(num_rows, num_cols);

	// Game loop
	while (1)
	{
		display_game(map, num_cols, num_rows);
		usleep(500 * 1000); // Sleep for half a second
		check_alive(map, buffer, num_rows, num_cols);
		system("clear");
	}

	return 0; // This point is never reached
}
