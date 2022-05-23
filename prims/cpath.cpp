//het_gokcandemiralp 17-08-21
#include "cpath.h"

vertex::vertex(int x, int y) {
	X = x;
	Y = y;
	isTree = 0;
	maxDepth = 0;
	parent = NULL;
};

void vertex::addEdge(vertex* neighbour) {
	g_adjacency_vec.push_back(neighbour);
}

vertex *pop_closest_vertex(vector<vertex*> &temp_vec, vertex *temp_vertex) {
	int closest_distance = INT_MAX;
	int distance = INT_MAX;
	int temp_x = temp_vertex->X;
	int temp_y = temp_vertex->Y;
	vector<vertex*>::iterator ans_itr;
	vertex *ans_vertex;
	for (vector<vertex*>::iterator i = temp_vec.begin(); i != temp_vec.end(); ++i) {
		if((*i)!= temp_vertex){
			distance = ((*i)->X - temp_x)*((*i)->X - temp_x) + ((*i)->Y - temp_y)*((*i)->Y - temp_y);
			if (distance < closest_distance) { 
				closest_distance = distance; 
				ans_itr = i;
			}
		}
	}
	ans_vertex = *ans_itr;
	temp_vec.erase(ans_itr);
	return ans_vertex;
}

min_tree::min_tree(vector<Point> coord_vec) {
	upperLeftPoint(coord_vec);
	for (vector<Point>::iterator i = coord_vec.begin(); i != coord_vec.end(); ++i) {
		vertex* temp_vertex = new vertex((*i).x, (*i).y);
		all_vertices.push_back(temp_vertex);
	}
	for (vector<vertex*>::iterator i = all_vertices.begin(); i != all_vertices.end(); ++i) {
		vector<vertex*> temp_vec = all_vertices;
		while (temp_vec.size() > 1) {
			(*i)->addEdge(pop_closest_vertex(temp_vec, (*i)));
		}
	}
}

void min_tree::construct_tree(){
	if (all_vertices.begin() != all_vertices.end()) {
		int closest_distance = INT_MAX;
		int distance = INT_MAX;
		int size = all_vertices.size();
		vector<vertex*>::iterator new_vertex_itr;
		vertex* branch_vertex = NULL;
		tree_vertices.push_back(*all_vertices.begin());
		++t_size;
		(*all_vertices.begin())->isTree = 1;

		for (vector<vertex*>::iterator j = tree_vertices.begin(); tree_vertices.size() < size ;) {
			for (vector<vertex*>::iterator k = (*j)->g_adjacency_vec.begin(); k != (*j)->g_adjacency_vec.end(); ++k) {
				if (!(*k)->isTree) {
					distance = ((*j)->X - (*k)->X) * ((*j)->X - (*k)->X) + ((*j)->Y - (*k)->Y) * ((*j)->Y - (*k)->Y);
					if (distance < closest_distance) {
						closest_distance = distance;
						branch_vertex = (*j);
						new_vertex_itr = k;
					}
					break;
				}
			}
			++j;
			if (j == tree_vertices.end()) {
				tree_vertices.push_back(*new_vertex_itr);
				branch_vertex->t_adjacency_vec.push_back(*new_vertex_itr);
				(*new_vertex_itr)->parent= branch_vertex;
				(*new_vertex_itr)->isTree = 1;
				++t_size;

				j = tree_vertices.begin();
				closest_distance = INT_MAX;
				distance = INT_MAX;
			}
		}
		set_depth(*(this->tree_vertices.begin()));
	}
}

void min_tree::traverse_tree(vertex* root){
	if (t_size > 0) {
		if (root->isTree != 2) {
			--t_size;
			traverse_path.push_back(Point(root->X, root->Y));
			root->isTree = 2;
		}

		if (root->t_adjacency_vec.size() != 0) {
			traverse_tree(shortest_branch(root));
		}
		else {
			vertex* parente = root->parent;
			vector<vertex*>::iterator root_itr = tree_find(parente, root);
			(parente->t_adjacency_vec).erase(root_itr);
			traverse_path.push_back(Point(parente->X, parente->Y)); // if omitted gives the optimal path
			traverse_tree(parente);
		}
	}
}

