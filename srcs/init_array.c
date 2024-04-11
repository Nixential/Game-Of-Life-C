#include "../incs/gol.h"

int	**init_array(int num_rows, int num_cols)
{
	int **array = (int **)malloc(num_rows * sizeof(int *));
	if (array == NULL)
		return (array);
	for (size_t i = 0; i < (size_t)num_rows; i++)
	{
		array[i] = (int *)malloc(num_cols * sizeof(int));
	}
	return (array);
}