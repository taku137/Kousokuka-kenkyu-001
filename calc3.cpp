#include <cmath>
#include <iostream>
#include <fstream>
#include <time.h>
#define FILE "GATASAN2.dat"
int main(){
    
    const long long CCC = 535;
    long long C=0;
    long long k, THETA0, THETA1;
    double  S1, S2, S3, S4, F;
    std::ofstream outputfile(FILE);
    double alpha =0.0;
    C=65535;
    for(long s=3500; s<=7000; s++){
    alpha = 0.001*(s-1);
    
    THETA0=0; THETA1=0;
    S1=0.0; S2=0.0; S3=0.0; S4=0.0; F=0.0;
    
        clock_t start = clock();

        for(long long k=0; k<=C; k++){
            THETA0 = pow(k,alpha);
            THETA1 = pow(k,alpha);
            S1 = S1 + cos(THETA1);
            S2 = S2 + sin(THETA0);
            S4 = S4 + cos(THETA0);
            S3 = S3 + sin(THETA1);
        }
        F = S1*S2 + S3*S4;    
        clock_t end = clock();
        const double time = static_cast<double>(end-start)/(CLOCKS_PER_SEC);

        std::cout << "Alpha: " << alpha << "   SUM: "<< F << std::endl;

        outputfile  << "Alpha: " << alpha 
                    << " SUM: " << F 
                    << " CPU-TIME: "<< time << "\n";
        
    }
    


    std::cerr << "Please push any key;";

    std::getchar();
    outputfile.close();
    return 0;
}