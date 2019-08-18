// Elo Maluco
// application.cpp
// Prof. Giovani Bernardes Vitor
// ECOI24 - 2019

#include <stdlib.h>
#include <stdio.h>
#include "application.hpp"
#include "cube.hpp"
#include "string.h"
#include "tinyxml2.h"
#include <cstring>
using namespace tinyxml2;
using namespace std;
#ifndef XMLCheckResult
	#define XMLCheckResult( a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

double rotate_y=0; 
double rotate_x=0;
string value= "oi";
string estados[4][4];
///////////////////////////////////////////////////////////////////////
// Application Class
Application::Application(int argc, char** argv)
{
	
	glutInit(&argc,argv);
     	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     	glutInitWindowSize(1280,720);
   	glutInitWindowPosition(100,100);
   	glutCreateWindow("ELO MALUCO");
	Inicializa();

	
}

//---------------------------------------------------------------------
Application::~Application()
{
}
//---------------------------------------------------------------------
void Application::Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    xf=50.0f;
    yf=50.0f;
    win=250.0f;
    time = 0;
    // XMLDocument xmlDoc;
    // XMLNode * pRoot = xmlDoc.NewElement("Root");
    // xmlDoc.InsertFirstChild(pRoot);
    // XMLElement * pElement = xmlDoc.NewElement("valor");
    // pElement->SetText(10);
    // pRoot->InsertEndChild(pElement);

    // XMLError eResult = xmlDoc.SaveFile("Teste.xml");
    
    XMLDocument doc;
    
    XMLError eResult2 = doc.LoadFile("./data/EloMaluco_estadoAtual_exemplo.xml");

    doc.Print();
    XMLElement * pElement = doc.FirstChildElement("EloMaluco") ->FirstChildElement("EstadoAtual");
    XMLElement * linhas = pElement->FirstChildElement("row");
    pElement = pElement->FirstChildElement("row")->FirstChildElement("col");
    cout << linhas->NextSiblingElement("row")->FirstChildElement("col")->GetText();
    value = pElement->GetText();
    
    //pRoot1 = doc.NextSibling();
//    doc.Print();
    //std::cout<<pRoot2;
    //MLNode * pNode = pRoot2->FirstChild();

  //  XML pElement2 = pElement2->FirstChildElement("row");
    // pElement2 = pElement2->FirstChildElement("col");
    //  const char * iOutInt;
    // iOutInt = pElement2->GetText();
    // value = iOutInt;

}


//---------------------------------------------------------------------
//void Application::DisplayFunc()
//{
//	glutDisplayFunc(Application::Desenha);
//}
//---------------------------------------------------------------------

void Application::draw()
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     

        glLineWidth(2.0f);

            glBegin(GL_LINES);
                glColor3f(1,0,0);
                glVertex3f(-15,0,0);
                glVertex3f(15,0,0);
            glEnd();
        glColor3f(0,1,0);
            glBegin(GL_LINES);
                glVertex3f(0,-15,0);
                glVertex3f(0,15,0);
            glEnd();
            glColor3f(0,0,1);
            glBegin(GL_LINES);
                glVertex3f(0,0,-15);
                glVertex3f(0,0,15);
            glEnd();

glPushMatrix();
        //glRotatef(rotate_x, 1.0, 0.0, 0.0);
        glRotatef(rotate_y, 0.0, 1.0, 0.0);

        Cube a = Cube(0, 0, 0, 6);
        a.draw();

glPopMatrix();

glPushMatrix();
         //glRotatef(rotate_x - 0.8, 1.0, 0.0, 0.0);
        glRotatef(rotate_y -0.8, 0.0, 1.0, 0.0);

         Cube b = Cube(0, 6, 0, 6);
        b.draw();
        glPopMatrix();
glPushMatrix();
       // glRotatef(rotate_x, 1.0, 0.0, 0.0);
        glRotatef(rotate_y, 0.0, 1.0, 0.0);
        Cube c = Cube(0, 12, 0, 6);
        if( value == "vms")
        c.draw();
    	glPopMatrix();


      for(list<Objects*>::const_iterator it = list_.begin(); it != list_.end(	) ;  ++it)
      {
    	   (*it)->draw();
      }

     
     glFlush();
     glutSwapBuffers();
}

//---------------------------------------------------------------------
void Application::resize(GLsizei w, GLsizei h)
{ 
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;                   

    // Inicializa o sistema de coordenadas
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluOrtho2D (-win, win, -win, win);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,(GLdouble)view_w/view_h,1,100);

    double rate=2.0;
    gluLookAt(rate*10,rate*14,rate*20,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);    
    glLoadIdentity() ;
}


//---------------------------------------------------------------------
void Application::KeyboardHandle(unsigned char key, int x, int y)
{
    switch (key) {
            case 'R': 
            case 'r':// muda a cor corrente para vermelho
                     glColor3f(1.0f, 0.0f, 0.0f);
                     break;
            case 'G':
            case 'g':// muda a cor corrente para verde
                     glColor3f(0.0f, 1.0f, 0.0f);
                     break;
            case 'B':
            case 'b':// muda a cor corrente para azul
                     glColor3f(0.0f, 0.0f, 1.0f);
			time++;
			for(list<Objects*>::const_iterator it = list_.begin(); it != list_.end(	) ;  ++it)
      			{
    	   			(*it)->update(time);
      			}
                     break;
	    case 27: // tecla Esc (encerra o programa)
		     exit(0);
		     break;
    }
    
}
        
//---------------------------------------------------------------------
void Application::MouseHandle(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
         if (state == GLUT_DOWN) {
                //   Troca o tamanho do retângulo, que vai do centro da 
                //   janela até a posição onde o usuário clicou com o mouse
                  xf = ( (2 * win * x) / view_w) - win;
                  yf = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
         }
    
}


//---------------------------------------------------------------------
void Application::SpecialKeyHandle(int key, int x, int y)
{
    if(key == GLUT_KEY_UP) {
         
           //win -= 20;
           //glMatrixMode(GL_PROJECTION);
           //glLoadIdentity();
           //gluOrtho2D (-win, win, -win, win);
	   //insert_object();
    }
    if(key == GLUT_KEY_DOWN) {
           win += 20;
           glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
           gluOrtho2D (-win, win, -win, win);
    }
    
}
//---------------------------------------------------------------------
void Application::update(int value, void (*func_ptr)(int))
{	
    rotate_y += 5;
    rotate_x += 5;
	glutPostRedisplay();
	glutTimerFunc(30,func_ptr,time);

}
//---------------------------------------------------------------------
bool Application::insert_object(void)
{
	Cube *obj;
	//Objects * node = reinterpret_cast<Objects*>(obj);
	list_.push_back(new Cube(10, 10 , 10, 3));
	std::cout << " insert: " << list_.size() << std::endl; 

	return true;
}

