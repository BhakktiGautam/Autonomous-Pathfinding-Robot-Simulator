#include <stdio.h>
#include "grid.h"
int dist[50][50];
int grid[50][50];
int rows, cols;
int sx, sy, gx, gy;

int visited[50][50];
int parentX[50][50];
int parentY[50][50];

void creategrid() {
    printf("Enter rows and cols: ");
    scanf("%d%d",&rows ,&cols);

    printf("Enter start: ");
    scanf("%d%d",&sx,&sy);

    printf("Enter goal: ");
    scanf("%d%d",&gx,&gy);

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            grid[i][j]=0;

    int obstacles;
    scanf("%d",&obstacles);

    for(int i=0;i<obstacles;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        grid[x][y]=1;
    }
}

void displaygrid() {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(i==sx && j==sy) printf("S ");
            else if(i==gx && j==gy) printf("G ");
            else if(grid[i][j]==1) printf("X ");
            else if(grid[i][j]==2) printf("* ");
            else printf(". ");
        }
        printf("\n");
    }
}

void clearPath() {
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(grid[i][j]==2)
                grid[i][j]=0;
}

void initialize() {
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++) {
            visited[i][j]=0;
            parentX[i][j]=-1;
            parentY[i][j]=-1;
        }
}