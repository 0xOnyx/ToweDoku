#include "game.h"


int create_game(int ***game, int default_Value)
{
    int **current;
    int i;
    
    current = malloc(sizeof(int *) * LENGHT_HEADER);

    i = 0;

    while(i < LENGHT_HEADER)
    {
        int y;
        y = 0;

        current[i] = malloc(sizeof(int) * LENGHT_HEADER);
        
        while(y < LENGHT_HEADER)
        {
            current[i][y] = default_Value;
            y++;
        }

        i++;
    }
    *game = current;
    return 1;
}


void ft_free_game(int ***game)
{
    
    int **current;
    int i;
    i = 0;
    
    current = *game;

    while(i < LENGHT_HEADER )
    {
        free(current[i]);
        i++;
    }
    free(*game);
}
