#include <cmath>
#include <math.h>
#include <iostream>

using namespace std;

//3 base time values
//overwritten when user inputs
double a = 7.07023*pow(10, -4);
double b = 2.63474*pow(10, -4);
double c = 0.0;

//speed of propogation underwater
double s=1481;

//iteration times - basically farthest distance in the horizontal direction of pinger
int iter;

//these were for personal use - not used in code
double A[] = {.5,0};
double B[] = {-.5,0};
double C[] = {0,1};

/*
	My formula for the equation was 
	D(XA)-D(XB) = speed*(time difference)
	D(XA) stands for the distance from Transmitter X to Receiver A.
	X is the location of the transmitter

	THIS FORMULA IS THE BASIS OF THE SOLVEX AND SOLVEY FUNCTIONS
*/
double solvex(double y, double x)
{
	/* 	
	this function takes the y value from the next function, and puts it into this equation.
	The X value is inputted ( same as the x value for solvey() ) and therefore doesn't 
	leave any variables left. I made this function from points B and C. This function outputs the X value.
	*/
	return sqrt((-0.5-x)*(-0.5-x)+y*y)-sqrt(x*x+(1-y)*(1-y))-abs(b-c)*s;
}
double solvey(double x)
{
	/*
	this function is basically my equation for points A and B
	I was able to simplify it into a y= form. I output a y value
	for the x that is inputted.
	*/
	double k = a-b;
	return sqrt(  (4*x*x-4*x*pow(k*s,2)+pow(k*s,4))/(4*pow(k*s,2))-x*x+x-0.25);
}
int main()
{
	//Get values from user
	cout << "Enter times with only values.\ne.g. 0.000263474\n";
	cout << "Enter time for a: ";
	cin >> a;
	cout << "Enter time for b: ";
	cin >> b;
	cout << "Enter time for c: ";
	cin >> c;
	cout << "Enter max iteration value (In Meters): ";
	cin >> iter;
	
	//if statements choose which direction sound is coming from
	// and iterate in a loop in that direction
	if(a>b)
	{
		for(double x=0;x>-1*iter;x=x-0.005)
		{
			double v = (solvex(solvey(x),x));
			if(v<0.0001&&v>-0.0001)
			{
				// the closer v is to 0, the closer it is to intersecting
				// I chose -0.0001 and 0.0001 as how close it should be
				cout << x << " , "<< solvey(x)<<endl;
				break;
			}
		}
	}
	else
	{
		//same as above
		for(double x=0;x<iter;x=x+0.005)
		{
			double v = (solvex(solvey(x),x));
			if(v<0.0001&&v>-0.0001)
			{
				cout << x << " , "<< solvey(x)<<endl;
				break;
			}
		}
	}
	return 0;
}
