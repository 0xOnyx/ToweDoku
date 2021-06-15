
#include <stdio.h>

/*
/rush-01 "col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left
row3left row4left row1right row2right row3right row4right"
*/

#define LENGHT_HEADER 4

typedef struct s_position{
    int left;    //up
    int right;  //down
} t_position;

typedef struct s_header_tower{
   t_position *row;
   t_position *col;
} t_header_tower;


int parse(t_header_tower **header, char *arg)
{
    int i;
    int current_value;


    t_header_tower *current_header;

    current_header = malloc(sizeof(t_header_tower)* LENGHT_HEADER );
    if(current_header == NULL)
        return 0;


    i = 0;
    while( i < (LENGHT_HEADER * LENGHT_HEADER) ) 
    {
        current_value = next_value(arg);
    
        current_header[i % LENGHT_HEADER]->col->left = current_value;
        current_header[i % LENGHT_HEADER]->col->right = current_value;
        current_header[i % LENGHT_HEADER]->row->left = current_value;
        current_header[i % LENGHT_HEADER]->row->right = 

    }

    *header = current_header;

    return i;
}

int main(int argc, char **argv)
{
    t_header_tower* header;
    
    if( parse(&header, argv[1]) == 0)
    {
            ft_puts("Error\n");
        return 1
    }


    free(header);
    return 0;
}