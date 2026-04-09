#ifndef GRID_H
#define GRID_H

#define MAX 2500
#define INF 99999

extern int grid[50][50];
extern int rows, cols;
extern int sx, sy, gx, gy;
extern int dist[50][50];

extern int visited[50][50];
extern int parentX[50][50];
extern int parentY[50][50];

void creategrid();
void displaygrid();
void clearPath();
void initialize();

#endif