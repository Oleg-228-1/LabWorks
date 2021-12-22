#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LINE_SIZE 10

void array_file(int x, int Fx, int count, int **array);
int main()
{
    char Line_1[LINE_SIZE];
    char Line_2[LINE_SIZE];
    char Line_3[LINE_SIZE];
    char Line_4[LINE_SIZE];
    char Line_5[LINE_SIZE];
    int x1, x2, N, krok, x, Fx;
//
    FILE *Data;
    Data = fopen("D:\\laba5\\Input.dat.txt", "rt");
        if ( NULL != fgets ( Line_1, sizeof(Line_1), Data ) ) printf("%s",Line_1);
        if ( NULL != fgets ( Line_2, sizeof(Line_2), Data ) ) x1 = atoi(Line_2); printf("%s",Line_2);
        if ( NULL != fgets ( Line_3, sizeof(Line_3), Data ) ) x2 = atoi(Line_3); printf("%s",Line_3);
        if ( NULL != fgets ( Line_4, sizeof(Line_4), Data ) ) N = atoi(Line_4); printf("%s",Line_4);
        if ( NULL != fgets ( Line_5, sizeof(Line_5), Data ) ) krok = atoi(Line_5); printf("%s\n",Line_5);
    fclose(Data);
    int i,j;
    int **array;
        array = malloc(sizeof(*array) * N);
        for(int i=0; i<N; i++){
            array[i] = malloc(sizeof(**array));
        }
        for(x = x1; x <= x2; x=x+krok){
            Fx = powf(x,3)/(2*x);
            array_file(x, Fx, i, array);
            i++;
        }
//
    FILE *result;
    result = fopen("D:\\laba5\\Result.txt", "wt");
    fprintf(result, "%d\n", N);
        for(i = 0; i<N; i++){
            j = 0;
            fprintf(result, "%d %d\n", array[i][j], array[i][j+1]);
        }
//int fprintf( FILE * stream, const char * format, ... );
    fclose(result);
//
    FILE *result_bin;
    result_bin = fopen("D:\\laba5\\Result.bin.txt", "wb");
    fwrite(&N, 1, sizeof(N), result_bin);
//size_t fwrite( const void * ptrvoid, size_t size, size_t count, FILE * filestream );
    int arr_1cols[N];
    int arr_2cols[N];
        for(i=0; i<N; i++){
            arr_1cols[i] = array[i][0];
        }
        for(i=0; i<N; i++){
            arr_2cols[i] = array[i][1];
        }
    fwrite(arr_1cols, 1, sizeof(arr_1cols), result_bin);
    fwrite(arr_2cols, 1, sizeof(arr_2cols), result_bin);
    fclose(result_bin);
//
    result_bin = fopen("D:\\laba5\\Result.bin.txt", "rb");
    fread(&N, 1, sizeof(N), result_bin);
    fread(arr_1cols, 1, sizeof(arr_1cols), result_bin);
    fread(arr_2cols, 1, sizeof(arr_2cols), result_bin);

        for(i=0; i<N; i++){
            array[i][0] = arr_1cols[i];
        }
        for(i=0; i<N; i++){
            array[i][1] = arr_2cols[i];
        }
    fclose(result_bin);
//
    N=1;
        for(i=0; i<N; i++){
            j = 0;
            x = array[i][j];
            Fx = array[i][j+1];
            printf("+---------------+---------------+---------------+\n");
            printf("|\t %d\t|\t %d \t|\t %d \t|\t\n", N, x, Fx);
            printf("+---------------+---------------+---------------+\n");
            N++;
        }
    return 0;
}
void array_file(int x, int Fx, int count, int **array){
    int i = count;
    int j = 0;
    array[i][j] = x;
    array[i][j+1] = Fx;
}
