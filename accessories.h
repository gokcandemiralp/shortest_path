//het_gokcandemiralp 04-08-21
#ifndef __ACCESSORIES_H__
#define __ACCESSORIES_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

vector<Point> randomPoints(int low, int up, int n);

void printPoints(vector<Point> vec);

#endif
