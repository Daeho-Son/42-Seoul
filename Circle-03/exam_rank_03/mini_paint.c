#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

char **Board;

typedef struct s_base
{
	int width;
	int height;
	char c;
} t_base;
t_base base;

typedef struct s_circle
{
	char type;
	float x;
	float y;
	float radius;
	char c;
} t_circle;

static size_t ft_strlen(const char *s)
{
	size_t i = 0;
	
	while (s[i])
		i++;
	return i;
}

void error_arg()
{
	const char *s = "Error: argument\n";
	write(1, s, ft_strlen(s));
}

void error_file()
{
	const char *s = "Error: Operation file corrupted\n";
	write(1, s, ft_strlen(s));
}

int make_board(FILE *file)
{
	int size = fscanf(file, "%d %d %c\n", &(base.width), &(base.height), &(base.c));
	if (size != 3 || !(0 < base.width && base.width <= 300) || !(0 < base.height && base.height <= 300))
		return FALSE;
	Board = (char **)malloc(sizeof(char *) * base.height);
	for (int y = 0; y < base.height; y++)
	{
		Board[y] = (char *)malloc(sizeof(char) * base.width);
		for (int x = 0; x < base.width; x++)
			Board[y][x] = base.c;
	}
	return TRUE;
}

static float get_distance(float x1, float y1, float x2, float y2)
{
	return sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2));
}

static int is_block_to_draw(t_circle circle, float x, float y)
{
	float dist = get_distance(x, y, circle.x, circle.y);
	if (circle.radius < dist)
		return -1;
	if (circle.radius - dist < 1.0f)
		return 0;
	return 1;
}

void draw_circle_one(t_circle circle)
{
	for (int y = 0; y < base.height; y++)
	{
		for (int x = 0; x < base.width; x++)
		{
			int is_draw = is_block_to_draw(circle, x, y);
			if (is_draw == 0 || (is_draw == 1 && circle.type == 'C'))
				Board[y][x] = circle.c;
		}
	}
}

int draw_circle(FILE *file)
{
	t_circle circle;

	while (1)
	{
		int size = fscanf(file, "%c %f %f %f %c\n", &(circle.type), &(circle.x), &(circle.y), &(circle.radius), &(circle.c));
		if (size == EOF)
			break;
		if (size != 5 || circle.radius <= 0 || (circle.type != 'c' && circle.type != 'C'))
			return FALSE;
		draw_circle_one(circle);
	}
	return TRUE;
}

void draw_board()
{
	for (int y = 0; y < base.height; y++)
	{
		for (int x = 0; x < base.width; x++)
			write(1, &Board[y][x], 1);
		write(1, "\n", 1);
	}
}

void free_board()
{
	for (int y = 0; y < base.height; y++)
		free(Board[y]);
	free(Board);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		error_arg();
		return 1;
	}
	FILE *file = fopen(argv[1], "r");
	if (file == NULL || make_board(file) == FALSE || draw_circle(file) == FALSE)
	{
		error_file();
		return 1;
	}
	draw_board();
	free_board();
	fclose(file);
	return 0;
}
