/**
 * @file cube.hpp
 * @author Felipe Amorim e Yago Massiah
 * @date August 20, 2019
 * @brief Cabeçalho da classe Cube
*/



#include "Objects.hpp"
#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

#ifndef __CUBE_HPP__
#define __CUBE_HPP__

using namespace std;

/////////////////////////////////////////////////////////////
class Cube: public Objects
{
public:	
	Cube(double x, double y, double z, double aresta);
	~Cube();

	void draw();
	void update(int value);
	void colision(int x, int y);
	void readXml();
	void parseXml();

private:

	int x,y,z;
	float theta;
	
	glm::vec3 points_base[24];
	glm::vec3 points[24];
	string xml[4][4];
    glm::vec3 cores[4][4];
	string posicao[4][4];
    int blank[1][2];

	void transform(void);
};

#endif
