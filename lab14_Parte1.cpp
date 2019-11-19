#include <iostream>
#include <cmath> 

using namespace std;

const float k = 100;
const float m = 2;
const float lambda = 1;

float euler(float y,float x, float dx);
float funcion(float x);

int main()
{
    float y = 0.0, x = 0.0, dx = 0.001;
    for(int i =0; i<50; i++)
    {
        y = euler(y,x,dx);
        cout<<x<<" "<<y<<endl;
        x = x+ dx;
    }
    
    return 0;
}

float funcion(float x)
{ 
    return (-k/m)*pow(y,lambda);
}

float euler(float y, float x, float dx)
{
    return y + dx*funcion(x);
}