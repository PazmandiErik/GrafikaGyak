#include "init.h"

#include <GL/glut.h>

GLint cubeList = 1;

float scp[18][3] = {
  {1.000000, 0.000000, 0.000000},
  {1.000000, 0.000000, 5.000000},
  {0.707107, 0.707107, 0.000000},
  {0.707107, 0.707107, 5.000000},
  {0.000000, 1.000000, 0.000000},
  {0.000000, 1.000000, 5.000000},
  {-0.707107, 0.707107, 0.000000},
  {-0.707107, 0.707107, 5.000000},
  {-1.000000, 0.000000, 0.000000},
  {-1.000000, 0.000000, 5.000000},
  {-0.707107, -0.707107, 0.000000},
  {-0.707107, -0.707107, 5.000000},
  {0.000000, -1.000000, 0.000000},
  {0.000000, -1.000000, 5.000000},
  {0.707107, -0.707107, 0.000000},
  {0.707107, -0.707107, 5.000000},
  {1.000000, 0.000000, 0.000000},
  {1.000000, 0.000000, 5.000000},
};
float fogDensity = 0.1;
static float fog_color[] = {0.0, 0.0, 0.0, 1.0};

void init_opengl()
{
	glShadeModel(GL_SMOOTH);

	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);

	glClearDepth(1.0);

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, fogDensity);
	glFogfv(GL_FOG_COLOR, fog_color);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	/* *INDENT-OFF* */
	glNewList(cubeList, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	  glNormal3fv(scp[0]);
	  glVertex3fv(scp[0]);
	  glNormal3fv(scp[0]);
	  glVertex3fv(scp[1]);
	  glNormal3fv(scp[2]);
	  glVertex3fv(scp[2]);
	  glNormal3fv(scp[2]);
	  glVertex3fv(scp[3]);
	  glNormal3fv(scp[4]);
	  glVertex3fv(scp[4]);
	  glNormal3fv(scp[4]);
	  glVertex3fv(scp[5]);
	  glNormal3fv(scp[6]);
	  glVertex3fv(scp[6]);
	  glNormal3fv(scp[6]);
	  glVertex3fv(scp[7]);
	  glNormal3fv(scp[8]);
	  glVertex3fv(scp[8]);
	  glNormal3fv(scp[8]);
	  glVertex3fv(scp[9]);
	  glNormal3fv(scp[10]);
	  glVertex3fv(scp[10]);
	  glNormal3fv(scp[10]);
	  glVertex3fv(scp[11]);
	  glNormal3fv(scp[12]);
	  glVertex3fv(scp[12]);
	  glNormal3fv(scp[12]);
	  glVertex3fv(scp[13]);
	  glNormal3fv(scp[14]);
	  glVertex3fv(scp[14]);
	  glNormal3fv(scp[14]);
	  glVertex3fv(scp[15]);
	  glNormal3fv(scp[16]);
	  glVertex3fv(scp[16]);
	  glNormal3fv(scp[16]);
	  glVertex3fv(scp[17]);
	glEnd();
	glEndList();
	/* *INDENT-ON* */
}
