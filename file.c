#include <stdio.h>
#include "grid.h"
#include "file.h"

// 🔹 Save grid to file
void saveToFile() {
    FILE *fp = fopen("grid.txt", "w");

    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Save dimensions
    fprintf(fp, "%d %d\n", rows, cols);

    // Save start and goal
    fprintf(fp, "%d %d\n", sx, sy);
    fprintf(fp, "%d %d\n", gx, gy);

    // Save grid
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            fprintf(fp, "%d ", grid[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Grid saved successfully \n");
}

// 🔹 Load grid from file
void loadFromFile() {
    FILE *fp = fopen("grid.txt", "r");

    if(fp == NULL) {
        printf("File not found!\n");
        return;
    }

    // Load dimensions
    fscanf(fp, "%d %d", &rows, &cols);

    // Load start and goal
    fscanf(fp, "%d %d", &sx, &sy);
    fscanf(fp, "%d %d", &gx, &gy);

    // Load grid
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            fscanf(fp, "%d", &grid[i][j]);
        }
    }

    fclose(fp);
    printf("Grid loaded successfully \n");
}