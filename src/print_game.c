
#include "game.h"

void print_game_test(t_header_tower* header, int **game)
{
    int heap;

    putchar('\n');
    putchar('\n');

    heap = 0;

    while(heap < (LENGHT_HEADER + 2))
    {
        if(heap == 0 || heap == 5)
            putchar('\t');
        else
        {
            
            putchar(header[heap-1].col.left + 48 );
            putchar('\t');
        }
        heap++;
    }
    putchar('\n');
    putchar('\n');

    int x;
    int y;

    x = 0;
    y = 0;

    while(x < LENGHT_HEADER )
    {
        while(y < (LENGHT_HEADER + 2))
        {
            if(y == 0)
                putchar(header[x].row.left + 48);
            else if(y == 5)
                putchar(header[x].row.right + 48);
            else
            {
                putchar(game[x][y-1] + 48);
            }
            putchar('\t');
            y++;
        }
        y = 0;
        x++;
        putchar('\n');
    }

    putchar('\n');
    putchar('\n');



    heap = 0;
    while(heap < (LENGHT_HEADER + 2))
    {
        if(heap == 0 || heap == 5)
            putchar('\t');
        else
        {
            putchar(header[heap-1].col.right + 48);
            putchar('\t');
        }
        heap++;
    }
    putchar('\n');

}
