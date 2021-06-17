

#include "game.h"


int check_is_only(int **game)
{
    int x;
    int y;

    x = 0;
    y = 0;

    while( x < LENGHT_HEADER )
    {

    }
    
    x = 0;

    while(y < LENGHT_HEADER)
    {
        game[x][y]
        y++;
    }
        
}


int ft_test_is_valide(t_header_tower *header, int **game)
{
    if(check_is_only(game)) //check col and row
        return 0;

    if(check_is)

    return 1;

}

int ft_find_solution(t_header_tower *header, int **game, int x, int y)
{
        if(ft_check_finish(header, game))
            return 1;

        game[x][y] += 1;

        if(ft_test_is_valide(header, game))
        {

            if(x == LENGHT_HEADER)
            {
                x = 0;
                y += 1;
            }
            else
            {
                x += 1;
            }

            ft_find_solution(header, game, x, y);
        }
        
        ft_find_solution(header, game, x, y);

}