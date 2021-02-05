#include <cmath>
#include <iostream>
#include <fstream>
#include <time.h>
#define FILE "GATASAN.dat"
int main(){
    
    long long CCC;
    CCC = 535;
    long long k, THETA0, THETA1;
    double  S1, S2, S3, S4, F;
    std::ofstream outputfile(FILE);
    
    #pragma omp parallel for private(CCC,THETA0, THETA1,S1,S2,S3,S4,k,F)
    for(long long i=1; i<=66; i++){
    THETA0=0; THETA1=0;
    S1=0.0; S2=0.0; S3=0.0; S4=0.0; F=0.0;
    
        clock_t start = clock();
    
        for(long long k=0; k<=CCC; k++){
            THETA0 = 2+3*k+7*k*k;
            THETA1 = 5*k+11*k*k;
            S1 = S1 + cos(THETA1);
            S2 = S2 + sin(THETA0);
            S4 = S4 + cos(THETA0);
            S3 = S3 + sin(THETA1);
        }
        F = S1*S2 + S3*S4;    
        clock_t end = clock();
        const double time = static_cast<double>(end-start)/(CLOCKS_PER_SEC);

        std::cout << "SUP: " << CCC << "   SUM: "<< F << std::endl;

        outputfile  << "M,N: " << CCC 
                    << " SUM: " << F 
                    << " CPU-TIME: "<< time << "\n";
        CCC = CCC + 1000;
    }

    std::cerr << "Please push any key;";

    std::getchar();
    outputfile.close();
    return 0;
}