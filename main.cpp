#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <time.h>
using namespace std;

ofstream ofile;
void output( double, double, double, double, double);
int main(int argc, char* argv[])
{
    char *outfilename;
    if(argc <= 1){
        cout << "Bad Usage: " << argv[0] <<
            " read also output file on same line" << endl;
    }
    else{
        outfilename = argv[1];
    }
    ofile.open(outfilename);

// Variables:
    //double M_e = 6e24;  // Mass of earth

    int N = 1000000;        // Number of steps
    double t_max = 10000.0;  //Final time
    double time = 0.0;
    double h = t_max/N;  //time step

    double pi = acos(-1.0);
    double FourPi2 = 4*pi*pi;
    double hFourPi2 = h*FourPi2;

// Initial values:
    double x = 1.0;
    double y = 0;
    double vx = 0;
    double vy = 2*pi;
    double r = sqrt(x*x+y*y);

    clock_t start, finish;  //  declare start and final time
    start = clock();

// Euler method:
    ofile << N+1<<" ";
    ofile << t_max<<" ";
    ofile << vy<<"\n";
    ofile << "Time, x, y, vx, vy\n";
    for (int i = 0; i <= N; i++){
         x  = x + h*vx;
         y  = y + h*vy;
         vx = vx - hFourPi2/(r*r*r)*x;
         vy = vy - hFourPi2/(r*r*r)*y;
         r = sqrt(x*x+y*y);

         time += h;
         output(time, x, y, vx, vy);  // write to file
    }
    finish = clock();
    cout << ( (finish - start)/double(CLOCKS_PER_SEC) );
    ofile.close();
    return 0;
}

void output(double time, double x, double y, double vx, double vy){
    ofile << setiosflags(ios::showpoint | ios::uppercase);
          ofile << setw(15) << setprecision(8) << time;
          ofile << setw(15) << setprecision(8) << x;
          ofile << setw(15) << setprecision(8) << y;
          ofile << setw(15) << setprecision(8) << vx;
    ofile << setw(15) << setprecision(8) << vy << endl;
}
#include "time.h"   //  you have to include the time.h header

