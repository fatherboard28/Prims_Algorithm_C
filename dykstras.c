#include <stdio.h>
#define UINT unsigned int

int main(void){
    //Adjacency matrix
    int map[6][6] = {{ 0, 4, 2,  0, 0,  0},
                   { 4, 0, 1,  5, 0,  0},
                   { 2, 1, 0,  8, 10, 0},
                   { 0, 5, 8,  0, 2,  6},
                   { 0, 0, 10, 2, 0,  3},
                   { 0, 0, 0,  6, 3,  0}  };

    //Diplay these arrays for final output
    char a_nodes[6]   = {'A', 'B', 'C', 'D', 'E', 'F'};
    char a_prev[6]    = {'-', '-', '-', '-', '-', '-'};

    //Size of data
    int SIZE = sizeof map[0] / sizeof map[0][0];

    printf("SIZE: %d \nsizeof map[0]: %ld \nsizeof map[0][0]: %ld \n", SIZE, sizeof map[0], sizeof map[0][0]);

    UINT prev = 0, cur = 0;
    int y;
    for (y=0; y < SIZE; y++){
        //determine what node is closest
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
        
        //set prev to cur
        //set cur to closest node
    }
}





















