

#include "game.h"


int check_duplicate_number_array_col(int *array, int size)
{
    int i;
    int res;

    i = 0;
    res = 0;

    while(i < size)
    {
        res = res ^ array[i];
        i++;
    }
    i = 1;
    while(i <= size)
    {
        res = res ^ i;
        i++;
    }

    return res;
}

int check_duplicate_number_array_row(int **array, int positionY, int size)
{
    int i;
    int res;

    i = 0;
    res = 0;

    while(i < size)
    {
        res = res ^ array[i][positionY];
        i++;
    }
    i = 1;

    while(i <= size)
    {
        res = res ^ i;
        i++;
    }

    return res;
}

int check_is_only(int **game)
{
    int x;
    int y;
    

    x = 0;
    y = 0;
    


    while( x < LENGHT_HEADER )
    {
        if(check_duplicate_number_array_col(game[x], 4))
            return 1;
        
        x++;
    }
    
    x = 0;

    while(y < LENGHT_HEADER)
    {
        if(check_duplicate_number_array_row(game, y, 4) )
            return 1;
            
        y++;
    }
        
    return 0;
}


int ft_test_is_valide(t_header_tower *header, int **game)
{
    if(check_is_only(game)) //check col and row
        return 0;

/*
    if(check_is_height(game))
        return 0
*/


    return 1;

}

int ft_empty_game(int **game)
{
    int x;
    int y;
    

    x = 0;
    y = 0;
    


    while( x < LENGHT_HEADER )
    {
        while(y < LENGHT_HEADER)
        {
            if(game[x][y] == 0)
                return 1;
            y++;
        }

        x++;
    }

    return 0;
}

int ft_check_finish(t_header_tower *header, int **game)
{
    if(ft_empty_game(game) != 1)
        return 0;
    
    if(ft_test_is_valide(header, game) != 1)
        return 0;
    

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