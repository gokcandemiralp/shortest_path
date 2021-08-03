//het_gokcandemiralp 03-08-21
#include "cpath.h"

void printPoints(vector<Point> vec) {
	for (vector<Point>::iterator i = vec.begin(); i != vec.end(); ++i) {
		cout << "["<< (*i).x << ","<< (*i).y << "]"<< " , ";
	}
}


vector<Point> closest(vector<Point> vec) {
	int smallest = INT_MAX;
	int temp;
	Point tempPoint;
	vector<Point>::iterator swapment;
	for (vector<Point>::iterator i = vec.begin(); i != vec.end() && (i + 1) != vec.end() ; ++i, smallest = INT_MAX) {
		for (vector<Point>::iterator j = i; j != vec.end() && (j + 1) != vec.end(); ++j) {
			vector<Point>::iterator a = i;
			vector<Point>::iterator b = (j + 1);
			temp = (((*a).x - (*b).x) * ((*a).x - (*b).x)) + (((*a).y - (*b).y) * ((*a).y - (*b).y));
			if (smallest > temp) { smallest = temp; swapment = b; }
		}
		if ((i + 1) != vec.end()) {
			tempPoint = *(i + 1);
			*(i + 1) = *swapment;
			*swapment = tempPoint;
		}
	}
	return vec;
}
