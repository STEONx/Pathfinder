#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "findway.h"

#include <algorithm>



	
//raster 1= start
// 2= unwalked place with price 1
// 3= no way
// 4= goal
// 5= walked

namespace find {
	
	bool sortbygoal(vector2d& A, vector2d& B) //function to sort fruits by price
	{
		return (A.goallengh < B.goallengh);
	}

	int find::vector2d::veclengh() {
		int l =sqrt( X * X + Y * Y);
		return l;


	}
	
	
	   
		inline bool find::less_than_key::operator() (const vector2d& struct1, const vector2d& struct2)
		{
			return (struct1.goallengh < struct2.goallengh);
		}
	
	
	
	
		

		find::Raster::Raster(int raster[20][20]) {
			vector2d m;
            this->raster[20][20] = raster[20][20];
			m.Y = 19;
			m.X = 19;
			goal = m;
			m.Y = 0;
			m.X = 0;
			player = m;

			
			
			



		}
		void find::Raster::vecpos() {
			vector2d m;

			int count = 0;
			for (int i = 0; i < 20; i++)
			{
				for (int v = 0; v < 20; v++)
				{
					if (raster[i][v] == 4) {
						m.X = i;
						m.Y = v;
						m.found = true;
						goal = m;

					}

				}

			}
			m.found = false;
			vector2d start;

			
			for (int i = 0; i < 20; i++)
			{
				for (int v = 0; v < 20; v++)
				{
					if (raster[i][v] == 1) {
						start.X = i;
						start.Y = v;
						start.found = true;
						player = start;

					}

				}

			}
			start.found = false;
			
		}/*bool doit = true;
			int index = 0;
			bool goalfound=false;
			if(!goalfound){
				while (doit)
				{

					vector2d nearestcordinatefound = nearestcordinate(index);
					vector2d nearestpossiblemove = bestwayo(nearestcordinatefound.X, nearestcordinatefound.Y);
					//std::cout << nearestcordinatefound.X << "kkkkkkkkk" << nearestcordinatefound.Y;

					if (nearestpossiblemove.found) {
						//place(nearestpossiblemove);
						if (nearestpossiblemove.X != goal.X && nearestpossiblemove.Y != goal.Y) {
							raster[nearestpossiblemove.X][nearestpossiblemove.Y] = 5;
							doit = false;


						}
						else
						{
							goalfound = true;

							raster[nearestpossiblemove.X][nearestpossiblemove.Y] = 6;

						}

					}

					index++;

				}

			}
			
			doit = true;*/
		
		
		int find::Raster::steps() {
			int count= 0;
			for (int l = 0; l < 20; l++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (raster[l][j] == 5) {
						count++;
					}

				}

			}
			return count;
		}
		void Raster::test() {
			raster[10][10] = 5;
			
		}

		void Raster::doonestep() {
			bool doit = true;
			int index = 0;
			bool place = true;
			vector2d nearestcordinatefound;
			vector2d nearestpossiblemove;
			while (doit)
			{
				
				nearestcordinatefound = nearestcordinate(index);
				x11 = nearestcordinatefound;
				nearestpossiblemove = bestwayo(nearestcordinatefound.X, nearestcordinatefound.Y);
				//std::cout << nearestcordinatefound.X << "kkkkkkkkk" << nearestcordinatefound.Y;
				;
				

				if (nearestpossiblemove.found) {
					if (nearestpossiblemove.X == goal.X && nearestpossiblemove.Y == goal.Y) {
						raster[nearestpossiblemove.X][nearestpossiblemove.Y] = 6;
						doit = false;
						place = false;
						
					}
					else
					{
						if (place) {
							raster[nearestpossiblemove.X][nearestpossiblemove.Y] = 5;
							doit = false;
						}
						
					}
					//place(nearestpossiblemove);
					

				}
				
				index++;

			}
			x11.X = nearestcordinatefound.X;
			x11.Y = nearestcordinatefound.Y;
			x22.X = nearestpossiblemove.X;
			x22.Y = nearestpossiblemove.Y;
			doit = true;
			vectorpixeltogoal(819, 88);

		}
		

		find::vector2d find::Raster::bestwayofalltime(int x, int y, int big) {
			std::vector<vector2d> list;
			std::vector<vector2d> bestlenghofalltime;
			//welche richtung die beste ist ob 1 nach oben doer uder unten
			for (int i = 0; i < 20; i++) {
				for (int v = 0; v < 20; v++) {
					vector2d f;
					if (raster[i][v] == 1) {
						f.X = i;
						f.Y = v;
						std::vector<vector2d> list;
						f.X = x;
						f.Y = y + 1;
						list.push_back(f);
						f.X = x;
						f.Y = y - 1;
						list.push_back(f);
						f.X = x - 1;
						f.Y = y;
						list.push_back(f);
						f.X = x + 1;
						f.Y = y;
						list.push_back(f);
						f.X = x + 1;
						f.Y = y + 1;
						list.push_back(f);
						f.X = x - 1;
						f.Y = y - 1;
						list.push_back(f);
						f.X = x - 1;
						f.Y = y + 1;
						list.push_back(f);
						f.X = x + 1;
						f.Y = y - 1;
						list.push_back(f);
						int count = 0;
						for (auto d : list) {
							
							
							d.X = goal.X - x;
							d.Y = goal.Y - y;
							float lengh = sqrt(d.X * d.X + d.Y * d.Y);
							if (count >= 4) {
								lengh += 1.4143;
							}
							else
							{
								lengh += 1;

							}
							d.goallengh = lengh;
							for (int i = 0; i < list.capacity(); i++)
							{
								if (raster[list[i].X][list[i].Y] != 3 || raster[list[i].X][list[i].Y] != 5) {
									
								}
								else
								{
									/// <summary>
									/// pfuschfffffffffffffffffffffffffffffffffff
									/// </summary>
									/// <param name="x"></param>
									/// <param name="y"></param>
									/// <returns></returns>
									list[i].goallengh = 132132000;

								}
							}


							count++;


						}
						std::sort(list.begin(), list.end(), less_than_key());
						if (list[0].goallengh != 132132000) {
							bestlenghofalltime.push_back(list[0]);

						}
						


					}





				}

			}
			
			std::sort(bestlenghofalltime.begin(), bestlenghofalltime.end(), less_than_key());
			return bestlenghofalltime[big];
			
			
			for (int i = 0; i < list.capacity(); i++)
			{
				if (raster[list[i].X][list[i].Y] != 3 || raster[list[i].X][list[i].Y] != 5) {
					list[i].found = true;
					return list[i];
				}
			} vector2d hh187819361;
			hh187819361.found = false;
			return hh187819361;

			for (auto d : list) {
				d.X = goal.X - x;
				d.Y =goal.Y- y;
				float lengh = sqrt(d.X * d.X + d.Y * d.Y);
				d.goallengh = lengh;
			}
			
			for (int i = 0; i < list.capacity(); i++)
			{
				if (raster[list[i].X][list[i].Y] != 3 || raster[list[i].X][list[i].Y] != 5) {
					list[i].found = true;
					return list[i];
				}
			} 
			vector2d heil;
			heil.found = false;
			return heil;


		}

		

		find::vector2d find::Raster::bestwayo(int x, int y) {
			std::vector<vector2d> list;
			vector2d f;
			vector2d ff;
			ff.X = x;
			ff.Y = y - 1;
			list.push_back(ff);
			f.X = x-1;
			f.Y = y;
			list.push_back(f);
			
			vector2d fff;
			fff.X = x;
			fff.Y = y+1;
			list.push_back(fff);
			vector2d ffff;
			ffff.X = x + 1;
			ffff.Y = y;
			list.push_back(ffff);
			vector2d p;
			p.X = x + 1;
			p.Y = y+1;
			list.push_back(p);
			vector2d pp;
			pp.X = x - 1;
			pp.Y = y - 1;
			list.push_back(pp);
			vector2d ppp;
			ppp.X = x - 1;
			ppp.Y = y + 1;
			list.push_back(ppp);
			vector2d pppp;
		    pppp.X = x + 1;
			pppp.Y = y - 1;
			list.push_back(pppp);
			for (int i = 0; i < 8; i++) {
				if(list[i].X>19||list[i].Y >19||list[i].X < 0 || list[i].Y <0)list.erase(list.begin() + i);
				

			}
		
			
			for (int i = 0; i < list.size(); i++) {
				float k = goal.X - list[i].X;
				float f = goal.Y - list[i].Y;
				float g = f * f + k * k;
				float lengh = sqrt(g);
				list[i].goallengh = lengh;

				std::cout << list[i].goallengh << std::endl;



			}
			
			
//raster 1= start
// 2= unwalked place with price 1
// 3= no way
// 4= goal
// 5= walked
			//std::sort(list.begin(), list.end(), less_than_key());
			
		
			for (int i = 0; i < 8; i++)
			{
				if (raster[list[i].X][list[i].Y] !=5&&raster[list[i].X][list[i].Y]!=3 && raster[list[i].X][list[i].Y] !=1 ) {
					list[i].found = true;
					
				
				}
				else
				{
					list[i].found = false;
				}

			} 
			
			
			//return list[3];
			
			
			sort(list.begin(), list.end(), [](const vector2d& x, const vector2d& y) {
				return x.goallengh < y.goallengh; });
			
			for(int i = 0; i < 8; i++)
			{
				if (list[i].found&& raster[list[i].X][list[i].Y]!=5) {
					 raster[list[i].X][list[i].Y]=7;
				}

			}
			for (int i = 0; i < 8; i++)
			{
				if (list[i].found) {
					return list[i];
				}

			}
			vector2d hh187819361;
			hh187819361.found = false;
			return hh187819361;


		}

		
		find::vector2d find::Raster::nearestcordinate(int big) {
			
			std::vector<vector2d> list;
			
			for(int i = 0; i < 20; i++) {
				for (int v = 0; v < 20; v++) {
					vector2d s;
					if (raster[i][v] == 5||raster[i][v] == 1) {
						s.X = i;
						s.Y = v;
						list.push_back(s);
						

					}





				}

			}	
			
			for (int i = 0; i < list.size(); i++) {
				float k = goal.X - list[i].X;
				float f = goal.Y - list[i].Y;
				float g = f * f + k * k;
				float lengh = sqrt(g);
				list[i].goallengh= lengh;
				
				std::cout << list[i].goallengh << std::endl;
				
				

			}
			sort(begin(list), end(list), [](const vector2d& a, const vector2d& b) { return a.goallengh < b.goallengh; });
			
			


			
			
		
			
			
		
			return list[big];
		}
		void find::Raster::vectorpixeltogoal(int x, int y) {
			std::vector<vector2d> list;
			for (int i = 0; i < 20; i++)
			{
				for (int v = 0; v < 20; v++)
				{
					if (raster[i][v] == 5|| raster[i][v] == 1) {
						
						vector2d f;
						vector2d ff;
						ff.X = i;
						ff.Y = v - 1;
						list.push_back(ff);
						f.X = i - 1;
						f.Y = v;
						list.push_back(f);

						vector2d fff;
						fff.X = i;
						fff.Y = v + 1;
						list.push_back(fff);
						vector2d ffff;
						ffff.X = i + 1;
						ffff.Y = v;
						list.push_back(ffff);
						vector2d p;
						p.X = i + 1;
						p.Y = v + 1;
						list.push_back(p);
						vector2d pp;
						pp.X = i - 1;
						pp.Y = v - 1;
						list.push_back(pp);
						vector2d ppp;
						ppp.X = i - 1;
						ppp.Y = v + 1;
						list.push_back(ppp);
						vector2d pppp;
						pppp.X = i + 1;
						pppp.Y = v - 1;
						list.push_back(pppp);
					}

				}

			}
			//raster 1= start
// 2= unwalked place with price 1
// 3= no way
// 4= goal
// 5= walked
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i].X <= 19 && list[i].Y >= 0 && list[i].Y <= 19 && list[i].X >= 0) {
					if (raster[list[i].X][list[i].Y] != 5 && raster[list[i].X][list[i].Y] != 4 && raster[list[i].X][list[i].Y] != 3 && raster[list[i].X][list[i].Y] != 1 && raster[list[i].X][list[i].Y] !=6) {
						raster[list[i].X][list[i].Y] = 7;
					}

				}
				

			}
			
		}
		find::vector2d find::Raster::vectortogoal() {
			vector2d s;
			s.X = goal.X - player.X;
			s.Y = goal.Y - player.Y;
			return s;
		}
		int find::Raster::getmap(int x , int y) {
			//muss noch verändert werden
			return 5;
		}
		
	




}