#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#include "ft2build.h"
#include FT_FREETYPE_H

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

#define PI acos(-1.0)

FT_Library  library;




str_box str={7.0*WINDOW_WIDTH/8.0,0,WINDOW_WIDTH/8.0,WINDOW_HEIGHT/7.0,"EXIT"};

Button button={7.0*WINDOW_WIDTH/8.0-20.0, 0, strlen("EXIT")* 24,strlen("EXIT")* 15};

void initGlut(int argc, char **argv);
void Display();
void MyInit();
void Mouse(int Button, int State, int X, int Y);
void reshape(int winWidth, int winHeight);
void RegisterCallbacks();
void print_bitmap_string( char* s);
void initGl();



void initGlut(int argc, char **argv){
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(WINDOW_X_OFFSET, WINDOW_Y_OFFSET);
	glutInit(&argc, argv);
	glutCreateWindow("maman 11");
}

void Display(){

	int min;

	float step = 0.01;

	float ang;

	float s_w,s_h;

	float s_x, s_y;

	float b_w, b_h, b_y;

	char *string;

	string = str.str;


	s_x = str.x;
	s_y = str.y;

	s_w = str.box_w;
	s_h = str.box_h;


	b_w = button.w;
	b_h = button.h;
	b_y = button.y;





	glClear(GL_COLOR_BUFFER_BIT);
	/*code for grass*/
	glViewport(0.0,0.0, Width, Height/3.0);
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_QUADS);
			glVertex2f(1.0f,1.0f);
			glVertex2f(-1.0f,1.0f);
			glVertex2f(-1.0f,-1.0f);
			glVertex2f(1.0f,-1.0f);
	glEnd();

	/*code for sky*/
	glViewport(0.0,Height/3.0, Width, 2*Height/3.0);
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_QUADS);
			glVertex2f(1.0f,1.0f);
			glVertex2f(-1.0f,1.0f);
			glVertex2f(-1.0f,-1.0f);
			glVertex2f(1.0f,-1.0f);
	glEnd();

	/*code for house*/

	glViewport(Width/3.0,Height/3.0, Width/5.0, Height/3.0);
	glColor3f(0.647059f, 0.164706f, 0.164706f);
	glBegin(GL_QUADS);
			glVertex2f(1.0f,1.0f);
			glVertex2f(-1.0f,1.0f);
			glVertex2f(-1.0f,-1.0f);
			glVertex2f(1.0f,-1.0f);
	glEnd();

	/*code for roof*/
	glViewport(Width/3.5,2*Height/3.0, Width/3.0, Height/5.0);
	glColor3f(1.0f,0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
			glVertex2f(-1.0f,-1.0f);
			glVertex2f(1.0f,-1.0f);
			glVertex2f(0.0f,0.0f);
	glEnd();

	/*code for sun*/


	if (Width<Height){
		min = Width;
	}
	else{
		min = Height;
	}

	glViewport(3*Width/4.0,3*Height/4.0, min/4.0, min/4.0);
	glColor3f(1.0f,1.0f, 0.0f);
	glBegin(GL_POLYGON);
	for (ang=-1; ang<=1; ang = ang+step){
		glVertex2f(0.55*cos(ang*PI), 0.5*sin(ang*PI));


	}
	glEnd();
	glBegin(GL_LINES);
	step=0.1;
	for (ang=-1; ang<=1; ang = ang+step){
		glVertex2f(0.5*cos(ang*PI), 0.5*sin(ang*PI));
		glVertex2f(cos(ang*PI), sin(ang*PI));


		}


	glEnd();



	/*code for exit button*/

	glViewport(s_x-20.0, b_y, b_w, b_h);
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
	print_bitmap_string(string);


	glFlush();
}

void MyInit(){
	glClearColor(1.0f, 1.0f, 1.0f,0.0f);

}

void Mouse(int Button, int State, int X, int Y){
	Y = Height - Y;
	if (Button ==GLUT_LEFT_BUTTON && State == GLUT_DOWN
			&& button.x<=X&&X<=button.x+button.w
				&&button.y<=Y&&Y<=button.y+button.h){
		exit(EXIT_SUCCESS);

	}

	glFlush();
}

void reshape(int winWidth, int winHeight){
	Width = winWidth;
	Height = winHeight;

	str.x = 7.0*Width/8.0;
	str.y = 0;
	str.box_w = Width/8.0;
	str.box_h = Height/7.0;

	button.x = str.x -20.0;
	button.y = 0;
	button.w = strlen(str.str)*24;
	button.h = strlen(str.str)*15;


}

void RegisterCallbacks(){
	glutDisplayFunc(Display);
	glutReshapeFunc(reshape);
	glutMouseFunc(Mouse);
}


void print_bitmap_string( char* s)
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









int main(int argc, char **argv)
{
	int error = FT_Init_FreeType( &library );
	if (error)
	{
	}


	initGlut(argc, argv);
	MyInit();
	initGl();
	RegisterCallbacks();
	glutMainLoop();


   return 0;
}
