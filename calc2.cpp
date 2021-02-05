#include <cmath>
#include <iostream>
#include <fstream>
#include <time.h>
#define FILE "GATASAN.dat"
int main(){
    
    const long long CCC = 535;
    long long C=0;
    long long k, THETA0, THETA1;
    double  S1, S2, S3, S4, F;
    std::ofstream outputfile(FILE);
    
    #pragma omp parallel for private(C,THETA0,THETA1,S1,S2,S3,S4,k,F)
    for(long long i=1; i<=66; i++){
    THETA0=0; THETA1=0;
    S1=0.0; S2=0.0; S3=0.0; S4=0.0; F=0.0;
    C = CCC + (i-1)*1000;
        clock_t start = clock();
    
        for(long long k=0; k<=C; k++){
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

        std::cout << "SUP: " << C << "   SUM: "<< F << std::endl;

        outputfile  << "M,N: " << C 
                    << " SUM: " << F 
                    << " CPU-TIME: "<< time << "\n";
        
    }

    std::cerr << "Please push any key;";

    std::getchar();
    outputfile.close();
    return 0;
}