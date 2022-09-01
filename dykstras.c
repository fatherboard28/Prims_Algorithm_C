/* 
   Jonathan Cunningham | Sep 1 2022
   -- dijkstras algorithm --
   Requirments:
    -map to be populated before running
   Restrictions:
    -map cannot be more than a 26x26
*/

#include <stdio.h>
#define UINT unsigned int

//Alphabet array
const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                      'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                      'U', 'V', 'W', 'X', 'Y', 'Z'};

//Adjacency matrix
int map[5][5] = {{0, 4, 12, 0, 11},
                 {4, 0, 0, 3, 7},
                 {12, 0, 0, 2, 1},
                 {0, 3, 2, 0, 4},
                 {12, 7, 1, 4, 0}};

//Size of data
const int SIZE = sizeof map[0] / sizeof map[0][0];

//Struct for print values
struct Vals{
    char nodes[SIZE];
    char prev[SIZE];
    UINT cost[SIZE];
};

struct Vals dijkstras(int map[SIZE][SIZE]){
    //Diplay these arrays for final output
    char a_nodes[SIZE];
    char a_prev[SIZE]; 
    UINT a_cost[SIZE]; 

    //populating display arrays
    UINT i;
    for (i=0; i < SIZE; i++){
        a_nodes[i] = letters[i];
        a_prev[i] = '-';
        a_cost[i] = 0;
    }

    //main algorithm
    UINT cur = 0;
    int y;
    for (y=0; y < SIZE; y++){

        //determine what node is closest
        // - requires cur to be on the correct node
        UINT closest;
        {   //Scope this logic for mem purposes
            UINT weight = -1;
            UINT x;
            for (x=0; x<SIZE; x++){
                if ((map[cur][x] < weight || weight == -1) && map[cur][x] != 0){
                    closest = x;
                    weight = map[cur][x];
                }
            }
        }
        
        //setup values for next itteration
        if (y != SIZE - 1){
            //set prev to cur
            a_prev[closest] = a_nodes[cur];

            //set weight from cur -> closest
            a_cost[closest] = map[cur][closest];

            //set cur to closest node
            cur = closest;

        }

    }

    struct Vals vals;
    {
        int i;
        for (i=0; i < SIZE; i++){
            vals.nodes[i] = a_nodes[i];
            vals.prev[i] = a_prev[i];
            vals.cost[i] = a_cost[i];
        }
    }

    return vals;
}

int main(void){
    //run dijkstras
    struct Vals printvals = dijkstras(map);
    
    UINT x;
    printf("| |  Node  |  Cost  |  Prev  |\n");
    for (x=0; x < SIZE; x++){
        printf("|%d|    %c   |    %d   |    %c   |\n", x, printvals.nodes[x], printvals.cost[x], printvals.prev[x]);
    }
}























