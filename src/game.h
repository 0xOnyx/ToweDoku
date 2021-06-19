
#ifndef H_FIN_SOLUTION
#   define H_FIN_SOLUTION
#   define LENGHT_HEADER 4



#include <stdio.h>
#include <stdlib.h>

typedef struct s_position{
    int left;    //up
    int right;  //down
} t_position;

typedef struct s_header_tower{
    t_position row;
    t_position col;
} t_header_tower;


int ft_find_solution(t_header_tower* header, int **game, int x , int y);

int create_game(int ***game, int default_Value);
void ft_free_game(int ***game);

#endif
