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
	
} ambientLight;

void init_scene(Scene* scene)
{	

//    load_model(&(scene->farm), "data/cube.obj");
    scene->texture_id = load_texture("data/grass.jpg"); 
    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue	 = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;
	
	ambientLight.oldR = 0.5f;
	ambientLight.oldG = 0.5f;
	ambientLight.oldB = 0.5f;
	ambientLight.oldA = 1.0f;
}

float ConstrainValue(float val)
{
	if (val > 1.0f)
	{
		val = 1.0f;
	}
	else if (val < 0.0f)
	{
		val = 0.0f;
	}
	return val;	
}

void set_lighting(float r, float g, float b, float a)
{
 	ambientLight.oldR = ConstrainValue(ambientLight.oldR + r);
	ambientLight.oldG = ConstrainValue(ambientLight.oldG + g);
	ambientLight.oldB = ConstrainValue(ambientLight.oldB + b);
	ambientLight.oldA = ConstrainValue(ambientLight.oldA + a);		
	
    float ambient_light[] = { ambientLight.oldR, ambientLight.oldG, ambientLight.oldB, ambientLight.oldA};
    float diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float specular_light[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
	
	float light2_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f};
	float light2_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f};
	float light2_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f};
	float light2_position[] = { 0.0f, 0.0f, 0.0f, 1.0f};
	
    glLightfv(GL_LIGHT1, GL_AMBIENT, light2_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light2_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light2_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light2_position);
	
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene)
{
//    set_material(&(scene->material));
    set_lighting(0.0f,0.0f,0.0f,0);
	
	glBindTexture(GL_TEXTURE_2D, scene->texture_id);
	glBegin(GL_QUADS);
		// Bottom left
		glTexCoord2f(0.0f, 50.0f);                   
		glVertex2i(-50.0f, 50.0f);

		// Top left
		glTexCoord2f(0.0f, 0.0f);
		glVertex2i(-50.0f, -50.0f);

		// Top right
		glTexCoord2f(50.0f, 0.0f);
		glVertex2i(50.0f, -50.0f);

		// Bottom right
		glTexCoord2f(50.0f, 50.0f);
		glVertex2i(50.0f, 50.0f);
	glEnd();

	
	
/*	glPushMatrix();
	glRotatef(90,1,0,0);
	glTranslatef(0,-2,0);
    draw_model(&(scene->farm));
	glPopMatrix();*/
}

