/**
 * @file application.cpp
 * @author Felipe Amorim e Yago Massiah
 * @date August 20, 2019
 * @brief Implementação da classe Application
 */

#include "application.hpp"
#include "cube.hpp"
#include "string.h"
#include "tinyxml2.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace tinyxml2;
using namespace std;
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult)                                              \
  if (a_eResult != XML_SUCCESS) {                                              \
    printf("Error: %i\n", a_eResult);                                          \
    return a_eResult;                                                          \
  }
#endif
double rotate_y = 0;
double rotate_yA = 0;
double rotate_yB = 0;
double rotate_x = 0;
string value = "oi";
string estados[4][4];
char tc = 'a';
char y = 'b';
Cube a = Cube(0, 0, 0, 6);
Cube b = Cube(0, 6, 0, 6);
Cube c = Cube(0, 12, 0, 6);
Cube d = Cube(0, 18, 0, 6);

///////////////////////////////////////////////////////////////////////
// Application Class
Application::Application(int argc, char **argv) {
  /**
   * Esta função inicializa a tela com o tamanho especificado.
   */

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1280, 720);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("ELO MALUCO");
  Inicializa();
}

//---------------------------------------------------------------------
Application::~Application() {}
//---------------------------------------------------------------------

//
void Application::Iluminacao(void) {
  // Light values and coordinates
  GLfloat whiteLight[] = {0.45f, 0.45f, 0.45f, 1.0f};
  GLfloat sourceLight[] = {0.25f, 0.25f, 0.25f, 1.0f};
  GLfloat lightPos[] = {-50.f, 25.0f, 250.0f, 0.0f};

  glEnable(GL_DEPTH_TEST); // Hidden surface removal
  glFrontFace(GL_CCW);     // Counter clock-wise polygons face out

  // Enable lighting
  glEnable(GL_LIGHTING);

  // Setup and enable light 0
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
  glLightfv(GL_LIGHT0, GL_AMBIENT, sourceLight);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLight);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
  glEnable(GL_LIGHT0);

  // Enable color tracking
  glEnable(GL_COLOR_MATERIAL);

  // Set Material properties to follow glColor values
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}
//

// TAG = Teste
void Application::Inicializa(void) {
  Iluminacao();

  /** Define a cor de fundo da janela de visualização como preta*/
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  xf = 50.0f;
  yf = 50.0f;
  win = 250.0f;
  time = 0;
  // XMLDocument xmlDoc;
  // XMLNode * pRoot = xmlDoc.NewElement("Root");
  // xmlDoc.InsertFirstChild(pRoot);
  // XMLElement * pElement = xmlDoc.NewElement("valor");
  // pElement->SetText(10);
  // pRoot->InsertEndChild(pElement);

  // XMLError eResult = xmlDoc.SaveFile("Teste.xml");

  // pRoot1 = doc.NextSibling();
  //    doc.Print();
  // std::cout<<pRoot2;
  // MLNode * pNode = pRoot2->FirstChild();

  //  XML pElement2 = pElement2->FirstChildElement("row");
  // pElement2 = pElement2->FirstChildElement("col");
  //  const char * iOutInt;
  // iOutInt = pElement2->GetText();
  // value = iOutInt;
}

//---------------------------------------------------------------------
// void Application::DisplayFunc()
//{
//	glutDisplayFunc(Application::Desenha);
//}
//---------------------------------------------------------------------
void Application::display() { glutSwapBuffers(); }

/**
 * Neste método são desenhados a maior parte dos objetos
 * bem como o eixo de referência.
 */
void Application::draw() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLineWidth(2.0f);
  glBegin(GL_LINES);
  glColor3f(1, 0, 0);
  glVertex3f(-15, 0, 0);
  glVertex3f(15, 0, 0);
  glEnd();
  glColor3f(0, 1, 0);
  glBegin(GL_LINES);
  glVertex3f(0, -15, 0);
  glVertex3f(0, 15, 0);
  glEnd();
  glColor3f(0, 0, 1);
  glBegin(GL_LINES);
  glVertex3f(0, 0, -15);
  glVertex3f(0, 0, 15);
  glEnd();

  glPushMatrix();
  glRotatef(rotate_yA, 0.0, 1.0, 0.0);

  a.draw();
  glPopMatrix();

  glPushMatrix();
  glRotatef(rotate_yB, 0.0, 1.0, 0.0);

  b.draw();
  glPopMatrix();

  // b.draw();
  c.draw();
  // a.rotateRight();
  // glPopMatrix();

  // if (tc == 'a') {
  //   glPushMatrix();
  //   b.draw();
  //   c.draw();
  //   glPopMatrix();
  //   glPushMatrix();
  //   glRotatef(rotate_x, 1.0, 0.0, 0.0);
  //   glRotatef(rotate_y, 0.0, 1.0, 0.0);
  //   a.draw();
  //   glPopMatrix();
  //   // a.rotateRight();
  // }
  // if (tc == 'b') {
  //   glPushMatrix();
  //   c.draw();
  //   a.draw();
  //   glPopMatrix();
  //   glPushMatrix();
  //   glRotatef(rotate_x, 1.0, 0.0, 0.0);
  //   glRotatef(rotate_y, 0.0, 1.0, 0.0);
  //   b.draw();
  //   glPopMatrix();
  // }
  // if (tc == 'c') {
  //   glPushMatrix();
  //   b.draw();
  //   a.draw();
  //   glPopMatrix();
  //   glPushMatrix();
  //   // glRotatef(rotate_x, 1.0, 0.0, 0.0);
  //   glRotatef(rotate_y, 0.0, 1.0, 0.0);
  //   c.draw();
  //   glPopMatrix();
  // }
  // glPopMatrix();

  // glFlush();
  glutSwapBuffers();
}

