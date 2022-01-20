#include<iostream>
#include<fstream>
#include<cassert>
#include<cstdlib>

using namespace std;

#ifndef ENTITIES
#define ENTITIES
enum entity_type {CAMERA_ENT, LIGHT_ENT, MATERIAL_ENT, PLANE_ENT};

const string entities[] =
{
   "camera",
   "light",
   "material",
   "plane"
};

#define NUM_ENTITIES (sizeof(entities) / sizeof(entities[0]))
#endif

#ifndef ATTRIBUTES
#define ATTRIBUTES
enum attribute_type {PIXELDIM_ATT, WORLDDIM_ATT, VIEWPOINT_ATT, AMBIENT_MAT, DIFFUSE_MAT, SPECULAR_MAT};

const string attributes[] =
{
   "pixeldim",
   "worlddim",
   "viewpoint",
   "ambient",
   "diffuse",
   "specular"
};

#define NUM_ATTRIBUTES (sizeof(attributes) / sizeof(attributes[0]))
#endif
#define MAX 10
#include"rayhdrs.h"
