#include "../incs/gol.h"

void	display_game(int **map, int num_cols, int num_rows)
{
	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_cols; j++)
		{
			if (map[i][j])
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}