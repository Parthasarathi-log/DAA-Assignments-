#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main(){
    int w[]={0,2,3,4,5}, v[]={0,3,4,5,6}; 
    int n=4, W=5, K[5][6];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=W;j++)
            K[i][j]=(i==0||j==0)?0:(w[i]<=j?max(v[i]+K[i-1][j-w[i]],K[i-1][j]):K[i-1][j]);
    printf("Max value = %d\n",K[n][W]);
}
