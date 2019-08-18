// Augmented reality
// Cube.cpp
// Prof. Giovani Bernardes Vitor
// ECOI24 - 2019


#include "Objects.hpp"

#ifndef __CUBE_HPP__
#define __CUBE_HPP__

/////////////////////////////////////////////////////////////
class Cube: public Objects
{
public:	
	Cube(double x, double y, double z, double aresta);
	~Cube();

	void draw();
	void update(int value);
	void colision(int x, int y);

private:

	int x,y,z;
	float theta;
	
	glm::vec3 points_base[24];
	glm::vec3 points[24];


private:

	void transform(void);
};

#endif
