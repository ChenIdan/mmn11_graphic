#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glut.h>

#include "header.h"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

#define WINDOW_X_OFFSET 100
#define WINDOW_Y_OFFSET 100

/*global variables tracking window height and width*/
int Height = WINDOW_HEIGHT;
int Width = WINDOW_WIDTH;

str_box str={4.0*WINDOW_WIDTH/5.0,WINDOW_HEIGHT/10.0,WINDOW_WIDTH/7.0,WINDOW_HEIGHT/7.0,"EXIT"};

Button button={4.0*WINDOW_WIDTH/5.0-20.0, WINDOW_HEIGHT/10.0 -20.0, strlen("EXIT")* 24,strlen("EXIT")* 15};



static int font_index=0;

void initGlut(int argc, char **argv){
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(WINDOW_X_OFFSET, WINDOW_Y_OFFSET);
	glutInit(&argc, argv);
	glutCreateWindow("maman 11");
}

void Display(){
	int len;

	float s_w,s_h;

	float s_x, s_y;

	float b_x, b_y, b_w, b_h;

	char *string;

	string = str.str;


	s_x = str.x;
	s_y = str.y;

	s_w = str.box_w;
	s_h = str.box_h;

	b_x = button.x;
	b_y = button.y;

	b_w = button.w;
	b_h = button.h;





	glClear(GL_COLOR_BUFFER_BIT);

	/*code for exit button*/

	glViewport(s_x-20.0, s_y-20.0, b_w, b_h);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);
		glVertex2f(1.0f,1.0f);
		glVertex2f(-1.0f,1.0f);
		glVertex2f(-1.0f,-1.0f);
		glVertex2f(1.0f,-1.0f);
	glEnd();
	glViewport(s_x, s_y, s_w, s_h);
	glColor4f(0.0, 0.0, 0.0, 0.0);
	glRasterPos2f(-1.0f,-1.0f);
	print_bitmap_string("EXIT");



	glFlush();
}

void MyInit(){
	glClearColor(1.0f, 1.0f, 1.0f,0.0f);

}

void Mouse(int Button, int State, int X, int Y){
	printf("mouse clicked\n");
	Y = Height - Y;
	if (Button ==GLUT_LEFT_BUTTON && State == GLUT_DOWN
			&& button.x<=X&&X<=button.x+button.w&&button.y<=Y&&Y<=button.y+button.h){
		printf("in button\n");
		exit(EXIT_SUCCESS);

	}

	glFlush();
}

void reshape(int winWidth, int winHeight){
	Width = winWidth;
	Height = winHeight;

	str.x = 4.0*Width/5.0;
	str.y = Height/10.0;
	str.box_w = Width/7.0;
	str.box_h = Height/7.0;

	button.x = str.x -20.0;
	button.y = str.y -20.0;
	button.w = strlen(str.str)*24;
	button.h = strlen(str.str)*15;


}

void RegisterCallbacks(){
	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutMouseFunc(Mouse);
}


void print_bitmap_string(/*void* font,*/ char* s)
{

      while (*s) {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *s);
         s++;
      }
  
}

void initGl(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
}



void my_reshape(int w, int h)
{
   GLdouble size;
   GLdouble aspect;

   /* Use the whole window. */
   glViewport(0, 0, w, h);

   /* We are going to do some 2-D orthographic drawing. */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   size = (GLdouble)((w >= h) ? w : h) / 2.0;
   if (w <= h) {
      aspect = (GLdouble)h/(GLdouble)w;
      glOrtho(-size, size, -size*aspect, size*aspect, -100000.0, 100000.0);
   }
   else {
      aspect = (GLdouble)w/(GLdouble)h;
      glOrtho(-size*aspect, size*aspect, -size, size, -100000.0, 100000.0);
   }

   /* Make the world and window coordinates coincide so that 1.0 in */
   /* model space equals one pixel in window space.                 */
   glScaled(aspect, aspect, 1.0);

   /* Now determine where to draw things. */
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

}


void draw_stuff()
{
   char* bitmap_font_names[7] = {"This is my firs text"};

   GLfloat x, y, ystep, yild, stroke_scale;

   /* Draw the strings, according to the current mode and font. */
   glTranslatef(0.5,-1.0,0);
   glColor4f(1.0, 1.0, 0.0, 0.0);
   x = -225.0;
   y = 70.0;
   ystep  = 100.0;
   yild   = 20.0;
      glRasterPos2f(-150, y+1.25*yild);
     print_bitmap_string(bitmap_font_names[0]);
}



void my_display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   draw_stuff();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.5,1.0);

        glVertex3f(0.5f, 0.0f, -4.0f);
        glVertex3f(1.0f, 0.5f, -4.0f);
        glVertex3f(0.5f, 0.5f, -4.0f);

   glEnd();

   glutSwapBuffers();
}

int main(int argc, char **argv)
{
	initGlut(argc, argv);
	MyInit();
	initGl();
	RegisterCallbacks();
	glutMainLoop();

   /*glutInitWindowSize(500, 250);
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
   glutCreateWindow("GLUT fonts");
   glutDisplayFunc(my_display);
   glutReshapeFunc(my_reshape);
   glutMainLoop();*/

   return 0;
}
