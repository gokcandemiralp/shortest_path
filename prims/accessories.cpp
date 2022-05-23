//het_gokcandemiralp 10-08-21
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
	Point temp_point;
	for (int i = 0;i<n;++i) {
		temp_point = Point(((rand() % (up - low) + low) * 1.8), (rand() % (up - low) + low));
		while (std::find(vec.begin(), vec.end(), temp_point) != vec.end()) {
			temp_point = Point(((rand() % (up - low) + low) * 1.8), (rand() % (up - low) + low));
		}
		vec.push_back(temp_point);
	}
	return vec;
}

void printPoints(vector<Point> vec) {
	for (vector<Point>::iterator i = vec.begin(); i != vec.end(); ++i) {
		cout << "[" << (*i).x << "," << (*i).y << "]" << " , ";
	}
}

