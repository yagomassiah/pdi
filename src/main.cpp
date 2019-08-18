// Elo Maluco
// main.cpp
// Prof. Giovani Bernardes Vitor
// ECOI24 - 2019



#include <iostream>
#include <thread>
#include "tinyxml2.h"

#include "wraps.hpp"
#include "application.hpp"

     
// Programa Principal 
int main(int argc, char** argv)
{
     int time=0;

     Application app(argc,argv);
     ptr_ = &app;

     glEnable(GL_DEPTH_TEST);
     glutDisplayFunc(draw);
     glutReshapeFunc(resize);
     glutKeyboardFunc(KeyboardHandle);
     glutMouseFunc(MouseHandle);
     glutSpecialFunc(SpecialKeyHandle); 
     glutTimerFunc(30,update,time);
     glutMainLoop();

     return 0;
}
