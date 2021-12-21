#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_PLANETAS 8
#define PI 3.14159265

typedef struct Planeta
{
  GLfloat r, g, b;
  GLfloat raio, planeta_raio, angulo, tamanho;
  GLfloat x_velocidade, y_velocidade, z_velocidade;

} planeta;

typedef struct Nomes
{
  char *nome;
} nomes;


nomes nomes_planetas[] =  { {"Sol"}, {"Venus"}, {"Jupiter"}, {"Terra"}, {"Mercurio"},
  {"Urano"}, {"Lua 1"}, {"Lua 2"} };



planeta planetas[N_PLANETAS] = {{1.0, 0.5, 0.0,0.7f, 0.0f, 0.0f, 0.0f, 0.0f,0.0f,-8.0f},
                   {1.0, 85/255.0, 85/255.0,0.1f, 1.1f, 0.0f, 0.05f, 0.0f,1.1f,-8.0f},
                   {139/255.0, 233/255.0, 253/255.0,0.15f, 1.5f, 0.0f, 0.03f, 0.0f,1.5f,-8.0f},
                    {0.25, 0.25, 1.0 ,0.25f, 2.2f, 0.0f, 0.02f, 0.0f,2.2f,-8.0f},
                   {1.0, 0.0, 1.0,0.2f, 2.8f, 0.0f, 0.045f, 0.0f,2.8f,-8.0f},
                    {0.5, 1.0, 0.0, 0.07f, 3.2f, 0.0f, 0.01f,  0.0,3.2f,-8.0f},
                   {189.0/255.0, 147.0/255.0, 249.0/255.0,0.05f, 0.45f, 0.0f, 0.05f, 0.0f,1.75f, -8.0f},
                   {189.0/255.0, 147.0/255.0, 249.0/255.0,0.03f, 0.3f, 0.0f, 0.05f, 0.0f,2.20f, -7.5f}};



/* ATIVIDADE DO SISTEMA SOLAR - CG

Aluno: Jonas Santos de Almeida Alves

PARA ROTACIONAR, PRESSIONE 'y'


*/



void nomes_planetas_func()
{
  for (int i = 0; i < N_PLANETAS; i++)
    {
      glColor3f (255 / 255.0, 248 / 255.0, 242 / 255.0);
      glRasterPos3f (planetas[i].x_velocidade + planetas[i].raio * 0.7,
		     planetas[i].y_velocidade + planetas[i].raio * 0.7, -7.7f);


      int len = (int) strlen (nomes_planetas[i].nome);

      for (int j = 0; j < len; j++)
	{
	  glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12,
			       nomes_planetas[i].nome[j]);
	}
    }

  glutPostRedisplay ();

}

void movimentacao(int value)
{


  for (int i = 1; i < N_PLANETAS; i++)
    {
      if (planetas[i].angulo + planetas[i].tamanho < 2)
	{

	  if (i == 6)
	    {
	      planetas[i].x_velocidade = planetas[3].x_velocidade;
	      planetas[i].y_velocidade =
		planetas[3].y_velocidade -
		cos (planetas[i].angulo * PI) * planetas[i].planeta_raio;
	      planetas[i].z_velocidade =
		sin (planetas[i].angulo * PI) * planetas[i].planeta_raio - 8.0;

	    }
	  else if (i == 7)
	    {
	      planetas[i].x_velocidade =
		planetas[3].x_velocidade -
		sin (planetas[i].angulo * PI) * planetas[i].planeta_raio;
	      planetas[i].y_velocidade =
		planetas[3].y_velocidade -
		sin (planetas[i].angulo * PI) * planetas[i].planeta_raio;
	      planetas[i].z_velocidade =
		cos (planetas[i].angulo * PI) * planetas[i].planeta_raio - 7.7;

	    }
	  else
	    {
	      planetas[i].x_velocidade =
		sin (planetas[i].angulo * PI) * planetas[i].planeta_raio;

	      planetas[i].y_velocidade =
		cos (planetas[i].angulo * PI) * planetas[i].planeta_raio;
	    }

	  planetas[i].angulo += planetas[i].tamanho;
	}
      else
	planetas[i].angulo = 0;
    }


  glutPostRedisplay ();
}


void desenho_estrelas(void){


  for (int i = 0; i < 150; i++)
    {
      glBegin (GL_POINTS);
      float x = 20.0 * (rand()/ ((double)RAND_MAX + 1)) - 10;
      float y = 20.0 * (rand()/ ((double)RAND_MAX + 1)) - 10;

      glColor3d (248.0 / 255.0, 248.0 / 255.0, 242.0 / 255.0);

      glVertex3f(x, y, -7.7f);

      glEnd ();
    }

}


void desenho_circulo (void)
{
  for (int j = 1; j < N_PLANETAS - 2; j++)
    {
      glBegin (GL_LINE_LOOP);

      glColor3d (248 / 255.0, 248 / 255.0, 242 / 255.0);

      for (int i = 0; i <= 100; i++)
	{
	  glVertex3f ((planetas[j].planeta_raio * cos (i * 2.0f * PI / 100)),
		      (planetas[j].planeta_raio * sin (i * 2.0f * PI / 100)),
		      -8.0f);
	}

      glEnd ();
    }
}

void desenho_sistema(void)
{

  for (int i = 0; i < N_PLANETAS; i++)
    {

      glPushMatrix ();

      glTranslatef (planetas[i].x_velocidade, planetas[i].y_velocidade,
		    planetas[i].z_velocidade);
      glColor3f (planetas[i].r, planetas[i].g, planetas[i].b);

      glScalef (1.0, 1.0, 1.0);

      glutSolidSphere (planetas[i].raio, 20, 20);

      glPopMatrix ();

    }

}

void mudanca(int x, int y)
{
  if (y == 0 || x == 0)
    return;

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective (45, (GLdouble) x / (GLdouble) y, 0.6, 21.0);
  glMatrixMode (GL_MODELVIEW);
  glViewport (0, 0, x, y);
  glClearColor (45.0 / 255.0, 45.0 / 255.0, 54.0 / 255.0, 1.0);

}

void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  desenho_circulo();
  desenho_sistema();
  nomes_planetas_func();
  desenho_estrelas();
  glutSwapBuffers();
}

void teclado (unsigned char key, int x, int y)
{

  if (key == 'y')
    movimentacao(1);

}




int main (int argc, char **argv)
{
  glutInit (&argc, argv);
  glutInitWindowSize (1400, 1200);
  glutCreateWindow ("Projeto 1 CG - Sistema Solar");
  glutInitDisplayMode (GLUT_DEPTH);
  glEnable (GL_DEPTH_TEST);
  glMatrixMode (GL_MODELVIEW);
  glClear (GL_COLOR_BUFFER_BIT);
  glLoadIdentity ();

  glutDisplayFunc (display);
  glutReshapeFunc (mudanca);
  glutKeyboardFunc (teclado);
  glutMainLoop ();
  return 0;
}