#include <iostream>
#include <fstream>
using namespace std;


void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename);
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename);

float dzdt(float t, float y, float z, float omega);
float dydt(float t, float y, float z, float omega);

int main(){
  float omega=1.0;
  solve_equation_euler(0.0, 10000.0, omega/2, omega, "euler.dat");
  solve_equation_rk4(0.0, 10000.0, omega/2, omega, "rk4.dat");
  solve_equation_leapfrog(0.0, 10000.0, omega/2, omega, "leapfrog.dat");
  return 0;
}

void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename)
{
  float t=t_init;
  float y=1.0;
  float z=0.0,y_old,z_old;
  ofstream outfile;
  outfile.open(filename);

  while(t<t_end){    
    outfile << t << " " << y <<  " " << z << endl;
    y_old=y;
    z_old=z;
    y = y_old + delta_t * z;
    z = z_old-delta_t*omega*omega*y_old;
    t = t + delta_t;
  }
  outfile.close();
}


void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename)
{
    float a,b,f0,f1,f2,f3,R,yn,yn1,y2,yy2;
        
    ofstream outfile;
    outfile.open(filename);  
    
    yn=1.0;
    y2=0.0;
    
    a=-omega*omega;
    while (t_init<t_end)
    {
        f0=a*(yn);
        f1=a*(yn+(f0*delta_t)/2.0);
        f2=a*(yn+(f1*delta_t)/2.0);
        f3=a*(yn+(f2*delta_t));
            
        R=(f0/6.0+f1/3.0+f2/3.0+f3/6.0);// y n+1 
        
        yy2= y2+R*delta_t;
        yn1= yn+yy2*delta_t;
        
        outfile << t_init << " " << yn << " " << y2 <<endl;
        t_init=t_init+delta_t;
        yn=yn1;
        y2=yy2;
    }     
    outfile.close();
}
    
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename)
{
    float vmed,vn,dvdt,xn1,xn,dxdt,vn1;

    ofstream outfile;
    outfile.open(filename); 
    
    xn=1.0;
    vn=0.0;
    
    
    while (t_init<t_end)
    {
        dvdt=-omega*omega*xn;
        vmed=vn+(dvdt*delta_t)/2;
        xn=xn+vmed*delta_t;
        dvdt=-omega*omega*xn;
        vn=vmed+(dvdt*delta_t)/2;
        
        outfile << t_init << " " << xn << " " << vn <<endl;
        
        t_init=t_init+delta_t;
    }     
    
    outfile.close();
}









