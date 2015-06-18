#include "Interfaces04.h"
#include "RTree.h"
#include <iostream>
#include <math.h>       /* pow */
#include "vector.h"


void RTree::hilbertSort(std::vector<IPoint *>& points)
{
	

	int max_x = points[0]->getX();
	int max_y = points[0]->getY();
	for (int i = 0; i < points.size(); i++)
	{
		if (max_x < points[i]->getX())
			max_x = points[i]->getX();

	}
	for (int j = 0; j < points.size(); j++)
	{
		if (max_y < points[j]->getY())
			max_y = points[j]->getY();

	}
	 max_xy=max(max_x,max_y);


	 int quad;

	 int w = max_xy / 2;


	 for (int i = 0; i < points.size(); i++)
	 {
		 Point * (d) = static_cast<Point*>((points[i]));


		 int x_new = points[i]->getX();
		 int y_new = points[i]->getY();
		 int w = max_xy / 2;
		 dist = 0;


		 while (w != 0)
		 {

			 int temp = x_new;
			 int temp1 = y_new;
			 if ((x_new < w) && (y_new < w))
			 {
				 quad = 0;
				 dist += (quad*w*w);
				 x_new = temp1;
				 y_new = temp;
				 w = w / 2;
			 }

			 else if ((x_new < w) && (y_new >= w))
			 {
				 quad = 1;
				 dist += (quad*w*w);
				 x_new = x_new;
				 y_new = y_new - w;
				 w = w / 2;

			 }

			 else if ((x_new >= w) && (y_new >= w))
			 {
				 quad = 2;
				 dist += (quad*w*w);
				 x_new = x_new - w;
				 y_new = y_new - w;
				 w = w / 2;
			 }


			 else if ((x_new >= w) && (y_new < w))
			 {
				 quad = 3;
				 dist += (quad*w*w);
				 x_new = w - temp1 - 1;
				 y_new = (w * 2) - temp - 1;
				 w = w / 2;
			 }

			 else
			 {
				 d->setDist(0);
			 }

		 }
		 d->setDist(dist);

	 }







	 int vectorSize = points.size();
	 for (int i = vectorSize / 2 - 1; i >= 0; i--)
	 {

		 topDown(points, i, vectorSize - 1);
		 
	 }

	 int endIndex = vectorSize - 1;
	 while (endIndex > 0)
	 {
		 //Point * (a) = static_cast<Point*>((points[0]));
		 //Point * (b) = static_cast<Point*>((points[endIndex]));

		 exchange(points[0],points[endIndex]);
		 endIndex--;
		 topDown(points, 0, endIndex);
	 }
	 return;

	
		
}

int RTree::max(int max_x, int max_y)
{
	if (max_x < max_y)
		max_xy = max_y;
	else
		max_xy = max_y;

	for (int i = 0; i < 100000; i++)
	{
		int x = pow(2, i);
		int y = pow(2, i + 1);
		if (x == max_xy)
			return max_xy;
		else if (x < max_xy && max_xy < y)
			return y;

	}
}


void RTree::exchange(IPoint * &(f), IPoint * &(g))
{
	IPoint* tempElement = f;
	f = g;
	g = tempElement;
	return;
}

void RTree::topDown(std::vector<IPoint *>& points, int i, int endIndex)
{
		int largest = 2 * i + 1;
		


	while (largest <= endIndex) {
		Point * (e) = static_cast<Point*>((points[i]));

		Point * (f) = static_cast<Point*>((points[largest]));
		
		

		if (largest < endIndex) //&& 	f->getDist() < g->getDist())
		{
			Point * (g) = static_cast<Point*>((points[largest+1]));

			if (f->getDist() < g->getDist())
			{
				largest++;
				f = g;
			}
			
		}
		if (e->getDist() < f->getDist())
		{
			exchange(points[i], points[largest]);
			i = largest;
			largest = 2 * i + 1;
		}
		else largest = endIndex + 1;
	}
}




void RTree::bulkInsert(std::vector<IPoint *>& points)
{

	p = points;

		/*IPoint * kk = new (Point)();
		std::cout<<kk->getX();*/

}

std::vector<IPoint *> RTree::findWithin(IPoint * top_left, IPoint * bottom_right)
{
	std::vector<IPoint *> k;
	//return k;
	//p[0]->

	for (int j = 0; j < p.size(); j++)
	{
		if ((p[j]->getX() >= top_left->getX() && p[j]->getX() <= bottom_right->getX()) && (p[j]->getY() >= top_left->getY() && p[j]->getY() <= bottom_right->getY()))
		{
			k.push_back(p[j]);
		}

	}

	return k;
}