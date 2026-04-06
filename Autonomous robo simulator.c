#include<stdio.h>
#include<stdlib.h>


int grid[50][50];
int  rows,cols;
int sx,sy,gx,gy;


int visited[50][50];
int parentX[50][50];
int parentY[50][50]; 

int stepsBFS = 0;
int stepsDijkstra = 0;
int stepsAstar = 0;
#define MAX 2500     
int queueX[MAX];
int queueY[MAX];
int front=-1;
int rear=-1;

struct Node{
	int x,y;
	int dist;
};

int dist[50][50];
#define INF 99999
void init(){
for(int i=0;i<rows;i++)
    {
	for(int j=0;j<cols;j++)
	{
		dist[i][j]=INF;
		visited[i][j]=0;
		parentX[i][j]=-1;
		parentY[i][j]=-1;
		
	}



    }
	dist[sx][sy]=0;
}


struct Node getMinNode()
{
	struct Node minNode;
	minNode.dist=INF;
	minNode.x = -1;
    	minNode.y = -1;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(visited[i][j]==0&& dist[i][j]<minNode.dist)		
			{
				minNode.x=i;
				minNode.y=j;
				minNode.dist=dist[i][j];
			}
		}
	}
	return minNode;
}
int isEmpty()
{
    return (front == -1 || front > rear);
}


void enqueue(int x,int y)
{
	if(rear==MAX-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)
	front=0;
	rear++;
	queueX[rear]=x;
	queueY[rear]=y;
}
int heuristic(int x, int y)
{
    return abs(x - gx) + abs(y - gy);
}
struct Node getMinNodeAstar()
{
    struct Node minNode;
    int minF = INF;
    minNode.x = -1;
    minNode.y = -1;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(visited[i][j]==0)
            {
                int f = dist[i][j] + heuristic(i,j);

                if(f < minF)
                {
                    minNode.x = i;
                    minNode.y = j;
                    minF = f;
                }
            }
        }
    }
    return minNode;
}

void dequeue(int *x,int *y ){
 if(isEmpty())
{
	printf("Queue Underflow\n");
	return ;
}
*x=queueX[front];
*y=queueY[front];
front++;
}



void creategrid(){
printf("Creating grid...........\n");
printf("Enter rows and cols: ");
scanf("%d%d",&rows ,&cols);

printf("Enter start (x,y): ");
scanf("%d%d",&sx,&sy);

printf("Enter goal (x,y): ");
scanf("%d%d",&gx,&gy);

for(int i=0;i<rows;i++)
{
	for(int j=0;j<cols;j++)
	{
		grid[i][j]=0;
	}
}
int obstacles;
printf("Enter the number of obstacles:\n");
scanf("%d",&obstacles);
for(int i=0;i<obstacles;i++)
{
int x,y;
printf("Obstacle %d position : ",i+1);
scanf("%d%d",&x,&y);
grid[x][y]=1;
}

}

