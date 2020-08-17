#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid - print a grid
 * @grid: grid
 */
static void print_grid(int grid[3][3])
{
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (j)
printf(" ");
printf("%d", grid[i][j]);
}
printf("\n");
}
}

/**
 * sandpiles_sum - sums two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
grid_sum(grid1, grid2);
while (!is_stable(grid1))
topple(grid1);
}

/**
 * grid_sum - sums 2 3x3 grid
 * @grid1: first grid
 * @grid2: second grid
 */
void grid_sum(int grid1[3][3], int grid2[3][3])
{
int i, j;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
grid1[i][j] += grid2[i][j];
}
}

/**
 * topple - topples sand
 * @grid: sandpile
 */
void topple(int grid[3][3])
{
int i, j;
printf("=\n");
print_grid(grid);
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
{
grid[i][j] -= 4;
if (i + 1 < 3)
grid[i + 1][j] += 1;
if (j + 1 < 3)
grid[i][j + 1] += 1;
if (i - 1 >= 0)
grid[i - 1][j] += 1;
if (j - 1 >= 0)
grid[i][j - 1] += 1;
}
}
}
}

/**
 * is_stable - checks if sandpile is stable
 *
 * @grid: sandpile
 * Return: 1 if stable 0 if not
 */
int is_stable(int grid[3][3])
{
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
return (0);
}
}
return (1);
}