//---------------------------------------------------------------------
void Application::resize(GLsizei w, GLsizei h) {
  // Especifica as dimensões da Viewport
  glViewport(0, 0, w, h);
  view_w = w;
  view_h = h;

  // Inicializa o sistema de coordenadas
  // glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  // gluOrtho2D(-win, win, -win, win);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (GLdouble)view_w / view_h, 1, 100);

  double rate = 2.5;
  gluLookAt(rate * 10, rate * 8, rate * 7, 0, 0, 0, 0, 1, 0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

//---------------------------------------------------------------------
void Application::KeyboardHandle(unsigned char key, int x, int y) {
  switch (key) {
  case 'R':
  case 'r': // muda a cor corrente para vermelho
    glColor3f(1.0f, 0.0f, 0.0f);
    break;
  case 'q':
    glPushMatrix();
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glPopMatrix();
    break;
  case 'G':
  case 'g': // muda a cor corrente para verde
    glColor3f(0.0f, 1.0f, 0.0f);
    break;
  case 'B':
  case 'b': // muda a cor corrente para azul
    glColor3f(0.0f, 0.0f, 1.0f);
    break;

    time++;
    for (list<Objects *>::const_iterator it = list_.begin(); it != list_.end();
         ++it) {
      (*it)->update(time);
    }
    break;
  case 27: // tecla Esc (encerra o programa)
    exit(0);
    break;
  }
}

//---------------------------------------------------------------------
void Application::MouseHandle(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN) {

      //   Troca o tamanho do retângulo, que vai do centro da
      //   janela até a posição onde o usuário clicou com o mouse
      xf = ((2 * win * x) / view_w) - win;
      yf = (((2 * win) * (y - view_h)) / -view_h) - win;
    }
}

//---------------------------------------------------------------------
void Application::SpecialKeyHandle(int key, int x, int y) {
  if (key == GLUT_KEY_UP) {
    // a.rotateRight();
    // this->draw();
    // //a.draw();
    // this->draw();
    // a.rotateRight();
    // this->draw();
    cout << "SOMETHING";
    if (tc == 'a') {
      for (int i = 0; i < 90; i += 2) {
        rotate_yA += 2;
        this->draw();
      }
    }
    if (tc == 'b') {
      for (int i = 0; i < 90; i += 2) {
        rotate_yB += 2;
        this->draw();
      }
    }
    // win -= 20;
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // gluOrtho2D (-win, win, -win, win);
    // insert_object();
  }
  if (key == GLUT_KEY_DOWN) {
    switch (tc) {
    case 'a':
      tc = 'b';
      break;
    case 'b':
      tc = 'c';
      break;
    case 'c':
      tc = 'a';
      break;
    }
    // glutPostRedisplay();
    //    win += 20;
    //    glMatrixMode(GL_PROJECTION);
    //    glLoadIdentity();
    //    gluOrtho2D (-win, win, -win, win);
  }
}
//---------------------------------------------------------------------
/**
 * Neste método atualizamos as variáveis de rotação
 * "x" e "y" utilizando o a função OpenGL "glutTimerFunc()"
 */
void Application::update(int value, void (*func_ptr)(int)) {
  // rotate_y += 5;
  // rotate_x += 5;
  // glutPostRedisplay();
  glutTimerFunc(30, func_ptr, time);
}
//---------------------------------------------------------------------
bool Application::insert_object(void) {
  Cube *obj;
  // Objects * node = reinterpret_cast<Objects*>(obj);
  list_.push_back(new Cube(10, 10, 10, 3));
  std::cout << " insert: " << list_.size() << std::endl;

  return true;
}
