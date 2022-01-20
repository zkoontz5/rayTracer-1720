#include<iostream>
#include"ray.h"

#ifndef DRGB
#define DRGB
//for lights and reflective materials, 
//0.0 means black and 1.0 means maximal brightness
class drgb_t
{
   public:
      double r;
      double g;
      double b;

      drgb_t()
      {
         r=g=b=0;
      }

      void dumper(ostream &outs)
      {
         double red = r;
         double green = g;
         double blue = b;
         outs << red << " " << green << " " << blue << endl;
      }

      friend ostream & operator<<(ostream &out, const drgb_t &other)
      {
         out << fixed << showpoint;
         out << other.r << " " << other.g << " " << other.b;
         return out;
      }

      friend istream & operator>>(istream &in, drgb_t &rgb)
      {
         double brightness;
         in >> brightness;
         if(brightness < 0.0)
         {
            cerr << "Bad value." << endl;
            exit(4);
         }
         rgb.r = brightness;

         in >> brightness;
         if(brightness < 0.0)
         {
            cerr << "Bad value." << endl;
            exit(5);
         }
         rgb.g = brightness;

         in >> brightness;
         if(brightness < 0.0)
         {
            cerr << "Bad value." << endl;
            exit(6);
         }
         rgb.b = brightness;
         
         return in;
      }
};
#endif
