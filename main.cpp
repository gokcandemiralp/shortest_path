//het_gokcandemiralp 04-08-21
#include "cpath.h"
#include "accessories.h"



int main() {

    vector<Point> vec = randomPoints(1, 11, 7);
    printPoints(closest(vec));
    return 0;
}
