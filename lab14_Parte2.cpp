#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

const double k = 100;
const double m = 2;
const double lambda = 1;
const double G = 0.7;
const double dt = 0.01;
const double tf = 14.0;

double velocidady(double t,double y, double vy); 
double aceleraciony(double t,double y, double vy);
void euler(double y, double vy, double tf, string name);
void rk4(double t, double dt, double &y, double &vy);
void rk4confriccion(double t, double dt, double &y, double &vy);

int main()
{
	double y,vy,yf,vyf;
	y = 1.0;
	vy = 0.0;
    
    yf = 1.0;
    vyf = 0.0;
    
    euler(y,vy,tf,"euler.dat");
    
    ofstream outfile;
    outfile.open("datos.dat");
	for(double time = 0.0; time <= tf; time += dt)
    {
		outfile <<time<< "\t" << y << "\t" << vy << "\t" << yf << "\t" << vyf<<endl;
		rk4(time, dt, y, vy);
        rk4confriccion(time, dt,yf,vyf);
    }
    outfile.close();
    return 0;
}

double velocidady(double t, double y, double vy)
{
  return vy;
}

double aceleraciony(double t, double y, double vy)
{
  return (-k/m)*pow(y,lambda);
}

double aceleracionyfriccion(double t, double y, double vy)
{
  return (-k/m)*pow(y,lambda) - G*vy;
}

void euler(double y, double v, double tfinal, string name)
{
    double yn,vn;
   
    ofstream outfile;
    outfile.open(name);
    for(double t=0;t<=tfinal;t+=dt){
        yn=y;
        vn=v;
        y += dt*vn;
        v -= dt*(k/m)*yn;
        outfile << t << "\t" << y << "\t" << v << endl;
    }
    outfile.close();
}

void rk4(double t, double dt, double &y, double &vy) 
{
    double k1y, k1vy, k2y, k2vy, k3y, k3vy, k4y, k4vy;
    
    k1y = dt*velocidady(t, y, vy);
    k1vy = dt*aceleraciony(t, y, vy);
    k2y = dt*velocidady(t + dt/2, y + k1y/2, vy + k1vy/2);
    k2vy = dt*aceleraciony(t+ dt/2, y + k1y/2, vy + k1vy/2);
    k3y = dt*velocidady(t + dt/2, y + k2y/2, vy + k2vy/2);
    k3vy = dt*aceleraciony(t+ dt/2, y + k2y/2, vy + k2vy/2);
    k4y = dt*velocidady(t + dt, y + k3y, vy + k3vy);
    k4vy = dt*aceleraciony(t + dt, y + k3y, vy + k3vy);
    
	y = y + (1.0/6.0)*(k1y + 2*k2y + 2*k3y + k4y);
    vy = vy + (1.0/6.0)*(k1vy + 2*k2vy + 2*k3vy + k4vy);
}


void rk4confriccion(double t, double dt, double &y, double &vy) 
{
    double k1y, k1vy, k2y, k2vy, k3y, k3vy, k4y, k4vy;
    
    k1y = dt*velocidady(t, y, vy);
    k1vy = dt*aceleracionyfriccion(t, y, vy);
    k2y = dt*velocidady(t+dt/2, y + k1y/2, vy + k1vy/2);
    k2vy = dt*aceleracionyfriccion(t+dt/2, y + k1y/2, vy + k1vy/2);
    k3y = dt*velocidady(t+dt/2, y + k2y/2, vy + k2vy/2);
    k3vy = dt*aceleracionyfriccion(t+dt/2, y + k2y/2, vy + k2vy/2);
    k4y = dt*velocidady(t + dt, y + k3y, vy + k3vy);
    k4vy = dt*aceleracionyfriccion(t + dt, y + k3y, vy + k3vy);
    
	y = y + (1.0/6.0)*(k1y + 2*k2y + 2*k3y + k4y);
    vy = vy + (1.0/6.0)*(k1vy + 2*k2vy + 2*k3vy + k4vy);
}