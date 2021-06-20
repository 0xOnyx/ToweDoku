//111448

#include "game.h"


int check_duplicate_number_array_col(int *array, int size)
{
    int i;
    int y;


    i = 0;
    y = 0;

    while(i < size)
    {
        while(y < size)
        {
            if(array[i] == array[y] && i != y \
            && array[i] != 0 && array[y] != 0)
                return 1;
            y++;
        }
        y = 0;
        i++;
    }

    return 0;
}

int check_duplicate_number_array_row(int **array, int positionY, int size)
{
    int i;
    int y;


    i = 0;
    y = 0;

    while(i < size)
    {
        while(y < size)
        {
            if(array[i][positionY] == array[y][positionY] && i != y \
            && array[i][positionY] != 0 && array[y][positionY] != 0)
                return 1;
            y++;
        }
        y = 0;
        i++;
    }

    return 0;
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

    while(y < LENGHT_HEADER)
    {
        if(check_duplicate_number_array_row(game, y, 4) )
            return 1;
            
        y++;
    }
        
    return 0;
}

int check_heigth_col(int value, int *game)
{
    int res;
    int back;
    int i;

    i = 0;
    res = 1;
    back = 0;

    while(i < LENGHT_HEADER)
    {
        if(game[i] > back)
        {
            back = game[i];
            res++;
        }

    }
i
    if(res != value)
        return 1;

    return 0;
}

int check_height_row(int value, int **game, int positionY)
{
    int i;
    i = 0;
}

int check_is_height(t_header_tower *header, int **game)
{
    int i;
    i = 0;

    while(i < LENGHT_HEADER)
    {
        if(check_height_col(header[i].row.left, game[i]) )
            return 1;
        if(check_height_col(header[i].row.right, game[i]) )
            return 1;

        i++;
    }

    i = 0;

    while(i < LENGHT_HEADER )
    {
        if(check_height_row(header[i].col.left, game, i) )
            return 1;
        if(check_height_row(header[i].col.right, game, i) )
            return 1;

        i++;
    }
}


int ft_test_is_valide(t_header_tower *header, int **game)
{
    if(check_is_only(game)) //check col and row
        return 0;


    if(check_is_height(header, game))
        return 0;

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
        y = 0;

        x++;
    }

    return 0;
}

int ft_check_finish(t_header_tower *header, int **game)
{
    if(ft_empty_game(game))
        return 0;
    
    if(ft_test_is_valide(header, game) != 1)
        return 0;
    
    return 1;
}



int ft_find_solution(t_header_tower *header, int **game, int x, int y)
{
    int i;

    if(ft_check_finish(header, game))
        return 1;

    i = 1;

    while(i < 5)
    {
        game[x][y] = i;

        if(ft_test_is_valide(header, game))
        {
            int tmpX;
            int tmpY;

            tmpX = x;
            tmpY = y;

            if(x == LENGHT_HEADER - 1)
            {
                tmpX = 0;
                tmpY += 1;
            }
            else
                tmpX += 1;

            if(ft_find_solution(header, game, tmpX, tmpY ) == 1)
                return 1;

            game[tmpX][tmpY] = 0;
        }


        
        i++;
    }

    return 0;

}

