#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model fattree;
	
    Material material;
    GLuint texture_id_ground;
	GLuint texture_id_fattree;
} Scene;

/* Scene initialization */
void init_scene(Scene* scene);

/* Set scene lighting */
void set_lighting(float r, float g, float b, float a);

/* Draw scene objects */
void draw_scene(const Scene* scene);

/* Draw ground */
void draw_ground(const Scene* scene);

#endif /* SCENE_H */
