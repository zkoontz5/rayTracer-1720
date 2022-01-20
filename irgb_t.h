#ifndef IRGB
#define IRGB

//for pixmap data
//0 means black and 255 means maximal brightness
class irgb_t
{
   public:
      unsigned char r;
      unsigned char g;
      unsigned char b;

      irgb_t()
      {
         r=g=b=0;
      }

      void dumper(ostream &outs)
      {
         outs << r << " " << g << " " << b << endl;
      }

      friend ostream & operator<<(ostream &out, const irgb_t &other)
      {
         out << fixed << showpoint;
         out << "( " << other.r << ", " << other.g << ", " << other.b << ")";
         return out;
      }

      friend istream & operator>>(istream &in, irgb_t &rgb)
      {
         int brightness;
         in >> brightness;
         if(brightness > 255 || brightness < 0)
         {
            cerr << "Bad value." << endl;
            exit(1);
         }
         rgb.r = brightness;

         in >> brightness;
         if(brightness > 255 || brightness < 0)
         {
            cerr << "Bad value." << endl;
            exit(2);
         }
         rgb.g = brightness;

         in >> brightness;
         if(brightness > 255 || brightness < 0)
         {
            cerr << "Bad value." << endl;
            exit(3);
         }
         rgb.b = brightness;
         
         return in;
      }
};

#endif
