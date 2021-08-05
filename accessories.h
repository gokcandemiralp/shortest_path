//het_gokcandemiralp 05-08-21
#ifndef __ACCESSORIES_H__
#define __ACCESSORIES_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <math.h>


using namespace std;
using namespace cv;

float totalDistance(vector<Point> vec);

vector<Point> randomPoints(int low, int up, int n);

void printPoints(vector<Point> vec);

#endif
