#include <stdio.h>
#define V 4
#define INF 99999

int main(){
    int g[V][V]={{0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}};
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(g[i][k]+g[k][j]<g[i][j])
                    g[i][j]=g[i][k]+g[k][j];
    printf("Shortest distances:\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            printf("%7s", g[i][j]==INF?"INF":({static char b[10];sprintf(b,"%d",g[i][j]);b;}));
        printf("\n");
    }
}
