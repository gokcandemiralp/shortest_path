//het_gokcandemiralp 09-08-21
#include "accessories.h"

float totalDistance(vector<Point> vec){
	Point b;
	Point a = Point(0, 0);
	float ans = 0;
	for (vector<Point>::iterator i = vec.begin(); i != vec.end(); ++i) {
		b = *i;
		ans += sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
		a = b;
	}
	return ans;
}

vector<Point> randomPoints(int low,int up,int n) {
	vector<Point> vec;
	for (int i = 0;i<n;++i) {
		vec.push_back(Point((rand() % (up - low) + low), (rand() % (up - low) + low)));
	}
	for (int i = 0; i < n; ++i) { // eliminates same points
		for (int j = 0; j < n; ++j) {
			if ( i!=j && vec[i] == vec[j] ) { 
				++(vec[i].x); 
				++(vec[i].y);
				j = 0;
			}
		}
	}
	return vec;
}

void printPoints(vector<Point> vec) {
	for (vector<Point>::iterator i = vec.begin(); i != vec.end(); ++i) {
		cout << "[" << (*i).x << "," << (*i).y << "]" << " , ";
	}
}

