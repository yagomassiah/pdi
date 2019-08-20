/**
 * \mainpage Página Principal 
 * Neste documento apresentaremos as classes utilizadas, funções e variáveis da primeira parte do projeto 1 da disciplina ECOI24,
 * que é a "Modelagem do objeto em OpenGL e leitura do arquivo XML".
 *  
 * \section Apresentação
 * Este trabalho foi realizado pelos alunos Felipe Amorim da Silveira Biazatti e Yago Lopes Siqueira Massiah,
 * como parte da nota 1 da disciplina ECOI24 do curso de Engenharia de Computação, ministrada pelo professor 
 * Giovanni Bernardes.
 * 
 * 
 * @file main.cpp
 * @author Felipe Amorim e Yago Massiah
 * @date August 20, 2019
 * @brief Função principal.
*/


#include <iostream>
#include <thread>
#include "tinyxml2.h"

#include "wraps.hpp"
#include "application.hpp"

     
/**
 * Programa Principal */
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
