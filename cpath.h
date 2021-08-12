//het_gokcandemiralp 09-08-21
#ifndef __CPATH_H__
#define __CPATH_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

bool onSegment(Point p, Point q, Point r);

int orientation(Point p, Point q, Point r);

bool doesIntersect(Point A1, Point A2, Point B1, Point B2);

void leftMostPoint(vector<Point>& vec);

bool distanceCompare(vector<Point> vec, vector<Point>::iterator swapment, vector<Point>::iterator n);

void vecInsert(vector<Point>& vec, vector<Point>::iterator swapment, vector<Point>::iterator a);

void closestPoint(vector<Point>::iterator a, vector<Point>& vec);

vector<Point> closest(vector<Point> vec);

void michelangelo(Mat drawing, vector<Point> vec);

#endif
