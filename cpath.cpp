//het_gokcandemiralp 17-08-21
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

bool distanceCompare(vector<Point> vec, int swapment, int n) {
	Point e, f, g, h;
	int ans1 = 0;
	int ans2 = 0;
	e = vec[swapment];
	f = vec[n];
	g = vec[(swapment + 1)];
	h = vec[(n-1)];

	ans1= ((((e.x - f.x) * (e.x - f.x)) + ((e.y - f.y) * (e.y - f.y))) + (((f.x - g.x) * (f.x - g.x)) + ((f.y - g.y) * (f.y - g.y))));
	ans2= ((((e.x - g.x) * (e.x - g.x)) + ((e.y - g.y) * (e.y - g.y))) + (((h.x - f.x) * (h.x - f.x)) + ((h.y - f.y) * (h.y - f.y))));

	return (ans1 < ans2);
}

void vecInsert(vector<Point>& vec, vector<Point>::iterator swapment, vector<Point>::iterator a) {
	Point tempPoint1, tempPoint2;
	tempPoint1 = *a;
	for (vector<Point>::iterator i = (swapment + 1); i != vec.end(); ++i) {
		tempPoint2 = *i;
		*i = tempPoint1;
		tempPoint1 = tempPoint2;
		if (i == a) { break; }
	}
}

void closestPoint(vector<Point>::iterator a, vector<Point>& vec) {
	int temp = 0;
	int smallest = INT_MAX;
	vector<Point>::iterator swapment;
	for (vector<Point>::iterator i = vec.begin(); i != a; ++i) {
		temp = (((*i).x - (*a).x) * ((*i).x - (*a).x)) + (((*i).y - (*a).y) * ((*i).y - (*a).y));
		if (smallest > temp) { smallest = temp; swapment = i; }
	}
	if((swapment + 1)!=a && distanceCompare(vec, (swapment-vec.begin()), (a - vec.begin()))){
		vecInsert(vec, swapment, a);
	}
}

vector<Point> closest(vector<Point> vec) {
	int smallest = INT_MAX;
	int temp;
	int size = vec.size();
	bool condition = false;
	Point tempPoint;
	vector<Point>::iterator swapment;
	leftMostPoint(vec);
	for (vector<Point>::iterator i = vec.begin(); i != vec.end() && (i + 1) != vec.end() ; ++i, smallest = INT_MAX, condition = false) {
		for (vector<Point>::iterator j = i; j != vec.end() && (j + 1) != vec.end(); ++j) {
			vector<Point>::iterator a = i;
			vector<Point>::iterator b = (j + 1);
			temp = (((*a).x - (*b).x) * ((*a).x - (*b).x)) + (((*a).y - (*b).y) * ((*a).y - (*b).y));
			if (smallest > temp) { smallest = temp; swapment = b; }
		}
		for (vector<Point>::iterator k = vec.begin() ; k != i ; ++k) {
			if (doesIntersect(*k, *(k + 1), *i, *swapment)) { condition = true; }
		}
		if ((i + 1) != vec.end()) {
			tempPoint = *(i + 1);
			*(i + 1) = *swapment;
			*swapment = tempPoint;
		}
		if (condition) {
			closestPoint((i+1), vec);
		}
	}
	return vec;
}

void michelangelo(Mat drawing, vector<Point> vec) {
	Point a = Point(0,0);
	for (vector<Point>::iterator i = vec.begin(); i!=vec.end() ; ++i) {
		Point b = (*i);
		line(drawing, Point(a.x * 50, a.y * 50), Point(b.x * 50, b.y * 50),Scalar(155, 155, 155),2, LINE_8);
		circle(drawing, Point(b.x * 50, b.y * 50), 5, Scalar(35, 35, 235), FILLED, LINE_8);
		a = b;
	}
}
