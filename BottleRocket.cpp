//Jonathon Dowdy
//Homework1
//455
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ofstream myfile ("HomeWork1.txt");
	double Rho = 1.293;
	double time = 0;
	double height = 0;
	double velocity = 0;
	double acceleration = 0;
	double force = 0;
	double mass = 0.0340 + 0.0242;
	double thrustCurve[30] = { 0, 5, 14, 5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 4.4, 4.1, 4.3, 4.3, 4.3, 4.3, 4.3,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	double fdBody;
	double fdFins;
	double fg;
	double ft;
	double dv;
	double ds;
	double dt = 0.1;
	int count = 1;

	while (velocity >= 0||count==1) {
		if (count < 30) {
			ft = thrustCurve[count];
		}
		fdBody = 0.45*Rho*0.000506*(velocity*velocity) / 2;
		fdFins = 0.01*Rho*0.00496*(velocity*velocity) / 2;
		fg = mass *9.80665;
		force = ft - (fdBody + fdFins + fg);
		acceleration = force / mass;
		dv = acceleration*dt;
		velocity = velocity + dv;
		ds = velocity*dt;
		height = height + ds;
		if (ft > 0) {
			mass = mass - 0.0001644*ft;
		}

		time = time + dt;
		count++;
		cout << "Time: " << time << endl;
		cout << "height: " << height << endl;;
		cout << "Acceleration " << acceleration << endl;
		cout << "Force: " << force << endl;
		cout << "Velocity: " << velocity << endl;
		cout << "Mass: " << mass << endl;
		cout << endl << endl;

		myfile << "Time: " << time << endl;
		myfile << "height: " << height << endl;;
		myfile << "Acceleration " << acceleration << endl;
		myfile << "Force: " << force << endl;
		myfile << "Velocity: " << velocity << endl;
		myfile << "Mass: " << mass << endl;
		myfile << endl << endl;
	}
	myfile.close();
	//system("pause");
}
