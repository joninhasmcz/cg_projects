#include <GL/glut.h>

static GLfloat v[10]={
        0,  2,
        0,  2,
        0,  2,
        0,  2,
        0,  2
};

void teclado(unsigned char key, int x, int y){
    switch (key) {
        case 'q':
            v[0] += 2;
            v[1] += 2;
            break;
        case 'w':
            v[2] += 2;
            v[3] += 2;
            v[0] -= 2;
            v[1] -= 2;
            break;
        case 'e':
            v[4] += 2;
            v[5] += 2;
            v[2] -= 2;
            v[3] -= 2;
            break;
        case 'r':
            v[6] += 2;
            v[7] += 2;
            v[4] -= 2;
            v[5] -= 2;
            break;
        case 't':
            v[8] += 2;
            v[9] += 2;
            v[6] -= 2;
            v[7] -= 2;
            break;
        case 'a':
           v[0] += 2;
            v[1] += 2;
            v[8] -= 2;
            v[9] -= 2;
            break;
      
    }
}

// O movimento dos quadrados baseados em vértices no teclado é feito por Q + clique na aba que está sendo executado o executavel do projeto.
// q + clique, w + clique, e + clique, r + clique, a + clique para repetir o processo.

void displayQ()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3, v[0], 0); 
    glVertex3f(2, v[0], 0);
    glVertex3f(2,v[1], 0);
    glVertex3f(3, v[1], 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(1, v[2], 0);
    glVertex3f(0, v[2], 0);
    glVertex3f(0,v[3], 0);
    glVertex3f(1, v[3], 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1, v[4], 0);
    glVertex3f(-2, v[4], 0);
    glVertex3f(-2,v[5], 0);
    glVertex3f(-1, v[5], 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.0, 0.8);
    glVertex3f(-3, v[6], 0);
    glVertex3f(-4, v[6], 0);
    glVertex3f(-4,v[7], 0);
    glVertex3f(-3, v[7], 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2, 1, 0.2);
    glVertex3f(-5, v[8], 0);
    glVertex3f(-6, v[8], 0);
    glVertex3f(-6,v[9], 0);
    glVertex3f(-5, v[9], 0);
    glEnd();

    glFlush();
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("Projeto 1 CG - OLA");

    glClearColor(0.0, 0.05, 0.10, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, -1.0);

    glutDisplayFunc(displayQ);
    glutKeyboardFunc(teclado);
    glutMainLoop();

    return 0;
}