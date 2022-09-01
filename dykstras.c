#include <stdio.h>
#define UINT unsigned int

int main(void){
    //Adjacency matrix
    int map[5][5] = {{0, 4, 12, 0, 11},
                     {4, 0, 0, 3, 7},
                     {12, 0, 0, 2, 1},
                     {0, 3, 2, 0, 4},
                     {12, 7, 1, 4, 0}};

    //Diplay these arrays for final output
    char a_nodes[5]   = {'A', 'B', 'C', 'D', 'E'};
    char a_prev[5]    = {'-', '-', '-', '-', '-'};
    UINT a_cost[5]    = {0,0,0,0,0};

    //Size of data
    int SIZE = sizeof map[0] / sizeof map[0][0];

    UINT cur = 0;
    int y;
    for (y=0; y < SIZE; y++){

        //determine what node is closest
        // - requires cur to be on the correct node
        UINT closest;
        {//Scope this logic for mem purposes
            UINT weight = -1;
            UINT x;
            for (x=0; x<SIZE; x++){
                if ((map[cur][x] < weight || weight == -1) && map[cur][x] != 0){
                    closest = x;
                    weight = map[cur][x];
                }
            }
        }
        
        if (y != SIZE - 1){
            //set prev to cur
            a_prev[closest] = a_nodes[cur];

            //set weight from cur -> closest
            printf("map[%d][%d]\n", cur, closest);
            a_cost[closest] = map[cur][closest];

            //set cur to closest node
            cur = closest;

        }

    }
    
    UINT x;
    printf("     Node  |  Cost  |  Prev  |\n");
    for (x=0; x < SIZE; x++){
        printf("|%d|    %c   |    %d   |    %c   |\n", x, a_nodes[x], a_cost[x], a_prev[x]);
    }
}





















