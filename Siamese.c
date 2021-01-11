#include<stdio.h>

void printmatrix(int n, int magicSquare[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%d ", magicSquare[i][j]);
        printf("\n");
    }
}

void fillMagicSquare(int n){
    int magicSquare[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            magicSquare[i][j]=0;

    int row=0,column=n/2;
    for(int number=1;number<=n*n;number++){
        magicSquare[row][column]=number;
        //if row overflows or column underflows bring them into range by using mod.
        if(magicSquare[(row-1)%n<0?(row-1)+n:row-1][(column+1)%n]==0){
            row=(row-1)%n<0?(row-1)+n:row-1;
            column=(column+1)%n;
        }
		else{
            row=row+1;
        }
    }
    printmatrix(n, magicSquare);
}

int main() {
	int n;
	printf("Enter the order of square matrix(only odd number permitted): ");
	scanf("%d",&n);
    if(n%2==1) {
        fillMagicSquare(n);
    }
    return 0;
}
