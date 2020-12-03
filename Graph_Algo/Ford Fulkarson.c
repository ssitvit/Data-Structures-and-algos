#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 1000
#define oo 1000000000
int n;  
int e;  
int capacity[MAX_NODES][MAX_NODES]; 
int flow[MAX_NODES][MAX_NODES];
int color[MAX_NODES];           
int pred[MAX_NODES];  

int min (int x, int y) {
    return x<y ? x : y; 
}
int head,tail;
int q[MAX_NODES+2];

void enqueue (int x) {
    q[tail] = x;
    tail++;
    color[x] = GRAY;
}

int dequeue () {
    int x = q[head];
    head++;
    color[x] = BLACK;
    return x;
}
int bfs (int start, int target) {
    int u,v;
    for (u=0; u<n; u++) {
	color[u] = WHITE;
    }   
    head = tail = 0;
    enqueue(start);
    pred[start] = -1;
    while (head!=tail) {
	u = dequeue();
	for (v=0; v<n; v++) {
	    if (color[v]==WHITE && capacity[u][v]-flow[u][v]>0) {
		enqueue(v);
		pred[v] = u;
	    }
	}
    }
    return color[target]==BLACK;
}

int max_flow (int source, int sink) {
    int i,j,u;
    int max_flow = 0;
    for (i=0; i<n; i++) {
	for (j=0; j<n; j++) {
	    flow[i][j] = 0;
	}
    }
    while (bfs(source,sink)) {
	int increment = oo;
	for (u=n-1; pred[u]>=0; u=pred[u]) {
	    increment = min(increment,capacity[pred[u]][u]-flow[pred[u]][u]);
	}
	for (u=n-1; pred[u]>=0; u=pred[u]) {
	    flow[pred[u]][u] += increment;
	    flow[u][pred[u]] -= increment;
	}
	max_flow += increment;
    }
    return max_flow;
}

void read_input_file() {
    int a,b,c,i,j;
    FILE* input = fopen("data.txt","r");
    fscanf(input,"%d %d",&n,&e);
    printf("\nNumber of Vertices : %d   Edges : %d",n,e);
    for (i=0; i<n; i++) {
	for (j=0; j<n; j++) {
	    capacity[i][j] = 0;
	}
    }
    for (i=0; i<e; i++) {
	fscanf(input,"%d %d %d",&a,&b,&c);
	capacity[a][b] = c;
	printf("\nA : %d  B : %d  Capacity : %d",a,b,c);
    }
    fclose(input);
}

int main () {
    read_input_file();
    printf("\nPlease enter Source(s) and Sink(t) :\n");
    int s=0,t=n-1;
    scanf("%d %d",&s,&t);
    printf("\nMax Flow : %d\n",max_flow(s,t));
    return 0;
}
