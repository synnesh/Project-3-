
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <time.h>
using namespace std;

ofstream ofile;
void output( double, double, double, double, double, double);
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
    double M_m = 1.65e-7;    // Mass of earth
    double c = 63198;  // Speed of light
    int N = 1000000000;            // Number of steps
    double t_max = 100.0;   //Final time
    double time = 0.0;
    double h = t_max/N;     //time step

    double FourPi2 = 4*M_PI*M_PI;
    double halfh = h/(2.0);
// Initial values:
    double x = 0.3075;
    double y = 0;
    double vx = 0;
    double vy = 12.44;
    double r = sqrt(x*x+y*y);

//Verlet:
    ofile << N+1<<" ";
    ofile << t_max<<" ";
    ofile << vy<<"\n";
    ofile << "Time, x, y, vx, vy, r\n";

    clock_t start, finish;  //  declare start and final time
    start = clock();
    double l, ax, ay;

    for (int i = 0; i <= N; i++){
        if(i%100000 == 0) cout<<i<<endl;
        l = abs(x*vy-y*vx);

        ax = -FourPi2/(r*r*r)*x*(1+3*l*l/(r*r*c*c));
        ay = -FourPi2/(r*r*r)*y*(1+3*l*l/(r*r*c*c));

        x = x + h*vx + (h*h)/(2.0)*ax;
        y = y + h*vy + (h*h)/(2.0)*ay;
        l = abs(x*vy-y*vx);
        r=sqrt(x*x+y*y);
        vx = vx + halfh*(-FourPi2/(r*r*r)*x*(1+3*l*l/(r*r*c*c)) + ax);
        vy = vy + halfh*(-FourPi2/(r*r*r)*y*(1+3*l*l/(r*r*c*c)) + ay);

        if(r<0.30755){
            output(time, x, y, vx, vy, r);
        }
        time += h;

    }


    finish = clock();
    cout<<((finish - start)/CLOCKS_PER_SEC );
    ofile.close();
    return 0;
}

void output(double time, double x, double y, double vx, double vy, double r){
    ofile << setiosflags(ios::showpoint | ios::uppercase);
          ofile << setw(15) << setprecision(8) << time;
          ofile << setw(15) << setprecision(8) << x;
          ofile << setw(15) << setprecision(8) << y;
          ofile << setw(15) << setprecision(8) << vx;
          ofile << setw(15) << setprecision(8) << vy;
    ofile << setw(25) << setprecision(16) << r << endl;
}
