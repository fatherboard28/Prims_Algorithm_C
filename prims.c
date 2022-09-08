/* 
   Jonathan Cunningham | Sep 1 2022
   -- prims algorithm --
   Requirments:
    -map to be populated before running
   Restrictions:
    -map cannot be more than a 26x26
*/

#include <stdio.h>

//Alphabet array
const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
                      'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                      'U', 'V', 'W', 'X', 'Y', 'Z'};

//Adjacency matrix
int map[5][5] = {{0,  4, 13, 1,  0},
                 {4,  0, 8,  0,  3},
                 {13, 8, 0,  11, 6},
                 {1,  0, 11, 0,  2},
                 {0,  3, 6,  2,  0}};

//Size of data
const int SIZE = sizeof map[0] / sizeof map[0][0];

//Struct for print values
struct Vals{
    char prev[SIZE];
    int cost[SIZE];
};

struct Vals dijkstras(int map[SIZE][SIZE]){
    //Diplay these arrays for final output
    char a_prev[SIZE]; 
    int a_cost[SIZE]; 
    int a_unvisited[SIZE];

    //populating display arrays
    int i;
    for (i=0; i < SIZE; i++){
        a_prev[i] = '-';
        a_cost[i] = 99999;
        a_unvisited[i] = i;
    }


    //main algorithm
    int node;
    int count;
    for (count = 0; count < SIZE; count++){
        //Gets current working node
        int weight = 99999;
        for(i=SIZE-1; i > -1; i--){
            if (a_unvisited[i] != -1 && a_cost[i] <= weight){
                weight = a_cost[i];
                node = i;
            }
        }

        //updating a_unvisited to exlude current node
        a_unvisited[node] = -1;

        //setting cost to get to node 0 to 0
        a_cost[0] = 0;

        //looping through all connections of node to find any new shortest
        //paths to a node
        for (i=0; i < SIZE; i++){
            if (map[node][i]){
                //find distance to node i 
                int tempDis = map[node][i];
                    
                //update the cost to node i if it is shorter than prev cost
                if (tempDis < a_cost[i] 
                        && a_unvisited[i] != -1){
                    a_cost[i] = map[node][i];
                    a_prev[i] = letters[node];
                }
            }
        }

    }

    //creating and filling return struct
    struct Vals vals;
    {
        int i;
        for (i=0; i < SIZE; i++){
            vals.prev[i] = a_prev[i];
            vals.cost[i] = a_cost[i];
        }
    }

    return vals;
}

int main(void){
    //run dijkstras
    struct Vals printvals = dijkstras(map);
    
    int x;
    printf("| |  Node  |  Cost   |  Prev  |\n");
    for (x=0; x < SIZE; x++){
        printf("|%d|    %c   |    %2d   |    %c   |\n", x, letters[x], printvals.cost[x], printvals.prev[x]);
    }
    return 0;
}























