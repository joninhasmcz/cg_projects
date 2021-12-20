#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define SENO 0.86602540378
#define PI 3.14159265

float velocidade_angular = PI / 4;

typedef struct Vertices
{
    GLfloat x, y;

} Vertices;

Vertices base[] = {
    {-4.0, 0.0},
    {4.0, 0.0},
    {-4.0, -200.0},
    {4.0, -200.0}
};

Vertices pas[] = {
    {60.0f, SENO * 100},
    {-60.0f,  SENO * 100},
    {110.0f, 0.0f},
    {60.0, -SENO * 100},
    {-110.0f, 0.0f},
    {-60.0, -SENO * 100}
};


/* ATIVIDADE DO CATAVENTO CG

Aluno: Jonas Santos de Almeida Alves

PARA ROTACIONAR PARA ESQUERDA, PRESSIONE 'l'
PARA ROTACIONAR PARA DIREITA, PRESSIONE 'r'
PARA AUMENTAR A VELOCIDADE, PRESSIONE '+'
PARA DIMINUIR A VELOCIDADE, PRESSIONE '-'


*/
 


void velocidade_rotacao(int valor){

    float mudanca = velocidade_angular + valor * PI / 16;

    if (mudanca >= PI / 16 && mudanca <= PI)
        velocidade_angular = mudanca;    

}

void rotacionar(float angulo){
    
    Vertices anterior;

    for (int i = 0; i < 6; i = i + 2)
    {

        for (int j = i; j < i + 2; j++)
        {   anterior = pas[j];

            pas[j].x = anterior.x * cos(angulo) - anterior.y * sin(angulo);
            pas[j].y = anterior.y * cos(angulo) + anterior.x * sin(angulo); 
        }   
       
    }
    glutPostRedisplay();
}

void teclado(unsigned char key, int x, int y)
{

    if (key == 'l')
    {
        rotacionar(velocidade_angular);
    }

    if (key == 'r')
    {
        rotacionar(-velocidade_angular);
    }

    if (key == '+'){
        velocidade_rotacao(1);
    }

    if (key == '-'){
        velocidade_rotacao(-1);
    }
}

void catavento(){
    glClear(GL_COLOR_BUFFER_BIT);
        for (int i = 0; i < 6; i = i + 2)
    {

        glBegin(GL_TRIANGLES);
        glColor3d(1.0f, 1.0f, 0.0f); 
        // Center
        glVertex2f(0.0f,0.0f);

        for (int j = i; j < i + 2; j++)
        {   
            GLfloat x = pas[j].x;
            GLfloat y = pas[j].y;

            glVertex2f(x,y);             
                      
        }   
        glEnd();
       
    }

}

void base_func(){

    for (int i=0; i<2; i++){

        glBegin(GL_TRIANGLES);
        glColor3d(1.0, 1.0, 1.0);  

        for (int j=i; j < i + 3; j++){
        

        GLfloat x = base[j].x;
        GLfloat y = base[j].y;

        glVertex2i(x, y);
        }

        glEnd();
        
    }

}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    base_func();
    catavento();
    glutSwapBuffers();
    
}

void iniciar(void){
    glClearColor(0.0f, 0.0f, 1.0f,0.0f);
    glutReshapeWindow(600, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600, 600, -600, 600);
}




int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Catavento - Atividade CG");

    iniciar();

    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    glutMainLoop();

    return 0;
}