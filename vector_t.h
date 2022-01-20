#include<iostream>

using namespace std;

#ifndef VECTORTYPE
#define VECTORTYPE
class vector_t
{
    private:
        //Private instance variables represent the coordinates on a 3D plane, x, y, and z
        double x;
        double y;
        double z;
    public:
        //Constructor acts and default and normal
        // x, y, and z either become 0 or the supplied value
        vector_t(double =0, double =0, double =0);
        //Destructor
        ~vector_t();

        //accessor and mutator methods for the x variable
        //x either becomes 0 or the given value
        void setX(double =0);
        //returns double value of x
        double getX();

        //accessor and mutator methods for the y variable
        //y either becomes 0 or the given value
        void setY(double =0);
        //returns double value of y
        double getY();

        //accessor and mutator methods for the z variable
        //z either becomes 0 or the given value
        void setZ(double =0);
        //returns the double value of z
        double getZ();

        //mutator method for entire class
        //sets x, y, and z to either 0 or given variables
        void setVector(double =0, double =0, double =0);
        //sets vector with values of instance variables of supplied vector
        void setVector(vector_t);

        //returns length of vector
        double len(void)const;

        //scales vector with given double and returns said vector
        vector_t scale(double)const;

        //returns base unit vector based on vector from this class
        vector_t unit(void)const;

        //returns dot product of this vector and given vector
        double dot(const vector_t &other)const;

        //OPERATOR OVERLOADING
        //overloads the '+' operator, adds this vector and given vector and returns result
        vector_t operator+(const vector_t &other)const;

        //overloads the '-' operator, subtracts this vector and given vector and returns result
        vector_t operator-(const vector_t &other)const;

        //overloads the '==' operator, returns true or false based on if this vector and the given vector are equal
        bool operator==(const vector_t &other)const;

        //overloads the '>>' operator, reads in vector and sets it to given vector
        friend istream & operator>>(istream &in, vector_t &vec);
        
        //overloads the '<<' operator, puts value of given vector into ostream variable
        friend ostream & operator<<(ostream &out, const vector_t &vec);
};
#endif
