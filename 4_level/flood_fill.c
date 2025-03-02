/*
Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------------
Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.
Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.
The flood_fill function won't fill diagonally.
The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);
The t_point structure is prototyped like this:
  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
Example:
$> cat test_main.c
#include "test_functions.h"
#include "flood_fill.h"
int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	}
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
}
$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill; ./flood_fill
1 1 1 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 1 0 0 0 1
1 0 1 0 0 0 0 1
1 1 0 0 0 0 0 0
1 1 1 1 1 1 1 1
1 F F F 1 0 0 1
1 F F 1 0 0 0 1
1 F 1 0 0 0 0 1
1 1 0 0 0 0 0 0
$> 
*/

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **make_area(char **zone)
{
    int i, j;
    char **area;

    for (i = 0; zone[i]; i++)
        ;
    area = malloc(sizeof(char *) * (i + 1));
    for (i = 0; zone[i]; i++)
    {
        area[i] = malloc(strlen(zone[i]) + 1);
        for (j = 0; zone[i][j]; j++)
            area[i][j] = zone[i][j];
        area[i][j] = '\0';
    }
    area[i] = NULL;
    return area;
}

void print_tab(char **tab)
{
    int i, j;

    for (i = 0; tab[i]; i++)
    {
        for (j = 0; tab[i][j]; j++)
        {
            if (tab[i][j] == ' ')
                continue;
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    char **area;
    t_point size = {8, 5};
    t_point begin = {2, 2};
    char *zone[] = {
        "1 1 1 1 1 1 1 1",
        "1 0 0 0 1 0 0 1",
        "1 0 0 1 0 0 0 1",
        "1 0 1 1 0 0 0 1",
        "1 1 1 0 0 0 0 1",
        NULL
    };

    area = make_area(zone);
    printf("Original area:\n");
    print_tab(area);
    flood_fill(area, size, begin);
    printf("\nFilled area:\n");
    print_tab(area);

    for (int i = 0; area[i]; i++)
        free(area[i]);
    free(area);

    return 0;
}
*/