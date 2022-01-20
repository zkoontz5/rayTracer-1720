#include"material_t.h"
using namespace std;

material_t::material_t()
{

}

material_t::material_t(istream &ins)
{
    string brace;

    ins >> name >> brace;
    load(ins);
}

drgb_t material_t::getamb()
{
    return ambient;
}

drgb_t material_t::getdif()
{
    return diffuse;
}

drgb_t material_t::getspec()
{
    return specular;
}

string material_t::getname()
{
    return name;
}

void material_t::dump(ostream &outs)
{
    outs << "Material: " << name << endl
         << "\tAmbient: " << ambient << endl 
         << "\tDiffuse: " << diffuse << endl
         << "\tSpecular: " << specular << endl;
}

void material_t::load(istream &ins)
{
    string material;
   
    ins >> material;
    while(material != "}") {
        item_load(ins,material);
        ins >> material;
    } 
}

void material_t::item_load(istream &ins, const string &attribute)
{
    int ndx;

    ndx = table_lookup(attributes, NUM_ATTRIBUTES, attribute);
    switch(ndx) {
        case AMBIENT_MAT: ins >> ambient;
                        break;
        case DIFFUSE_MAT: ins >> diffuse;
                        break;
        case SPECULAR_MAT: ins >> specular;
                        break;
   }
}
