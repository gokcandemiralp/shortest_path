//het_gokcandemiralp 04-08-21
#include "accessories.h"

vector<Point> randomPoints(int low,int up,int n) {
	vector<Point> vec;
	for (int i = 0;i<n;++i) {
		vec.push_back(Point((rand() % (up - low) + low), (rand() % (up - low) + low)));
	}
	return vec;
}

void printPoints(vector<Point> vec) {
	for (vector<Point>::iterator i = vec.begin(); i != vec.end(); ++i) {
		cout << "[" << (*i).x << "," << (*i).y << "]" << " , ";
	}
}

