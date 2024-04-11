#include "../incs/gol.h"

bool check_neigbours(int **map, int i, int j, int num_rows, int num_cols)
{
	int count_neighbours;

	count_neighbours = 0;
	// Check top
	if (j - 1 >= 0 && map[j - 1][i])
		count_neighbours++;
	// Check down
	if (j + 1 < num_rows && map[j + 1][i])
		count_neighbours++;
	// Check left
	if (i - 1 >= 0 && map[j][i - 1])
		count_neighbours++;
	// Check right
	if (i + 1 < num_cols && map[j][i + 1])
		count_neighbours++;
	// Check Top Left
	if (j - 1 >= 0 && i - 1 >= 0 && map[j - 1][i - 1])
		count_neighbours++;
	// Check Top Right
	if (j - 1 >= 0 && i + 1 < num_cols && map[j - 1][i + 1])
		count_neighbours++;
	// Check Bottom Left
	if (j + 1 < num_rows && i - 1 >= 0 && map[j + 1][i - 1])
		count_neighbours++;
	// Check Bottom Right
	if (j + 1 < num_rows && i + 1 < num_cols && map[j + 1][i + 1])
		count_neighbours++;
	// Rule 1
	if (count_neighbours < 2)
		return (false);
	// Rule 2 and 3
	if (map[j][i] && (count_neighbours == 2 || count_neighbours == 3))
		return (true);
	// Rule 4
	if (count_neighbours > 3)
		return (false);
	// Rule for reproduction
	if (!map[j][i] && count_neighbours == 3)
		return (true);
	return (false);
}

void check_alive(int **map, int **buffer, int num_rows, int num_cols)
{
	for (size_t j = 0; j < (size_t)num_rows; j++)
	{
		for (size_t i = 0; i < (size_t)num_cols; i++)
		{
			buffer[j][i] = check_neigbours(map, i, j, num_rows, num_cols);
		}
	}
	copy_buffer(map, buffer, num_rows, num_cols);
}