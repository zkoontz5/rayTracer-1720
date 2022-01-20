RAYOBJS = raytracer.o model_t.o  camera_t.o vector_t.o rayfunctions.o material_t.o
RAYHDRS = model_t.h camera_t.h irgb_t.h drgb_t.h vector_t.h rayhdrs.h material_t.h
rayTrace: $(RAYOBJS)
	g++ -Wall -g *.o -lm -o rayTrace
$(RAYOBJS): $(RAYHDRS) makefile
raytracer.o: raytracer.cpp 
	g++ -Wall -c -g raytracer.cpp
vector_t.o: vector_t.cpp vector_t.h
	g++ -Wall -c -g vector_t.cpp
model_t.o: model_t.cpp model_t.h
	g++ -Wall -c -g model_t.cpp
camera_t.o: camera_t.cpp camera_t.h
	g++ -Wall -c -g camera_t.cpp
rayfunctions.o: rayfunctions.cpp rayhdrs.h
	g++ -Wall -c -g rayfunctions.cpp
material_t.o: material_t.cpp material_t.h
	g++ -Wall -c -g material_t.cpp
clean:
	rm *.o rayTrace
