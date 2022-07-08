#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

typedef struct s_rectangle
{
	char type;
	float x;
	float y;
	float width;
	float height;
	char c;
} t_rectangle;

static size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return i;
}

static void error_argc()
{
	const char *s = "Error: argument\n";
	write(1, s, ft_strlen(s));
}

static void error_file()
{
	const char *s = "Error: Operation file corrupted\n";
	write(1, s, ft_strlen(s));
}

int make_board(FILE* file)
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

static int is_block_to_draw(t_rectangle rect, float x, float y)
{
	if (x < rect.x || rect.x + rect.width < x || y < rect.y || rect.y + rect.height < y)
		return -1;
	if (x - rect.x < 1.0f || rect.x + rect.width - x < 1.0f || y - rect.y < 1.0f || rect.y + rect.height - y < 1.0f)
		return 0;
	return 1;
}

static void draw_rectangle_one(t_rectangle rect)
{
	for (int y = 0; y < base.height; y++)
	{
		for (int x = 0; x < base.width; x++)
		{
			int is_draw = is_block_to_draw(rect, x, y);
			if (is_draw == 0 || (is_draw == 1 && rect.type == 'R'))
				Board[y][x] = rect.c;
		}
	}
}

int draw_rectangle(FILE *file)
{
	t_rectangle rect;

	while (1)
	{
		int size = fscanf(file, "%c %f %f %f %f %c\n", &(rect.type), &(rect.x), &(rect.y), &(rect.width), &(rect.height), &(rect.c));
		if (size == EOF)
			break;
		if (size != 6 || rect.width <= 0 || rect.height <= 0 || (rect.type != 'r' && rect.type != 'R'))
			return FALSE;
		draw_rectangle_one(rect);
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
		error_argc();
		return 1;
	}
	FILE *file = fopen(argv[1], "r");
	if (file == NULL || make_board(file) == FALSE || draw_rectangle(file) == FALSE) 
	{
		error_file();
		return 1;
	}
	draw_board();
	free_board();
	fclose(file);
	return 0;
}

