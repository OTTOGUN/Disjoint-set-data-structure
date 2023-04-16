#include <stdio.h>
#include <stdlib.h>
#define VERTICES 6

#define ERROR 0
#define OK 1

void Initialise(int* parent){      //≥ı ºªØq
    for(int i = 0;i < VERTICES;i++){
        parent[i] = -1;
    }
}

int Find_root(int x,int* parent){
    int x_root = x;
    while(parent[x_root] != -1){
        x_root = parent[x_root];
    }
    return x_root;
}

//1 >>> union successfully, 0 >>> failed
int Union_Vertices(int x,int y,int* parent){
    int x_root = Find_root(x,parent);
    int y_root = Find_root(y,parent);
    if(x_root == y_root){
        return ERROR;
    }else{
        parent[x_root] = y_root;
        return OK;
    }
}

int main(){
    int parent[VERTICES] = {0};
    int edges[6][2] = {{0,1},{1,2},{1,3},{2,4},{3,4},{2,5}};
    Initialise(parent);

    for(int i = 0;i < VERTICES;i++){
        int x = edges[i][0];
        int y = edges[i][1];
        if(Union_Vertices(x,y,parent) == 0){
            printf("Cycle detected!\n");
            exit(0);
        }
    }
    printf("NO cycles found.");
}