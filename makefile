
OBJ=geoform.o scanline.o ischar.o identifier.o softcom.o \
   range.o

TARGET=geoform


$(TARGET): $(OBJ)
	gcc -o $(TARGET) $(OBJ)



geoform.o : geoform.h 

scanline.o : geoform.h 

identifier.o: geoform.h


geoform.h : scanline.h