void min_tree::optimal_path(vertex* root) {
	if(t_size > 0){
		if (root->isTree != 2) {
			--t_size;
			traverse_path.push_back(Point(root->X, root->Y));
			root->isTree = 2;
		}

		if (root->t_adjacency_vec.size() != 0) {
			optimal_path(shortest_branch(root));
		}
		else {
			vertex* parente = root->parent;
			vector<vertex*>::iterator root_itr = tree_find(parente, root);
			(parente->t_adjacency_vec).erase(root_itr);
			optimal_path(parente);
		}
	}
}

vertex* min_tree::shortest_branch(vertex* root) {
	int shortest_distance = INT_MAX;
	int distance = INT_MAX;
	vertex* ans = NULL;
	for (vector<vertex*>::iterator i = root->t_adjacency_vec.begin(); i != root->t_adjacency_vec.end(); ++i) {
		distance = (*i)->maxDepth;
		if (distance < shortest_distance) {
			shortest_distance = distance;
			ans = (*i);
		}
	}
	return ans;
}

int min_tree::set_depth(vertex* root) {
	int distance = 0;
	int max_distance = 0;
	for (vector<vertex*>::iterator i = root->t_adjacency_vec.begin(); i != root->t_adjacency_vec.end(); ++i) {
		distance = set_depth(*i);
		if (max_distance < distance) {
			max_distance = distance;
		}
	}
	vertex* parente = root->parent;
	if (parente) {
		distance = (root->X - parente->X) * (root->X - parente->X) + (root->Y - parente->Y) * (root->Y - parente->Y);
		root->maxDepth = distance + max_distance;
	}
	return root->maxDepth;
}

vector<vertex*>::iterator min_tree::tree_find(vertex* grandparent, vertex* searche) {
	for (vector<vertex*>::iterator i = grandparent->t_adjacency_vec.begin(); i != grandparent->t_adjacency_vec.end(); ++i) {
		if ((*i) == searche) { return i; }
	}
}

void upperLeftPoint(vector<Point> &coord_vec) {
	int closest_distance = INT_MAX;
	int distance = INT_MAX;
	vector<Point>::iterator leftMostItr;
	Point tempPoint;
	for (vector<Point>::iterator i = coord_vec.begin(); i != coord_vec.end(); ++i) {
		distance = ((*i).x) * ((*i).x) + ((*i).y) * ((*i).y);
		if (distance < closest_distance) {
			closest_distance = distance;
			leftMostItr = i;
		}
	}
	tempPoint = *coord_vec.begin();
	*coord_vec.begin() = *(leftMostItr);
	*(leftMostItr) = tempPoint;
}

void michelangelo(Mat drawing, vector<Point> vec) {
	Point a = Point(0,0);
	std::string string_x;
	std::string string_y;
	int red = 0;
	int red_increment = 255/vec.size();
	for (vector<Point>::iterator i = vec.begin(); i!=vec.end() ; ++i) {
		Point b = (*i);
		red += red_increment;
		line(drawing, Point(a.x * 50, a.y * 50), Point(b.x * 50, b.y * 50),Scalar(155, 155, red),2, LINE_8);
		circle(drawing, Point(b.x * 50, b.y * 50), 5, Scalar(35, 35, 235), FILLED, LINE_8);
		string_x = std::to_string(b.x);
		string_y = std::to_string(b.y);
		string coordinates = " ( " + string_x + " , " + string_y + " ) ";
		putText(drawing, coordinates, Point(b.x * 50, b.y * 50), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(255, 150, 150), 1, LINE_8);
		a = b;
	}
}
