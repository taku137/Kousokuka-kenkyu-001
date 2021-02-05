#include <cmath>
#include <iostream>
#include <time.h>
#define N 65535
#define M 65535
int main(){
    clock_t start = clock();
    long m, n;
    long THETA0[M+1]={0}, THETA1[N+1]={0};
    double F=0.0;
    
    
#if null
    m=0;
    for(int i = 0; i <= N; i++){
        THETA0 = 2+ 3*m + 7*m*m;
        n=0;
        for(int j = 0; j <= M; j++){
          THETA1 = 5*n + 11*n*n;
          F = F + sin(THETA0+THETA1);
          n++;
        }
    m++;
    }
#endif 
    m=0;
    n=0;
    for(int i=0; i<=M; i++){
        THETA0[i] = 2+3*m+7*m*m;
        THETA1[i] = 5*n+11*n*n;
    m++;
    n++;
    }
    int k;
    #pragma omp parallel for private(k) reduction(+:F)
    for(int j=0; j<=M; j++){
        for(k=0; k<=N; k++){
            F = F + sin(THETA0[j]+THETA1[k]);
        }
    }

    clock_t end = clock();
    const double time = static_cast<double>(end-start)/(CLOCKS_PER_SEC);
    
    std::cerr << "The answer is:  ";
    std::cout << F << std::endl;
    std::cerr << "CPU time is:  ";
    std::cout << time << std::endl;
    
    std::cerr << "Please push any key;";
    std::getchar();
    return 0;
}