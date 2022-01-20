#include"drgb_t.h"
#include<string>
#include<iostream>
#include"ray.h"

using namespace std;

#ifndef MATERIAL
#define MATERIAL

class material_t;
typedef material_t * material_tptr;

class material_t
{
    private:
        string name;
        drgb_t ambient;
        drgb_t diffuse;
        drgb_t specular;
    public:
        material_t();
        material_t(istream &ins);
        drgb_t getamb();
        drgb_t getdif();
        drgb_t getspec();
        string getname();
        void dump(ostream &outs);
    private:
        void load(istream &ins);
        void item_load(istream &ins, const string &attribute);
};
#endif
