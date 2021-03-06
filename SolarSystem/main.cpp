#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <random>
#include <chrono>
#include <time.h>
#include "planet.h"
#include "solver.h"
#include <vector>

using namespace std;

void PrintInitialValues(int, double, double, double *, double *, int);
void PrintFinalValues(int, double *, double *);


int main()
{
    int IntegrationPoints;  // No. of integration points
    double FinalTime;       // End time of calculation
    int Dimension;           // No. of spatial dimensions

        cout << "Earth-Sun binary system" << endl;
        Dimension = 3;

        IntegrationPoints = 10000;
        FinalTime = 50     ;

        double TimeStep = FinalTime/((double) IntegrationPoints);
        double x[3],v[3];  // positions and velocities
        // initial position x = 1AU, y = z = 0, vx = 2pi, vy=0, vz=0
        planet planet1(0.000003,8.77e-1,4.81e-1,-1.56e-4,-8.51e-3*365,1.51e-2*365,-4.66e-7*365); // Earth: (mass,x,y,z,vx,vy,vz)
        planet planet2(9.5e-4,-4.56,-2.95,1.14e-1,4.01e-3*365,-5.98e-3*365,-6.49e-5*365); //Jupiter: (mass,x,y,z,vx,vy,vz)
        //planet planet1(0.000003, 1, 0.,0.,0.,6.3, 0.);
        //planet planet2(9.5e-4*1000, 5.2, 0.,0., 0., 2*3.14*5.2/12, 0.);
        planet planet3(3.3e-7,-1.58,5.12e-1,4.94e-2,-3.74e-3*365,-1.21e-2*365,-1.62e-4*365); //Mars
        planet planet4(2.45e-6, -6.80e-1, 2.30e-1, 4.23e-2,-6.41e-3*365,-1.93e-2*365, 1.05e-4*365); //Venus
        planet planet5(2.75e-4, -3.26e-1,-1.01e1,1.88e-1,5.27e-3*365, -1.99e-4*365, -2.06e-4*365); //Saturn
        planet planet6(1.65e-7, -2.51e-1, -3.77e-1, -8.17e-3, 1.78e-2*365, -1.42e-2*365, -2.79e-3*365); //Merkur
        planet planet7(4.4e-5, 1.79e1,8.83,-1.98e-1, -1.77e-3*365, 3.34e-3*365, 3.52e-5*365); //Uranus
        planet planet8(5.5e-5, 2.86e1, -8.81, -4.78e-1, 9.03e-4*365, 3.02e-3*365, -8.32e-5*365); //Neptun

        solver binary_vv(50.0);
        binary_vv.add(planet1);
        binary_vv.add(planet2);
       binary_vv.add(planet3);
        binary_vv.add(planet4);
        binary_vv.add(planet5);
        binary_vv.add(planet6);
        binary_vv.add(planet7);
        binary_vv.add(planet8);

        vector<double> sunStartVel= binary_vv.startVelocitySun();
        vector<double> sunStartPos = binary_vv.startPositionSun();


        planet sun(1.,sunStartPos[0],sunStartPos[1],sunStartPos[2],sunStartVel[0],sunStartVel[1],sunStartVel[2]);
        //planet sun(1., -4.943e-3, 0.,0., 0, -(0.000003*6.3-9.5e-4*2*3.14*5.2/12),0.);
        binary_vv.add(sun);


        PrintInitialValues(Dimension,TimeStep,FinalTime,x,v,IntegrationPoints);

        cout << "Velocity Verlet results for the Sun-Earth system:" << endl;
        binary_vv.VelocityVerlet(Dimension,IntegrationPoints,FinalTime,9,0.);

        for(int j = 0; j < Dimension;j++){
            x[j] = binary_vv.all_planets[0].position[j];
            v[j] = binary_vv.all_planets[0].velocity[j];
        }
        PrintFinalValues(Dimension,x,v);
    return 0;
}



void PrintInitialValues(int Dimension,double TimeStep, double FinalTime,double *x_initial,double *v_initial, int N){
    // A function that prints out the set up of the calculation

    cout << "Time step = " << TimeStep << "; final time = " << FinalTime << "; integration points = " << N << endl;

    cout << "Initial position = ";
    for(int j=0;j<Dimension;j++) cout << x_initial[j] << " ";
    cout << endl;

    cout << "Initial velocity = ";
    for(int j=0;j<Dimension;j++) cout << v_initial[j] << " ";
    cout << endl;
}

void PrintFinalValues(int Dimension,double *x_final,double *v_final){
    // A function that prints out the final results of the calculation

    cout << "Final position = ";
    for(int j=0; j<Dimension; j++) cout << x_final[j] << " ";
    cout << endl;

    cout << "Final velocity = ";
    for(int j=0; j<Dimension; j++) cout << v_final[j] << " ";
    cout << endl;
}

