#include "ft_putchar.c"

void	rush(int x, int y);
void	ft_putchar(char c);

void	ft_display_char(int cnt_x, int x, int line_pos)
{
	if (line_pos == 1)
	{
		if	(cnt_x == 0)
			ft_putchar('A');
		else if (cnt_x == (x-1))
			ft_putchar('B');
		else
			ft_putchar('C');
	}
	if (line_pos == 2)
	{
		if	(cnt_x == 0)
			ft_putchar('D');
		else if (cnt_x == (x-1))
			ft_putchar('E');
		else
			ft_putchar('F');
	}
	else
	{
		if (cnt_x == 0 || cnt_x == (x - 1))
			ft_putchar('G');
		else
			ft_putchar('H');
	}
}

void	rush(int x, int y)
{
	int cnt_x;
	int cnt_y;

	cnt_y = 0;
	while (cnt_y < y)
	{
		cnt_x = 0;
		while (cnt_x < x)
		{
			if (cnt_y == 0)
				ft_display_char(cnt_x, x, 1);
			else if (cnt_y == (y-1))
				ft_display_char(cnt_x, x, 2);
			else
				ft_display_char(cnt_x, x, 0);
			cnt_x++;
		}
		ft_putchar('\n');
		cnt_y++;
	}
}
