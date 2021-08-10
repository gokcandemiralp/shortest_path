//het_gokcandemiralp 10-08-21
#include "cpath.h"
#include "accessories.h"



int main() {

    vector<Point> vec = randomPoints(1, 17, 34);

    
    cout << "\n"  << totalDistance(vec) << "\n";
    //printPoints(vec);


    //cout << "\n" << totalDistance(closest(vec)) << "\n";
    //printPoints(closest(vec));


     Mat drawing;
     drawing = Mat::zeros(Size(1600, 900), CV_8UC3);


     michelangelo(drawing, closest(vec));
     imshow("image", drawing);
     waitKey(0);
}
