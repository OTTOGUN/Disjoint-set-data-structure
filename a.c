#include <stdio.h>
#include <stdlib.h>
#define VERTICES 6

#define ERROR 0
#define OK 1

void Initialise(int* parent,int* rank){      //初始化双亲结点以及树的深度
    for(int i = 0;i < VERTICES;i++){
        parent[i] = -1;
        rank[i] = 0;
    }
}

int Find_root(int x,int* parent){
    int x_root = x;                 //递归求解
    while(parent[x_root] != -1){
        x_root = parent[x_root];
    }
    return x_root;
}

//1 >>> union successfully, 0 >>> failed
int Union_Vertices(int x,int y,int* parent,int* rank){
    int x_root = Find_root(x,parent);
    int y_root = Find_root(y,parent);       //若祖先相同则闭环，否则不是闭环
    if(x_root == y_root){
        return ERROR;
    }else{
        //parent[x_root] = y_root;              //尽可能地减小树地深度，让树深度大的继续作为祖先
            if(rank[x_root] > rank[y_root]){
            parent[y_root] = x_root;
        }else if(rank[y_root] > rank[x_root]){
            parent[x_root] = y_root;
        }else{
            parent[x_root] = y_root;            //若俩树的深度相等，则任意一方可以作为祖先，然后祖先树的深度加一
            rank[y_root]++;
        }
        return OK;
    }
}

int main(){
    int rank[VERTICES] = {0};
    int parent[VERTICES] = {0};
    int edges[6][2] = {{0,1},{1,2},{1,3},{2,4},{3,4},{2,5}};
    Initialise(parent,rank);

    for(int i = 0;i < VERTICES;i++){
        int x = edges[i][0];
        int y = edges[i][1];
        if(Union_Vertices(x,y,parent,rank) == 0){
            printf("Cycle detected!\n");
            exit(0);
        }
    }
    printf("NO cycles found.");
}