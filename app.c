
#include <stdio.h>
#include <stdlib.h>

#include "./src/game.h"

/*          0       1       2       3   4       5           6       7       8      9
/rush-01 "col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left
row3left row4left row1right row2right row3right row4right"

 4324122243211222
 4324122243211222
 4324122243211222
*/

//"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
//col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right




int value_from_id(char *arg, int id)
{
    int i;
    int index;
    char *current;
    
    i = 0;
    index = 0;
    current = arg;
    

    while(arg[i] != '\0')
    {
        if(arg[i] > 48 && arg[i] < 53)
        {
            if(index ==  id)
                return (arg[i] - 48);
            index++;
        }

        i++;
    }   
    return 7;
}

int ft_parse(t_header_tower **header, char *arg)
{
    int i;
    int current_value;
    t_header_tower *current_header;


    current_header = malloc(sizeof(t_header_tower)* LENGHT_HEADER );

    if(current_header == NULL)
        return 0;


    i = 0;
// 4 3 2 4   1 2 3 2   4 3 4 1   2 3 7 7
//"4 3 2 4   1 2 3 2   4 3 0 4   1 2 3 6"

    while( i < (LENGHT_HEADER * LENGHT_HEADER) ) 
    {
        current_value = value_from_id(arg, i);

        if(i > 11)
            current_header[i % LENGHT_HEADER].row.right = current_value;
        else if( i > 7)
            current_header[i % LENGHT_HEADER].row.left = current_value;
        else if(i > 3)
            current_header[i % LENGHT_HEADER].col.right = current_value;
        else
            current_header[i % LENGHT_HEADER].col.left = current_value;

        i++;
    }

    *header = current_header;

    return i;
}

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
                putchar(game[x][y] + 48);
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

int main(int argc, char **argv)
{

    t_header_tower* header;
    int **game;


    if(argc < 2)
    {
        puts("Error missing arguments\n");
        return 1;
    }

    if(create_game(&game, 0) == 0)
    {
        puts("Error to create Game\n");
        return 1;
    }

    if(ft_parse(&header, argv[1]) == 0)
    {
        free(header);
        ft_free_game(game);
        puts("Error to parse\n");
        return 1;
    }

    print_game_test(header, game);
/*


    if(ft_find_solution(header, game, 0, 0) == 0)
    {
        free(header);
        ft_free_game(game);
        puts("Error no solution found\n");
        return 1;
    }

    free(header);
*/
    return 0;
}
