#include <stdio.h>
#include "grid.h"
#include "bfs.h"
#include "dijkstra.h"
#include "astar.h"
#include "file.h"

int main() {
    int choice;

    do {
        printf("\n1.Create Grid\n2.Display\n3.BFS\n4.Dijkstra\n5.A*\n6.Save\n7.Load\n8.Exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1: creategrid(); break;
            case 2: displaygrid(); break;
            case 3: clearPath(); runBFS(); displaygrid(); break;
            case 4: clearPath(); runDijkstra(); displaygrid(); break;
            case 5: clearPath(); runAstar(); displaygrid(); break;
            case 6: saveToFile(); break;
            case 7: loadFromFile(); break;
        }

    } while(choice != 8);

    return 0;
}