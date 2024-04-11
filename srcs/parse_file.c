#include "../incs/gol.h"

void parse_file_to_2d_array(const char *file_path, int ***array, int *rows, int *cols)
{
	FILE *file;
	char line[MAX_LINE_LENGTH];
	int current_length;
	int row;

	file = fopen(file_path, "r");
	if (!file)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	*rows = 0;
	*cols = 0;
	while (fgets(line, sizeof(line), file))
	{
		(*rows)++;
		current_length = 0;
		while (line[current_length] != '\n' && line[current_length] != '\0')
		{
			current_length++;
		}
		if (current_length > *cols)
		{
			*cols = current_length;
		}
	}
	*array = (int **)malloc(*rows * sizeof(int *));
	for (int i = 0; i < *rows; i++)
	{
		(*array)[i] = (int *)malloc(*cols * sizeof(int));
	}
	fseek(file, 0, SEEK_SET);
	row = 0;
	while (fgets(line, sizeof(line), file))
	{
		for (int col = 0; col < *cols && line[col] != '\n' && line[col] != '\0'; col++)
		{
			(*array)[row][col] = line[col] - '0';
		}
		row++;
	}
	fclose(file);
}
