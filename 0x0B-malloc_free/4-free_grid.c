#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees memory allocated for a 2D integer grid
 *
 * @grid: pointer to the 2D integer grid
 * @height: height of the grid
 *
 * Description: This function frees the memory allocated for a 2D integer grid
 * that was created using alloc_grid function.
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

