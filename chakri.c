#include<GL/glut.h>
#include<stdlib.h>
float xpos=0;
float r,g,b;
void idle()
{
	if (xpos<=360)
	{
		r=(rand()%9/8);
		g=(rand()%9/8);
		b=(rand()%9/8);
		xpos+=1;
	}
	else
	{
		xpos=xpos-360;
	}
	glutPostRedisplay();
}

void display(void)
{
	int i;
glClearColor(1,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
//glMatrixMode(GL_PROJECTION);
//glLoadIdentity();
//gluOrtho2D(-150.0, 150.0, -150.0, 150.0);
glPushMatrix();
glColor3f(r,g,b);
//glTranslatef(xpos,xpos,0);
glScalef(2,1.5,1);
glRotatef(xpos,0,0,0);
glutWireCube(0.2);
glPopMatrix();
glutSwapBuffers();
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(10, 10);
glutCreateWindow("Animation Transform");
glutDisplayFunc(display);
glutIdleFunc(idle);
glutMainLoop();
}

//Output of all is attached in video form.


