//het_gokcandemiralp 10-08-21
#include "cpath.h"
#include "accessories.h"



int main() {

    vector<Point> vec = randomPoints(1, 18, 48);
    min_tree* agac = new min_tree(vec);
    agac->construct_tree();
    // agac->traverse_tree(agac->tree_vertices.begin());
    agac->optimal_path(*(agac->tree_vertices.begin()));
    cout << "\n" << "e" << "\n";

     Mat drawing;
     drawing = Mat::zeros(Size(1600, 900), CV_8UC3);

     michelangelo(drawing, agac->traverse_path);
     imshow("image", drawing);
     waitKey(0);
}
