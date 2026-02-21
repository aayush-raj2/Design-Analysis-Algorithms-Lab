#include <stdio.h>
#include <stdlib.h>

void add(int **A, int **B, int **C, int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int **A, int **B, int **C, int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int **A, int **B, int **C, int n) {
    if(n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n/2;

    int i,j;

    int **A11 = malloc(k*sizeof(int*));
    int **A12 = malloc(k*sizeof(int*));
    int **A21 = malloc(k*sizeof(int*));
    int **A22 = malloc(k*sizeof(int*));
    int **B11 = malloc(k*sizeof(int*));
    int **B12 = malloc(k*sizeof(int*));
    int **B21 = malloc(k*sizeof(int*));
    int **B22 = malloc(k*sizeof(int*));
    int **C11 = malloc(k*sizeof(int*));
    int **C12 = malloc(k*sizeof(int*));
    int **C21 = malloc(k*sizeof(int*));
    int **C22 = malloc(k*sizeof(int*));

    for(i=0;i<k;i++){
        A11[i]=malloc(k*sizeof(int));
        A12[i]=malloc(k*sizeof(int));
        A21[i]=malloc(k*sizeof(int));
        A22[i]=malloc(k*sizeof(int));
        B11[i]=malloc(k*sizeof(int));
        B12[i]=malloc(k*sizeof(int));
        B21[i]=malloc(k*sizeof(int));
        B22[i]=malloc(k*sizeof(int));
        C11[i]=malloc(k*sizeof(int));
        C12[i]=malloc(k*sizeof(int));
        C21[i]=malloc(k*sizeof(int));
        C22[i]=malloc(k*sizeof(int));
    }

    for(i=0;i<k;i++)
        for(j=0;j<k;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];
            A22[i][j]=A[i+k][j+k];
            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];
            B22[i][j]=B[i+k][j+k];
        }

    int **M1 = malloc(k*sizeof(int*));
    for(i=0;i<k;i++) M1[i]=malloc(k*sizeof(int));

    int **temp1 = malloc(k*sizeof(int*));
    int **temp2 = malloc(k*sizeof(int*));
    for(i=0;i<k;i++){
        temp1[i]=malloc(k*sizeof(int));
        temp2[i]=malloc(k*sizeof(int));
    }

    add(A11,A22,temp1,k);
    add(B11,B22,temp2,k);
    strassen(temp1,temp2,M1,k);

    for(i=0;i<k;i++)
        for(j=0;j<k;j++)
            C[i][j]=M1[i][j];  // simplified combine for demo

}

int main() {
    int n = 2;

    int **A = malloc(n*sizeof(int*));
    int **B = malloc(n*sizeof(int*));
    int **C = malloc(n*sizeof(int*));

    for(int i=0;i<n;i++){
        A[i]=malloc(n*sizeof(int));
        B[i]=malloc(n*sizeof(int));
        C[i]=malloc(n*sizeof(int));
    }

    A[0][0]=1; A[0][1]=2;
    A[1][0]=3; A[1][1]=4;

    B[0][0]=5; B[0][1]=6;
    B[1][0]=7; B[1][1]=8;

    strassen(A,B,C,n);

    printf("Result Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    return 0;
}
