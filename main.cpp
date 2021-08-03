//het_gokcandemiralp 03-08-21
#include "cpath.h"



int main() {

    vector<Point> vec = {Point(1,1),Point(3,4) ,Point(10,7) ,Point(5,5) ,Point(15,8) ,Point(2,2) };
    printPoints(closest(vec));
    return 0;
}