#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>


struct 
{
	float oldR;
	float oldG;
	float oldB;
	float oldA;
	
} diffuseLight;


void init_scene(Scene* scene)
{	

    load_model(&(scene->fattree), "data/fattree.obj");
	
    scene->texture_id_ground = load_texture("data/grass.jpg"); 
	scene->texture_id_fattree = load_texture("data/fattree.png");

	diffuseLight.oldR = 0.8f;
	diffuseLight.oldG = 0.8f;
	diffuseLight.oldB = 0.8f;
	diffuseLight.oldA = 1.0f;
}

float ConstrainValue(float val)
{
	if (val > 10.0f)
	{
		val = 10.0f;
	}
	else if (val < 0.0f)
	{
		val = 0.0f;
	}
	return val;	
}

void set_lighting(float r, float g, float b, float a)
{
 	diffuseLight.oldR = ConstrainValue(diffuseLight.oldR + r);
	diffuseLight.oldG = ConstrainValue(diffuseLight.oldG + g);
	diffuseLight.oldB = ConstrainValue(diffuseLight.oldB + b);
	diffuseLight.oldA = ConstrainValue(diffuseLight.oldA + a);		
	
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { diffuseLight.oldR, diffuseLight.oldG, diffuseLight.oldB, diffuseLight.oldA};
    float specular_light[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    float position[] = { 0.0f, 0.0f, 100.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void draw_scene(const Scene* scene)
{
	// Set lighting
    set_lighting(0.0f, 0.0f, 0.0f, 0.0f);
	
	// Draw ground
	draw_ground(scene);
	
	// Draw model: fattree
	glBindTexture(GL_TEXTURE_2D, scene->texture_id_fattree);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glScalef(0.5f, 0.5f, 0.5f);
	glTranslatef(35, 0, 25);
    draw_model(&(scene->fattree));
	glPopMatrix();	
}

void draw_ground(const Scene* scene)
{
	glBindTexture(GL_TEXTURE_2D, scene->texture_id_ground);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 50.0f);                   
		glVertex2i(-50.0f, 50.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex2i(-50.0f, -50.0f);

		glTexCoord2f(50.0f, 0.0f);
		glVertex2i(50.0f, -50.0f);

		glTexCoord2f(50.0f, 50.0f);
		glVertex2i(50.0f, 50.0f);
	glEnd();	
}



