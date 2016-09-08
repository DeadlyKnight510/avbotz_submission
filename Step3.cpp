#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>

int main(){

	std::string file;
	std::string line;
	std::string arr[3];

	int vals[3];
	int overHundred=0;
	std::ifstream myfile ("test.in");
	std::ofstream out;
	out.open ("test.out");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			int i =0;
			std::stringstream ssin(line);
			while (ssin.good() && i < 3){
				ssin >> arr[i];
				++i;
			}
			for(int x=0;x<3;x++)
			{
				std::stringstream convert(arr[x]);

				if (!(convert >> vals[x]))
					vals[x] = 0;
			}

			double dist = sqrt(pow(vals[0],2)+pow(vals[1],2)+pow(vals[2],2));
			out << (int) dist<<"\n";
			if((int) dist>200)
				overHundred++;
		}
		myfile.close();
	}
	out << overHundred<<"\n";
	out.close();
}
