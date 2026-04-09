#include <stdio.h>
#include "grid.h"
#include "bfs.h"

int stepsBFS = 0;

int queueX[MAX], queueY[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int x, int y) {
    if(rear == MAX - 1) return;

    if(front == -1) front = 0;
    rear++;

    queueX[rear] = x;
    queueY[rear] = y;
}

void dequeue(int *x, int *y) {
    if(isEmpty()) return;

    *x = queueX[front];
    *y = queueY[front];
    front++;
}

void runBFS() {
    printf("Running BFS...\n");

    front = -1;
    rear = -1;

    initialize();

    enqueue(sx, sy);
    visited[sx][sy] = 1;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int found = 0;
    stepsBFS = 0;

    while(!isEmpty()) {
        stepsBFS++;

        int x, y;
        dequeue(&x, &y);

        if(x == gx && y == gy) {
            found = 1;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX >= 0 && newX < rows &&
               newY >= 0 && newY < cols &&
               grid[newX][newY] == 0 &&
               visited[newX][newY] == 0) {

                enqueue(newX, newY);
                visited[newX][newY] = 1;

                parentX[newX][newY] = x;
                parentY[newX][newY] = y;
            }
        }
    }

    if(!found) {
        printf("No path found\n");
        return;
    }

    printf("Path found (BFS)\n");

    int x = gx, y = gy;
    while(!(x == sx && y == sy)) {
        grid[x][y] = 2;

        int tx = parentX[x][y];
        int ty = parentY[x][y];

        x = tx;
        y = ty;
    }
}