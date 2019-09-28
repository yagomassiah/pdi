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

	double fixo = aresta / 2;
	//lado z fixo -
	points_base[0] = glm::vec3(xita - fixo, yita - fixo, zeta - fixo);
	points_base[1] = glm::vec3(xita + fixo, yita - fixo, zeta - fixo);
	points_base[2] = glm::vec3(xita + fixo, yita + fixo, zeta - fixo);
	points_base[3] = glm::vec3(xita - fixo, yita + fixo, zeta - fixo);

	//lado z fixo +
	points_base[4] = glm::vec3(xita - fixo, yita - fixo, zeta + fixo);
	points_base[5] = glm::vec3(xita + fixo, yita - fixo, zeta + fixo);
	points_base[6] = glm::vec3(xita + fixo, yita + fixo, zeta + fixo);
	points_base[7] = glm::vec3(xita - fixo, yita + fixo, zeta + fixo);

	//lado y fixo -
	points_base[8] = glm::vec3(xita - fixo, yita - fixo, zeta - fixo);
	points_base[9] = glm::vec3(xita + fixo, yita - fixo, zeta - fixo);
	points_base[10] = glm::vec3(xita + fixo, yita - fixo, zeta + fixo);
	points_base[11] = glm::vec3(xita - fixo, yita - fixo, zeta + fixo);

	//lado y fixo -
	points_base[12] = glm::vec3(xita - fixo, yita + fixo, zeta - fixo);
	points_base[13] = glm::vec3(xita + fixo, yita + fixo, zeta - fixo);
	points_base[14] = glm::vec3(xita + fixo, yita + fixo, zeta + fixo);
	points_base[15] = glm::vec3(xita - fixo, yita + fixo, zeta + fixo);

	//lado x fixo -
	points_base[16] = glm::vec3(xita - fixo, yita - fixo, zeta - fixo);
	points_base[17] = glm::vec3(xita - fixo, yita + fixo, zeta - fixo);
	points_base[18] = glm::vec3(xita - fixo, yita + fixo, zeta + fixo);
	points_base[19] = glm::vec3(xita - fixo, yita - fixo, zeta + fixo);

	//lado x fixo +
	points_base[20] = glm::vec3(xita + fixo, yita - fixo, zeta - fixo);
	points_base[21] = glm::vec3(xita + fixo, yita + fixo, zeta - fixo);
	points_base[22] = glm::vec3(xita + fixo, yita + fixo, zeta + fixo);
	points_base[23] = glm::vec3(xita + fixo, yita - fixo, zeta + fixo);

	// points_base[1] = glm::vec3( 15.0f,  0.0f , 1.0f);
	// points_base[2] = glm::vec3( 0.0f,  30.0f , 1.0f) ;

	for (int i = 0; i < 24; i++)
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

	for (int i = 0; i < 4; i++)
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
	for (int i = 0; i < 23; i)
	{

		glBegin(GL_POLYGON);
		if (i < 4)
			glColor3f(0.0, 1.0, 0.3);
		else if (i < 8)
			glColor3f(1.0, 0.0, 0.8);
		else if (i < 12)
			glColor3f(0.0f, 0.0f, 1.0f);
		else if (i < 16)
			glColor3f(1.0, 0.0, 0.0);
		else if (i < 20)
			glColor3f(1.0, 0.7, 0.0);
		else if (i < 24)
			glColor3f(0.5, 0.5, 0.0);

		glVertex3f(points[i].x, points[i].y, points[i].z);
		i++;
		glVertex3f(points[i].x, points[i].y, points[i].z);
		i++;
		glVertex3f(points[i].x, points[i].y, points[i].z);
		i++;
		glVertex3f(points[i].x, points[i].y, points[i].z);
		i++;

		glEnd();
	}
}

///
/// A matriz xml foi adicionada ao objeto contendo as cores e a ordem. Ela é instanciada durante a leitura do arquivo
///
void Cube::readXml()
{
	tinyxml2::XMLDocument doc;
	xml[4][4];

	// Path completo. Path local estava gerando erro
	bool eResult = doc.LoadFile("../data/EloMaluco_estadoAtual_exemplo.xml");

	if (!eResult)
	{
		tinyxml2::XMLElement *row = doc.FirstChildElement("EloMaluco")->FirstChildElement("EstadoAtual")->FirstChildElement("row");
		tinyxml2::XMLElement *col = row->FirstChildElement("col");

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				xml[i][j] = col->GetText();
				col = col->NextSiblingElement();
			}
			if (i != 3)
			{
				row = row->NextSiblingElement();
				col = row->FirstChildElement("col");
			}
		}
	}
}

///
/// Método para interpretar o xml
///
void Cube::parseXml()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (xml[i][j] == "vzo")
			{
				blank[0][0] = i;
				blank[0][1] = j;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (xml[i][j].substr(0, 2) == "vm")
				cores[i][j] = glm::vec3(1.0, 0.0, 0.0); // Vermelho
			else if (xml[i][j].substr(0, 2) == "vd")
				cores[i][j] = glm::vec3(0.0, 1.0, 0.0); // Verde
			else if (xml[i][j].substr(0, 2) == "am")
				cores[i][j] = glm::vec3(1.0, 1.0, 0.0); // Amarelo
			else if (xml[i][j].substr(0, 2) == "br")
				cores[i][j] = glm::vec3(1.0, 1.0, 1.0); // Branco
			else if (xml[i][j].substr(0, 3) == "vzo")
				cores[i][j] = glm::vec3(0.5, 0.5, 0.5); // Cinza (vazio)

			posicao[i][j] = xml[i][j].substr(2, 4);

			cout << "(" << cores[i][j].x << "," << cores[i][j].y << "," << cores[i][j].z << ") ";
			// cout << posicao[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}