void clearPath()
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j] == 2)
                grid[i][j] = 0;
        }
    }
}
void displaygrid(){
printf("Displaying grid..........\n");
	printf("\n                 Grid                 \n");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				if(i==sx&&j==sy)
				{
					printf("S ");
				}
				else if(i==gx&& j==gy)
				{
					printf("G ");
				}
				else if(grid[i][j]==1)
				{
					printf("X ");
				}
				else if(grid[i][j]==2)
				{
  					 printf("* ");   
				}
				else
					printf(". ");
			}
			printf("\n");
		}
}
void initialize()
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			visited[i][j]=0;
			parentX[i][j]=-1;
			parentY[i][j]=-1;
		}
	}
}
void runBFS(){
printf("Running BFS...............\n");

front = -1;
rear = -1;
initialize();

enqueue(sx, sy);
visited[sx][sy] = 1;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int found=0;
stepsBFS = 0;
while (!isEmpty())
{
    stepsBFS ++;
	int x,y;
	dequeue(&x,&y);
	if(x==gx&&y==gy)
	{
		found=1;
		break;
	}
	for(int i=0;i<4;i++)
	{
		int newX=x+dx[i];
		int newY=y+dy[i];
		if(newX>=0&& newX<rows&& newY>=0 && newY<cols && grid[newX][newY]==0 && visited[newX][newY]==0)
		{
			enqueue(newX,newY);
			visited[newX][newY]=1;
			
			parentX[newX][newY]=x;
			parentY[newX][newY]=y;
		}
	}
}

if(!found)
{
	printf("No path found\n");
	return;
}
	printf("Path found\n");
	
int x=gx;
int y=gy;
while(!(x==sx &&y==sy))
{
	grid[x][y]=2;

	int tempX=parentX[x][y];
	int tempY=parentY[x][y];
	
	x=tempX;
	y=tempY;
}	
    

	
}
void runDijkstra()
{
    printf("Running Dijkstra...........\n");

    init();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    stepsDijkstra=0;
    while(1)
    {
        stepsDijkstra++;
        struct Node current = getMinNode();

        if(current.x == -1 || current.y == -1)
            break;

        int x = current.x;
        int y = current.y;

        if(x == gx && y == gy)
            break;

        visited[x][y] = 1;

        for(int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            //  FIXED CONDITION
            if(newX >= 0 && newX < rows &&
               newY >= 0 && newY < cols &&
               grid[newX][newY] == 0 &&
               visited[newX][newY] == 0)
            {
                int newDist = dist[x][y] + 1;

                if(newDist < dist[newX][newY])
                {
                    dist[newX][newY] = newDist;
                    parentX[newX][newY] = x;
                    parentY[newX][newY] = y;
                }
            }
        }
    }

    //  no path
    if(dist[gx][gy] == INF)
    {
        printf("No path found\n");
        return;
    }

    printf("Shortest Path Found! \n");
    printf("Distance = %d\n", dist[gx][gy]);

    //  BACKTRACK PATH
    int x = gx;
    int y = gy;

    while(!(x == sx && y == sy))
    {
        grid[x][y] = 2;

        int tempX = parentX[x][y];
        int tempY = parentY[x][y];

        x = tempX;
        y = tempY;
    }
}
void runAstar()
{
    printf("Running A*..................\n");

    init();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    stepsAstar = 0;
    while(1)
    {
        stepsAstar ++;
        struct Node current = getMinNodeAstar();

        if(current.x == -1 || current.y == -1)
            break;

        int x = current.x;
        int y = current.y;

        if(x == gx && y == gy)
            break;

        visited[x][y] = 1;

        for(int i=0;i<4;i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX >= 0 && newX < rows &&
               newY >= 0 && newY < cols &&
               grid[newX][newY] == 0 &&
               visited[newX][newY] == 0)
            {
                int newDist = dist[x][y] + 1;

                if(newDist < dist[newX][newY])
                {
                    dist[newX][newY] = newDist;
                    parentX[newX][newY] = x;
                    parentY[newX][newY] = y;
                }
            }
        }
    }

    if(dist[gx][gy] == INF)
    {
        printf("No path found\n");
        return;
    }

    printf("Path Found using A* 🚀\n");
    printf("Distance = %d\n", dist[gx][gy]);

    int x = gx;
    int y = gy;

    while(!(x == sx && y == sy))
    {
        grid[x][y] = 2;

        int tempX = parentX[x][y];
        int tempY = parentY[x][y];

        x = tempX;
        y = tempY;
    }
}
void compareAlgorithms()
{
    printf("\nComparing Algorithms.........\n");

    clearPath();
    runBFS();
    int distBFS = 0;

    int x = gx, y = gy;
    while(!(x == sx && y == sy))
    {
        distBFS++;
        int tempX = parentX[x][y];
        int tempY = parentY[x][y];
        x = tempX;
        y = tempY;
    }

    clearPath();
    runDijkstra();
    int distDijkstra = dist[gx][gy];

    clearPath();
    runAstar();
    int distAstar = dist[gx][gy];

    printf("\n===== RESULT =====\n");
    printf("BFS        -> Distance: %d | Steps: %d\n", distBFS, stepsBFS);
    printf("Dijkstra   -> Distance: %d | Steps: %d\n", distDijkstra, stepsDijkstra);
    printf("A*         -> Distance: %d | Steps: %d\n", distAstar, stepsAstar);
}
int main(){
int choice;
do{
	printf("\n============Autonomous Pathfinding Robot Simulator============\n");
	printf("1. Create Grid\n");
	printf("2.Display Grid\n");
        printf("3. Run BFS\n");
        printf("4. Run Dijkstra\n");
        printf("5. Run A*\n");
        printf("6. Compare Algorithms\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
	if(choice==1)
	{
		creategrid();
	}
	else if(choice==2)
	{
		displaygrid();
	}
	else if(choice==3)
	{
		clearPath();
		runBFS();
		displaygrid();
	}
	else if(choice==4)
	{
		clearPath();
		runDijkstra();
		displaygrid();
	}
	else if(choice==5)
	{
		clearPath();
		runAstar();
		displaygrid();
	}
	else if(choice==6)
	{
		compareAlgorithms();
	}
	else if(choice==7)
	{
		printf("Exiting the program\n");
		break;
	}
	else 
	{
		printf("Invalid input\n");
	}
}       while(choice!=6);
return 0;
}