#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double my_fun(double x);
double m_hord(double x1, double x2, double iter, double eps, double mod);
double m_dil(double x1, double x2, double eps, double mod, double iter );
int var3();

int main()
{
    int var;
    double x1, x2, eps, iter, mod, start, stop;

    printf("|1 - Method Hords|\n|2 - Method Half Division|\nChoice you method = ");
    scanf("%i", &var);
    printf("Enter your data:\n");

        do{
            printf("x1 = ");
            scanf("%lf", &x1);
            printf("x2 = ");
            scanf("%lf", &x2);
        }while((my_fun(x1)*my_fun(x2)>0));

    printf("eps = ");
    scanf("%lf", &eps);
    printf("Iterations = ");
    scanf("%lf", &iter);
    printf("mode = ");
    scanf("%lf", &mod);

    start = clock();

         if(var==1) m_hord(x1,x2,iter,eps,mod);
    else if(var==2) m_dil(x1,x2,iter,eps,mod);
    else var3();

    stop = clock();
    printf("\nTime spent=%lf", (stop-start)/CLK_TCK);
    getch();
   return 0;
}
int var3(){
    printf("Start again\n");
    main();
}
double my_fun(double x){
    return pow(x+2,2)-pow(x,3);
}
double m_hord(double x1, double x2, double iter, double eps, double mod){
    double f1, f2, x;
    double max = INFINITY;
    unsigned int n, N=iter, i=0;
    do{
         do{
            printf("what will you do next?\n 1-exit  result\n2-plus iteration\n3-just find root\n");
            scanf("%u",&n);
            printf("\n");
                 if(n==1) break;
            else if(n==2) iter+=N;
            else if(n==3) iter=max;
        }while(i==iter);

        f2 = my_fun(x2);
        f1 = my_fun(x1);
        x1=x2-((x2-x1)*f2)/(f2-f1);
        x2=x1-((x1-x2)*f1)/(f1-f2);
        i++;

        if(mod==1){
            printf("x = %0.4f, F(x) = %0.4f, iteration = %0.4u\n", x2, f2, i);
        }
    }while(fabs(f2) > eps && i<1000);

printf("x = %0.f, f(x) = %0.f, iteration = %0.u\n", x2, f2, i);
}

double m_dil(double x1, double x2, double eps, double mod, double iter ){
    double x, f, f1, f2;
    double max = INFINITY;
    unsigned int n, N=iter, i=0;
    do{
         do{
            printf("what will you do next?\n 1-exit  result\n2-plus iteration\n3-just find root\n");
            scanf("%u",&n);
            printf("\n");
                 if(n==1) break;
            else if(n==2) iter+=N;
            else if(n==3) iter=max;
        }while(i==iter);

        f2 = my_fun(x2);
        f1 = my_fun(x1);
            x = (x1 + x2) / 2;
            f = my_fun(x);
            if(f1*f2<0) (x2 = x);
            else (x1 = x);
            i++;
            if(mod==1){
            printf("x = %0.4f, F(x) = %0.4f, iteration = %0.4u\n", x, f, i);
        }
        }while(fabs(f) > eps && i < 1000);

    printf("x = %0.4f, F(x) = %0.4f, iteration = %0.4u\n", x, f, i);
}
