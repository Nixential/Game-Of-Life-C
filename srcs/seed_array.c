#include "../incs/gol.h"

void seed_array(int **arr, int num_rows, int num_cols)
{
	srand(time(NULL));
	for (size_t i = 0; i < (size_t)num_rows; i++)
	{
		for (size_t j = 0; j < (size_t)num_cols; j++)
		{
			int random = rand() % 100;
			int res = (random < 60) ? 0 : 1;
			arr[i][j] = res;
		}
	}
}