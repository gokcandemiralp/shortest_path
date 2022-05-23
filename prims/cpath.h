//het_gokcandemiralp 09-08-21
#ifndef __CPATH_H__
#define __CPATH_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

class vertex{

    public:
        vertex(int x, int y);
        void addEdge(vertex*);
        vector<vertex*> g_adjacency_vec;
        vector<vertex*> t_adjacency_vec;
        vertex* parent;
        int X;
        int Y;
        int isTree;
        int maxDepth;
};

class min_tree {
public:
    min_tree(vector<Point> vec);
    void construct_tree();
    void traverse_tree(vertex*);
    void optimal_path(vertex*);
    vertex* shortest_branch(vertex*);
    int set_depth(vertex*);

    int t_size = 0;
    vector<vertex*> all_vertices;
    vector<vertex*> tree_vertices;
    vector<Point> traverse_path;
    vector<vertex*>::iterator tree_find(vertex*, vertex*);
};

vertex* pop_closest_vertex(vector<vertex*>& temp_vec, vertex* temp_point);

void upperLeftPoint(vector<Point>& );

void michelangelo(Mat drawing, vector<Point> vec);

#endif
