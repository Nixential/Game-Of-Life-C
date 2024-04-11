#include "../incs/gol.h"

void copy_buffer(int **map, int **buffer, int num_rows, int num_cols)
{
	for (size_t j = 0; j < (size_t)num_rows; j++)
	{
		for (size_t i = 0; i < (size_t)num_cols; i++)
		{
			map[j][i] = buffer[j][i];
		}
	}
}