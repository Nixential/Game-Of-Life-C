#include "../incs/gol.h"

int	main(int argc, char **argv)
{
	int num_cols;
	int num_rows;
	int **map;
	int **buffer;
	if (argc == 1)
	{
		num_cols = 9;
		num_rows = 9;
		map = init_array(num_rows, num_cols);
		seed_array(map, num_rows, num_cols);
	}
	else if (argc == 3)
	{
		num_cols = atoi(argv[1]);
		num_rows = atoi(argv[2]);
		map = init_array(num_rows, num_cols);
		seed_array(map, num_rows, num_cols);
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

	buffer = init_array(num_rows, num_cols);
	display_game(map, num_cols, num_rows);
	while (true)
	{
		printf("------------------------------\n");
		check_alive(map, buffer, num_rows, num_cols);
		display_game(map, num_cols, num_rows);
		printf("------------------------------\n");
		usleep(500 * 1000);
		system("clear");
	}
	return (0);
}