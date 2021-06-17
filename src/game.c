#include "game.h"


int create_game(int ***game, int default_Value)
{
    int **current;
    int i;
    
    current = malloc(sizeof(int *) * LENGHT_HEADER);
    if(current == NULL)
        return 0;

    i = 0;

    while(i < LENGHT_HEADER)
    {
        int y;
        y = 0;

        current[i] = malloc(sizeof(int) * LENGHT_HEADER);

        if(current[i] == NULL) 
            return 0;
        
        while(y < LENGHT_HEADER)
        {
            current[i][y] = default_Value;
            y++;
        }

        i++;
    }
    return 1;
}


void ft_free_game(int **game)
{
    int i;
    i = 0;

    while(i < LENGHT_HEADER )
    {
        free(game[i]);
    }
    free(game);
}
