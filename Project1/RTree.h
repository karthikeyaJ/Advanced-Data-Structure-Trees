#pragma once
#include "Interfaces04.h"
#include "Point.h"


class RTree:public IRTree
{
public:
	RTree() { max_xy = 0; dist = 0; }
	~RTree() {}
	void hilbertSort(std::vector<IPoint *>& points);
	void bulkInsert(std::vector<IPoint *>& points);
	std::vector<IPoint *> findWithin(IPoint * top_left, IPoint * bottom_right);
private:
	int max(int max_x, int max_y);
	int max_xy;
	int dist;
	void exchange(IPoint * &(f), IPoint * &(g));
	void topDown(std::vector<IPoint *>& points, int i, int endIndex);
	std::vector<IPoint *> p;


};