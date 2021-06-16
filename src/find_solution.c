

#include "game.h"

int ft_test_is_valide(t_header_tower *header, int **game)
{

}

int ft_find_solution(t_header_tower *header, int **game, int x, int y)
{
        if(ft_test_is_valide())

        game[x][y] += 1;

        if(ft_test_is_valide())
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

            ft_find_solution(header, game, x, y)
        }
        
        ft_find_solution(header, game, x, y)

}