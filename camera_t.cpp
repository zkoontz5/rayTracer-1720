#include"camera_t.h"
/* constructor:
 * pre-condition:
 * post-condition:
 */
camera_t::camera_t(istream &ins)
{
   string brace;

   ins >> name;
   ins >> brace;

   load(ins);
   
   //pixmap....dynamically setup the pixmap - later....
}

/* load:
 * pre-condition:
 * post-condition:
 */
void camera_t::load(istream &ins)
{   
   string attribute; 

   ins >> attribute;
   while(attribute != "}")
   {
      item_load(ins, attribute);
      ins >> attribute;
   }
}

/* item_load:
 * pre-condition:
 * post-condition:
 */
void camera_t::item_load(istream &ins, const string &attribute)
{
   int ndx;
   
   ndx = table_lookup(attributes, NUM_ATTRIBUTES, attribute);
   switch(ndx)
   {
      case PIXELDIM_ATT: ins >> pixel_dim[0] >> pixel_dim[1];
                  break;
      case WORLDDIM_ATT: ins >> world_dim[0] >> world_dim[1];
                  break;
      case VIEWPOINT_ATT: ins >> view_point;
                  break;
   }
}

/* getxdim:
 * pre-condition:
 * post-condition:
 */
int camera_t::getxdim(void)
{
   return pixel_dim[0];
}

/* getydim:
 * pre-condition:
 * post-condition:
 */
int camera_t::getydim(void)
{
   return pixel_dim[1];
}

/* getviewpt:
 * pre-condition:
 * post-condition:
 */
vector_t getviewpt(void)
{
   vector_t rv(0,0,0);
   return rv;  //will update later
}

/* dump:
 * pre-condition:
 * post-condition:
 */
void camera_t::dump(ostream &outs)
{
   outs << "Camera: " << name << endl;
   outs << "\tpixeldim: " << pixel_dim[0] << " " << pixel_dim[1] << endl;
   outs << "\tworlddim: " << world_dim[0] << " " << world_dim[1] << endl;
   outs << "\tviewpoint: " << view_point << endl;
}

/* getdir:
 * pre-condition:
 * post-condition:
 */
void camera_t::getdir(int x, int y, vector_t &raydir)
{

}

/* setpix:
 * pre-condition:
 * post-condition:
 */
void camera_t::setpix(int x, int y, drgb_t *d_pix)
{
   irgb_t i_pix;
   i_pix.r = (unsigned char)(d_pix->r*255);
   i_pix.g = (unsigned char)(d_pix->g*255);
   i_pix.b = (unsigned char)(d_pix->b*255);
   int offset = ((pixel_dim[1]-y-1)*pixel_dim[0] + x);
   //Don't forget, the offset will be mult by sizeof(irgb_t)
   *(pixmap+offset) = i_pix;
}

/* write_image:
 * pre-condition:
 * post-condition:
 */
void camera_t::write_image(const char *image_filename)
{
   ofstream outs;
   outs.open(image_filename);
   if(outs.fail()) {
      cerr << "Problems creating image file: " << image_filename << endl;
      exit(1); 
   } else {
      outs << "P6" << endl;
      outs << "#my ray trace image" << endl;
      outs << pixel_dim[0] << " " << pixel_dim[1] << endl;
      outs << "255" << endl;;
      //output all of the pixel information here, cover this later
      outs.close(); 
   }
}
