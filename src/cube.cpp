/**
 * @file cube.cpp
 * @author Felipe Amorim e Yago Massiah
 * @date August 20, 2019
 * @brief Este arquivo implementa a classe Cube possibilitando
 * utilizar programação orientada à objeto para manipular nossos
 * modelos.
 */

#include <stdlib.h>
#include <stdio.h>
#include "cube.hpp"

/**
 * No construtor da classe pedimos o centro de massa de cada cubo
 * e o tamanho da aresta do cubo para então calcularmos as posições
 * de cada vértice do cubo.
 */
Cube::Cube(double xita, double yita, double zeta, double aresta)
{
	x = y = z = 0;
	theta = 0.0f;

	double fixo = aresta/2;
	//lado z fixo - 
	points_base[0] = glm::vec3( xita - fixo,   yita - fixo , zeta - fixo);
	points_base[1] = glm::vec3( xita + fixo ,   yita- fixo , zeta - fixo);
	points_base[2] = glm::vec3( xita + fixo ,   yita + fixo , zeta - fixo);
	points_base[3] = glm::vec3( xita - fixo ,   yita + fixo , zeta - fixo);

	//lado z fixo + 
	points_base[4] = glm::vec3( xita - fixo,   yita - fixo , zeta + fixo);
	points_base[5] = glm::vec3( xita + fixo ,   yita- fixo , zeta + fixo);
	points_base[6] = glm::vec3( xita + fixo ,   yita + fixo , zeta + fixo);
	points_base[7] = glm::vec3( xita - fixo ,   yita + fixo , zeta + fixo);


//lado y fixo - 
	points_base[8] = glm::vec3( xita - fixo,   yita - fixo , zeta - fixo);
	points_base[9] = glm::vec3( xita + fixo ,   yita - fixo , zeta - fixo);
	points_base[10] = glm::vec3( xita + fixo ,   yita - fixo , zeta + fixo);
	points_base[11] = glm::vec3( xita - fixo ,   yita - fixo , zeta + fixo);


	//lado y fixo - 
	points_base[12] = glm::vec3( xita - fixo,   yita + fixo , zeta - fixo);
	points_base[13] = glm::vec3( xita + fixo ,   yita + fixo , zeta - fixo);
	points_base[14] = glm::vec3( xita + fixo ,   yita + fixo , zeta + fixo);
	points_base[15] = glm::vec3( xita - fixo ,   yita + fixo , zeta + fixo);

	
	

	//lado x fixo - 
	points_base[16] = glm::vec3( xita - fixo,   yita - fixo , zeta - fixo);
	points_base[17] = glm::vec3( xita - fixo ,   yita + fixo , zeta - fixo);
	points_base[18] = glm::vec3( xita - fixo ,   yita + fixo , zeta + fixo);
	points_base[19] = glm::vec3( xita - fixo ,   yita - fixo , zeta + fixo);


	//lado x fixo + 
	points_base[20] = glm::vec3( xita + fixo,   yita - fixo , zeta - fixo);
	points_base[21] = glm::vec3( xita + fixo ,   yita + fixo , zeta - fixo);
	points_base[22] = glm::vec3( xita + fixo ,   yita + fixo , zeta + fixo);
	points_base[23] = glm::vec3( xita + fixo ,   yita - fixo , zeta + fixo);
	
	
	// points_base[1] = glm::vec3( 15.0f,  0.0f , 1.0f);
    // points_base[2] = glm::vec3( 0.0f,  30.0f , 1.0f) ;      

	for( int i = 0; i < 24; i++)
	points[i] = points_base[i];

	
}
//---------------------------------------------------------------------
Cube::~Cube()
{

}

//---------------------------------------------------------------------
void Cube::update(int value)
{
	x += value;
	y += value;

	transform();
}

//---------------------------------------------------------------------
void Cube::colision(int x, int y)
{

	

}

//---------------------------------------------------------------------
void Cube::transform(void)
{

	//glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
        glm::mat3 Model = glm::mat3(1.0);
        Model[2] = glm::vec3(x, y, 1.0);
	

	//std::cout << "tes: " << glm::to_string(Model[0]) << std::endl;
	//std::cout << "tes: " << glm::to_string(Model[1])<< std::endl;
	//std::cout << "tes: " << glm::to_string(Model[2])<< "\n" << std::endl;
	
        //glm::vec4 Transformed = Model * Position;


	for(int i=0; i < 4; i++)
	{
		points[i] = Model * points_base[i];

	}

}



//---------------------------------------------------------------------
/**
 * Neste método utilizamos os vértices já calculados no construtor
 * para finalmente desenharmos nosso cubo. Também alteramos
 * a cor de cada lado a cada 4 iterações.
 */

void Cube::draw()
{

	

	glLineWidth(3.0f);
	//glColor3f(0.5f, 0.6f, 0.4f);
	glColor3f(0.0, 1.0, 0.3);
	for (int i = 0; i < 23 ;i){
		
		 glBegin(GL_POLYGON);  
		if(i < 4)
		 glColor3f(0.0, 1.0, 0.3);
		 else if(i < 8)
		  glColor3f(1.0, 0.0, 0.8);
		  else if ( i < 12)
		   glColor3f(0.0f, 0.0f, 1.0f);
		   else if (i < 16)
		   glColor3f(1.0, 0.0, 0.0);
		   else if ( i < 20)
		    glColor3f(1.0, 0.7, 0.0);
			else if ( i < 24)
			 glColor3f(0.5, 0.5, 0.0);
		   

		glVertex3f(points[i].x,points[i].y, points[i].z);
		i++;
	    glVertex3f(points[i].x,points[i].y, points[i].z);
		i++;
		glVertex3f(points[i].x,points[i].y, points[i].z);
		i++;
		glVertex3f(points[i].x,points[i].y, points[i].z);
		i++;
        
		glEnd();

		}
        

}
