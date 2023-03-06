#pragma once


#include <iostream>
#include "findway.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#include <vector>
#include "findway.h"
#include <math.h>

#include <algorithm>



namespace find {

	class vector2d
	{
	public:
		
		
		int X, Y;
		float goallengh;
		bool found;
		int veclengh(); 

		

	private:

	};
	struct less_than_key
	{
		bool operator() (const vector2d& struct1, const vector2d& struct2);

	};
	class Raster
	{
	public:
		int raster[20][20];
		vector2d player;
		vector2d goal;
		vector2d postry;
		vector2d x22;
		vector2d x11;
		
		Raster(int raster[20][20]);
		
		int steps();
		void doonestep();
		void vecpos();
		void test();
		
		
		vector2d bestwayofalltime(int x, int y, int big);
		vector2d bestwayo(int x, int y);
		vector2d nearestcordinate(int big);
		void vectorpixeltogoal(int x, int y);
		vector2d vectortogoal();
		int getmap(int x, int y);

	private:

	};








}
