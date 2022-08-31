/*
 1  function Dijkstra(Graph, source):
 2      
 3      for each vertex v in Graph.Vertices:
 4          dist[v] ← INFINITY
 5          prev[v] ← UNDEFINED
 6          add v to Q
 7      dist[source] ← 0
 8      
 9      while Q is not empty:
10          u ← vertex in Q with min dist[u]
11          remove u from Q
12          
13          for each neighbor v of u still in Q:
14              alt ← dist[u] + Graph.Edges(u, v)
15              if alt < dist[v]:
16                  dist[v] ← alt
17                  prev[v] ← u
18
19      return dist[], prev[]
*/

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

    UINT prev = 0, cur = 0;
    int y;
    for (y=0; y < SIZE; y++){
        //determine what node is closest
        UINT closest;
        {//Scope this logic for mem purposes
            UINT weight = 9999999;
            UINT x;
            for (x=0; x<SIZE; x++){
                if (map[cur][x] < weight){
                    closest = x;
                    weight = map[cur][x];
                }
            }
        }
        printf("%i", closest);
        
        //set prev to cur
        //set cur to closest node
    }
}





















