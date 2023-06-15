#include <stdio.h>
#include <stdlib.h>

int *ColunadaMatriz(int *v1, int n, int m, int col){
    int *v2 = (int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        for(int j =0; j<m; j++){
            if(j==col){
                v2[i] =  v1[i*m + j];
                break;
            }  
        }
    }
    return v2;
}

int main(){
    int n=4, m=4;
    int *v1 = (int*)malloc(sizeof(int)*n*m);
    for(int i=0;i<n;i++){
        for(int j =0; j<m; j++){
            v1[i*m + j] = i+j;
        }
    }
    int *v2;
    v2 = ColunadaMatriz(v1, n, m, 2);
    for(int i=0; i<n; i++){
        printf("\n%d", v2[i]);
    }
}