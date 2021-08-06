//het_gokcandemiralp 06-08-21
#include "cpath.h"

bool doesIntersect(Point A1, Point A2, Point B1, Point B2) {
	int AX1, AX2, BX1, BX2, AY1, AY2, BY1, BY2;
	(A1.x < A2.x) ? (AX1 = A1.x, AX2 = A2.x) : (AX1 = A2.x, AX2 = A1.x); //normalizing the input
	(B1.x < B2.x) ? (BX1 = B1.x, BX2 = B2.x) : (BX1 = B2.x, BX2 = B1.x);
	(A1.y < A2.y) ? (AY1 = A1.y, AY2 = A2.y) : (AY1 = A2.y, AY2 = A1.y);
	(B1.y < B2.y) ? (BY1 = B1.y, BY2 = B2.y) : (BY1 = B2.y, BY2 = B1.y);
	return (AX1 <= BX2 && BX1 <= AX2 && AY1 <= BY2 && BY1 <= AY2);
}

void leftMostPoint(vector<Point> &vec) {
	int temp = 0;
	int smallest = INT_MAX;
	vector<Point>::iterator swapment;
	Point tempPoint;
	for (vector<Point>::iterator i = vec.begin(); i != vec.end(); ++i) {
		temp = (((*i).x) * ((*i).x)) + (((*i).y) * ((*i).y));
		if(smallest > temp) { smallest = temp; swapment = i; }
	}
	tempPoint = *(vec.begin());
	*(vec.begin()) = *swapment;
	*swapment = tempPoint;
}


vector<Point> closest(vector<Point> vec) {
	int smallest = INT_MAX;
	int temp;
	int size = vec.size();
	Point tempPoint;
	vector<Point>::iterator swapment;
	leftMostPoint(vec);
	for (vector<Point>::iterator i = vec.begin(); i != vec.end() && (i + 1) != vec.end() ; ++i, smallest = INT_MAX) {
		for (vector<Point>::iterator j = i; j != vec.end() && (j + 1) != vec.end(); ++j) {
			vector<Point>::iterator a = i;
			vector<Point>::iterator b = (j + 1);
			temp = (((*a).x - (*b).x) * ((*a).x - (*b).x)) + (((*a).y - (*b).y) * ((*a).y - (*b).y));
			if (smallest > temp) { smallest = temp; swapment = b; }
		}
		for (vector<Point>::iterator k = vec.begin() ; k != i && size > 1 &&i != (vec.begin()+1); ++k) {
			cout << doesIntersect(*k, *(k + 1), *i, *swapment);
		}
		if ((i + 1) != vec.end()) {
			tempPoint = *(i + 1);
			*(i + 1) = *swapment;
			*swapment = tempPoint;
		}
	}
	return vec;
}
