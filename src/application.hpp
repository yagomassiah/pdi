/**
 * @file application.hpp
 * @author Felipe Amorim e Yago Massiah
 * @date August 20, 2019
 * @brief Cabeçalho da classe Application
*/

#include <iostream>
#include <vector>
#include <list>

#include <GL/glut.h>

#include "tinyxml2.h"
#include "Objects.hpp"
#include "triangle.hpp"

#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

using namespace std;

/////////////////////////////////////////////////////////////
class Application
{
public:
	Application(int argc, char** argv);
	~Application(void);

	void draw();
	void display();
	void resize(GLsizei w, GLsizei h);
	void KeyboardHandle(unsigned char key, int x, int y);
	void MouseHandle(int button, int state, int x, int y);
	void SpecialKeyHandle(int key, int x, int y);
	void update(int value, void (*func_ptr)(int));

	void Iluminacao(void); // Inicializa as configurações de luz

private:

	int time;
	

	GLfloat xf;
	GLfloat yf;
	GLfloat win;
	GLint view_w;
	GLint view_h;

	list<Objects*> list_;


	void Inicializa (void);
	bool insert_object(void);
	
};

#endif
