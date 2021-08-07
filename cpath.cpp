//het_gokcandemiralp 07-08-21
#include "cpath.h"

bool onSegment(Point p, Point q, Point r){
	if (q.x < max(p.x, r.x) && q.x > min(p.x, r.x) &&
		q.y < max(p.y, r.y) && q.y > min(p.y, r.y))
		return true;

	return false;
}

int orientation(Point p, Point q, Point r){
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;

	return (val > 0) ? 1 : 2;
}

bool doesIntersect(Point p1, Point q1, Point p2, Point q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (p1 == p2 || p1 == q2 || q1 == p2 || q1 == q2) { ; }

	else if (o1 != o2 && o3 != o4)
		return true;


	return ((o1 == 0 && onSegment(p1, p2, q1)) ||

		    (o2 == 0 && onSegment(p1, q2, q1)) ||

		    (o3 == 0 && onSegment(p2, p1, q2)) ||

		    (o4 == 0 && onSegment(p2, q1, q2)));

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
		for (vector<Point>::iterator k = vec.begin() ; k != i ; ++k) {
			cout << "[" << (*k).x << " , "  << (*k).y << "]"
				 << "[" << (*(k + 1)).x << " , " << (*(k + 1)).y << "]"
				 << "[" << (*i).x << " , " << (*i).y << "]"
				 << "[" << (*swapment).x << " , " << (*swapment).y << "]   ";
		}
		cout << "\n";
		if ((i + 1) != vec.end()) {
			tempPoint = *(i + 1);
			*(i + 1) = *swapment;
			*swapment = tempPoint;
		}
	}
	return vec;
}
