#include <stdio.h>
#include "grid.h"
#include "dijkstra.h"


int stepsDijkstra = 0;

void initDijkstra() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            dist[i][j] = INF;
            visited[i][j] = 0;
            parentX[i][j] = -1;
            parentY[i][j] = -1;
        }
    }
    dist[sx][sy] = 0;
}

struct Node {
    int x, y, dist;
};

struct Node getMinNode() {
    struct Node minNode;
    minNode.dist = INF;
    minNode.x = -1;
    minNode.y = -1;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(!visited[i][j] && dist[i][j] < minNode.dist) {
                minNode.x = i;
                minNode.y = j;
                minNode.dist = dist[i][j];
            }
        }
    }
    return minNode;
}

void runDijkstra() {
    printf("Running Dijkstra...\n");

    initDijkstra();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    stepsDijkstra = 0;

    while(1) {
        stepsDijkstra++;

        struct Node current = getMinNode();

        if(current.x == -1) break;

        int x = current.x;
        int y = current.y;

        if(x == gx && y == gy) break;

        visited[x][y] = 1;

        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX >= 0 && newX < rows &&
               newY >= 0 && newY < cols &&
               grid[newX][newY] == 0 &&
               !visited[newX][newY]) {

                int newDist = dist[x][y] + 1;

                if(newDist < dist[newX][newY]) {
                    dist[newX][newY] = newDist;
                    parentX[newX][newY] = x;
                    parentY[newX][newY] = y;
                }
            }
        }
    }

    if(dist[gx][gy] == INF) {
        printf("No path found\n");
        return;
    }

    printf("Shortest path found (Dijkstra)\n");

    int x = gx, y = gy;
    while(!(x == sx && y == sy)) {
        grid[x][y] = 2;

        int tx = parentX[x][y];
        int ty = parentY[x][y];

        x = tx;
        y = ty;
    }
}