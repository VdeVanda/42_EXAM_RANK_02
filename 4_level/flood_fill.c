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

void  flood_fill(char **tab, t_point size, t_point begin)
{
    if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
        return ;
    if (tab[begin.y][begin.x] != '0')
        return ;
    tab[begin.y][begin.x] = 'F';
    flood_fill(tab, size, (t_point){begin.x + 1, begin.y}); // Right
    flood_fill(tab, size, (t_point){begin.x - 1, begin.y}); // Left
    flood_fill(tab, size, (t_point){begin.x, begin.y + 1}); // Down
    flood_fill(tab, size, (t_point){begin.x, begin.y - 1}); // Up
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void flood_fill(char **tab, t_point size, t_point begin);

void print_tab(char **tab, t_point size)
{
    for (int i = 0; i < size.y; i++)
        printf("%s\n", tab[i]);
    printf("\n");
}

int main(void)
{
    t_point size = {8, 5};
    char *area[] = {
        "11111111",
        "10010001",
        "10010001",
        "10110001",
        "11111111"
    };
    
    char **tab = malloc(size.y * sizeof(char *));
    for (int i = 0; i < size.y; i++)
        tab[i] = strdup(area[i]);
    
    t_point begin = {6, 1};  // Starting point for flood fill
    
    printf("Before flood fill:\n");
    print_tab(tab, size);
    
    flood_fill(tab, size, begin);
    
    printf("After flood fill:\n");
    print_tab(tab, size);
    
    // Free allocated memory
    for (int i = 0; i < size.y; i++)
        free(tab[i]);
    free(tab);
    
    return (0);
}