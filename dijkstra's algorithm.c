#include <stdio.h>
#include <limits.h>
#define V 5

int heap[V], pos[V], dist[V], size=0;
int G[V][V]={{0,9,6,0,0},{9,0,11,5,0},{6,11,0,8,10},{0,5,8,0,15},{0,0,10,15,0}};

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}
void heapify_down(int i){
    int l=2*i+1,r=2*i+2,sm=i;
    if(l<size && dist[heap[l]]<dist[heap[sm]]) sm=l;
    if(r<size && dist[heap[r]]<dist[heap[sm]]) sm=r;
    if(sm!=i){pos[heap[i]]=sm;pos[heap[sm]]=i;swap(&heap[i],&heap[sm]);heapify_down(sm);}
}
void heapify_up(int i){
    int p=(i-1)/2;
    if(i && dist[heap[i]]<dist[heap[p]]){
        pos[heap[i]]=p;pos[heap[p]]=i;swap(&heap[i],&heap[p]);heapify_up(p);
    }
}
void build_heap(){for(int i=size/2-1;i>=0;i--)heapify_down(i);}
int extract_min(){
    int root=heap[0];heap[0]=heap[--size];pos[heap[0]]=0;heapify_down(0);return root;
}
void decrease_key(int v,int newd){dist[v]=newd;heapify_up(pos[v]);}

int main(){
    int vis[V]={0};
    for(int i=0;i<V;i++){dist[i]=INT_MAX;heap[i]=i;pos[i]=i;} size=V;
    build_heap(); dist[0]=0; decrease_key(0,0);
    while(size){
        int u=extract_min(); vis[u]=1;
        for(int v=0;v<V;v++) if(G[u][v]&&!vis[v]&&dist[u]+G[u][v]<dist[v])
            decrease_key(v,dist[u]+G[u][v]);
    }
    printf("Vertex\tDist\n");
    for(int i=0;i<V;i++) printf("%d\t%d\n",i,dist[i]);
}
