//het_gokcandemiralp 04-08-21
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


void leftMostPoint(vector<Point>& vec);

vector<Point> closest(vector<Point> vec);


#endif
