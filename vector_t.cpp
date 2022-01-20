#include<iostream>
#include<math.h>
#include<iomanip>
#include"vector_t.h"

using namespace std;

//CONSTRUCTOR
vector_t::vector_t(double x_in, double y_in, double z_in)
{
    x = x_in;
    y = y_in;
    z = z_in;
}

//DESTRUCTOR
vector_t::~vector_t()
{}

//MUTATOR OF X
void vector_t::setX(double x_in)
{
    x = x_in;
}

//ACCESSOR OF X
double vector_t::getX()
{
    return x;
}

//MUTATOR OF Y
void vector_t::setY(double y_in)
{
    y = y_in;
}

//ACCESSOR OF Y
double vector_t::getY()
{
    return y;
}

//MUTATOR OF Z
void vector_t::setZ(double z_in)
{
    z = z_in;
}

//ACCESSOR OF Z
double vector_t::getZ()
{
    return z;
}
//SET VECTOR WITH VARIABLES
void vector_t::setVector(double x_in, double y_in, double z_in)
{
    x = x_in;
    y = y_in;
    z = z_in;
}

//SET VECTOR WITH VECTOR
void vector_t::setVector(vector_t vec)
{
    x = vec.getX();
    y = vec.getY();
    z = vec.getZ();
}

//RETURNS LENGTH OF THIS VECTOR
double vector_t::len()const
{
    return sqrt(pow(x, 2)+ pow(y, 2) + pow(z, 2));
}

//RETURNS DOT PRODUCT OF THIS VECTOR AND GIVEN VECTOR
double vector_t::dot(const vector_t &other)const
{
    return ((x * other.x) + (y * other.y) + (z * other.z));
}

//RETURNS UNIT VECTOR
vector_t vector_t::unit()const
{
    vector_t tempVect;
    tempVect = this->scale(1/this->len());
    return tempVect; 
}

//RETURNS THIS VECTOR SCALED WITH GIVEN VALUE
vector_t vector_t::scale(double factor)const
{
    vector_t tempVect(factor * x, factor * y, factor * z);
    return tempVect;
}

//OPERATOR + OVERLOADING
vector_t vector_t::operator+(const vector_t &other)const
{
   vector_t tempVect(other.x + x, other.y + y, other.z + z);
   return tempVect;
}

//OPERATOR - OVERLOADING
vector_t vector_t::operator-(const vector_t &other)const
{
   vector_t tempVect(x - other.x, y - other.y, z - other.z);
   return tempVect;
}

//OPERATOR == OVERLOADING
bool vector_t::operator==(const vector_t &other)const
{
   return (x == other.x && y == other.y && z == other.z);
}

//OPERATOR << OVERLOADING
ostream & operator<<(ostream &out, const vector_t &other)
{
    out << fixed << showpoint;
    out << "<" << setprecision(2) << other.x << ", " << setprecision(2) << other.y << ", " << setprecision(2) << other.z << ">";
    return out;
}

//OPERATOR >> OVERLOADING
istream & operator>>(istream &in, vector_t &vec)
{
    char ch;
    in >> ch;
    if(ch != '<')
    {
        cerr << "Bad vector" << endl;
        exit(1);
    }
    in >> vec.x;
    in >> ch;
    if(ch != ',')
    {
        cerr << "Bad vector" << endl;
        exit(2);
    }
    in >> vec.y;
    in >> ch;
    if(ch != ',')
    {
        cerr << "Bad vector" << endl;
        exit(3);
    }
    in >> vec.z;
    in >> ch;
    if(ch != '>')
    {
        cerr << "Bad vector" << endl;
        exit(4);
    }
    return in;
}
