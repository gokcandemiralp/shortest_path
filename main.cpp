//het_gokcandemiralp 09-08-21
#include "cpath.h"
#include "accessories.h"



int main() {

    vector<Point> vec = randomPoints(1, 15, 20);

    
    //cout << "\n"  << totalDistance(vec) << "\n";
    //printPoints(vec);


    // cout << "\n" << totalDistance(closest(vec)) << "\n";
    //printPoints(closest(vec));

    //cout << doesIntersect(Point(1, 6), Point(6, 6), Point(7, 7), Point(1, 1));

     Mat drawing;
     drawing = Mat::zeros(Size(1600, 900), CV_8UC3);


     michelangelo(drawing, closest(vec));
     imshow("image", drawing);
     waitKey(0);
}
