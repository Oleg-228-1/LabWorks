#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int Options(int Na, int Nb, int Mb);
void Max_Min_Matrix_A(int **a,int Na);
void Dobytok_A_B(int **a,int **b,int Na,int Nb,int Mb);
void Transposition_B(int **b,int Nb,int Mb);
void Sorting_A(int **a,int m1);
void Suma_Elements(int **a,int **b,int m1,int m2,int n2);

void main(){
    int Na = 0, Nb = 0, Mb = 0;
    printf("What size of your matrix A?:");
    scanf("%d",&Na);
    printf("What are the parameters of your matrix B?\n");
    printf("Cols B:");
    scanf("%d",&Nb);
    printf("Rows B:");
    scanf("%d",&Mb);
    Options(Na,Nb,Mb);

    return 0;
}
int Options(int Na, int Nb, int Mb){
    int **a;
    int **b;
    a = malloc(Na * sizeof(int *));
    for(int i=0;i < Na;i++){
        a[i] =  malloc(Na * sizeof(int));
    }
    b = malloc(Mb * sizeof(int *));
    for (int i = 0; i < Mb; i++){
        b[i] =  malloc(Nb * sizeof(int));
    }
    printf("Enter your matrix A parameters:\n");
        for (int i = 0; i < Na; i++){
            for (int j = 0; j < Na; j++){
                printf("a[%d][%d] = ", i, j);
                scanf("%d", &a[i][j]);
            }
        }
        printf("Your Matrix A:\n");
        for (int i = 0; i < Na; i++){
            for (int j = 0; j < Na; j++){
                printf("%d \t", a[i][j]);
            }
            printf("\n");
        }
    printf("Enter your matrix B parameters:\n");
        for (int i = 0; i < Mb; i++){
            for (int j = 0; j < Nb; j++){
                printf("b[%d][%d] = ", i, j);
                scanf("%d", &b[i][j]);
            }
        }
        printf("Your Matrix B:\n");
        for (int i = 0; i < Mb; i++){
            for (int j = 0; j < Nb; j++){
                printf("%d \t", b[i][j]);
            }
            printf("\n");
        }

    int variant=0;
    printf("(1)Find the maximum element of matrix A and the minimum of the elements?\n");
    printf("(2)Transpose matrix B?\n");
    printf("(3)Find the matrix product A * B?\n");
    printf("(4)Sort in ascending order the elements of the array A given from the keyboard?\n");
    printf("(5)Display the sum of the elements of rows of matrix A and columns of matrix B?\n");

    printf("Your actions: ",variant);
    scanf("%d", &variant);
             if(variant==1)
                Max_Min_Matrix_A(a,Na);
        else if(variant==2)
                Transposition_B(b,Nb,Mb);
        else if(variant==3)
                Dobytok_A_B(a,b,Na,Nb,Mb);
        else if(variant==4)
                Sorting_A(a,Na);
        else if(variant==5)
                Suma_Elements(a,b,Na,Nb,Mb);
    return 0;
}
void Max_Min_Matrix_A(int **a,int Na){
    int max = 1;
    int min = 0;
    for(int i = 0; i < Na; i++ ){
        for (int j = Na - 1; j > i;j--){
                if(a[i][j]>max)
                    max=a[i][j];
                else max;
                if(a[i][j]<min)
                   min=a[i][j];
                else min;
        }
    }
    printf("\nMaximum value is higher than the diagonal:%d",max);
    printf("\nMinimum value is higher than the diagonal:%d",min);
    min = 1;
    max = 0;
    for(int i = 0;i < Na;i++){
        for(int j = 0; j < i; j++){
                if(a[i][j]>max)
                    max=a[i][j];
                else max;
                if(a[i][j]<min)
                    min=a[i][j];
                else min;
        }
    }
    printf("\nMaximum value is below than the diagonal: %d",max);
    printf("\nMinimum value is below than the diagonal: %d\n",min);
}
void Transposition_B(int **b,int Nb,int Mb){
    int **Bt;
    Bt = malloc(Nb * sizeof(int *));
    for (int i = 0; i < Nb; i++){
        Bt[i] =  malloc(Mb * sizeof(int));
    }
    for(int i = 0;i < Nb;i++){
        for(int j = 0;j < Mb;j++){
            Bt[i][j] = b[j][i];
        }
    }
    printf("\n Transposed matrix B:\n");
    for(int i = 0;i < Nb;i++){
        for(int j = 0;j < Mb;j++){
            printf("%d\t",Bt[i][j]);
        }
        printf("\n");
    }
}
void Dobytok_A_B(int **a,int **b,int Na,int Nb,int Mb){
    int **c;
    c = malloc(Nb * sizeof(int *));

     if(Na != Nb ){
        printf("Wrong action!!!");
        return;
    }
    for(int i = 0; i < Nb;i++){
        for (int j = 0;j < Mb;j++){
            c[i][j] = a[i][j] * b[j][i];
        }
    }
    printf("\nDobutok matrix A and B:\n");
    for(int i = 0;i < Nb;i++){
        for(int j = 0;j < Mb;j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}
void Sorting_A(int **a,int Na){
    int row;
    int arr[Na];
    printf("Іelect your row: \t");
    scanf("%d",&row);
    row--;
    for(int i = 0 ; i < Na+1; i++){
       for(int j = 0 ; j < Na-i ; j++){
           if(a[row][j] > a[row][j+1]){
                int sort = a[row][j];
                a[row][j] = a[row][j+1];
                a[row][j+1] = sort;
           }
        }
    }
    printf("\n");
    for (int i = 0;i < Na+1;i++){
        printf("%d\t",a[row][i]);
    }
}
void Suma_Elements(int **a, int **b,int Na,int Nb,int Mb){
    int suma = 0;
    printf("Syma elements matrix A\n");
    for (int i = 0;i < Na;i++){
        for(int j = 0;j < Na;j++){
            suma+=a[i][j];
        }
        printf("%d\t",suma);
        suma = 0;
    }
    suma = 0;
    printf("\nSyma elements matrix B\n");
    for (int i = 0;i < Nb;i++){
        for(int j = 0;j < Mb;j++){
            suma+=b[j][i];
        }
        printf("%d\t",suma);
        suma = 0;
    }
}

