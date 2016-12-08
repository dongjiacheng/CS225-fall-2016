EXENAME = testimage
EXENAME2 = testscene
OBJS =  png.o rgbapixel.o image.o testimage.o
OBJS2 = testscene.o scene.o png.o rgbapixel.o image.o
CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread
ifdef asan
ASANFLAGS = -fsanitize = address
endif

all : $(EXENAME) $(EXENAME2)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)
$(EXENAME2) : $(OBJS2)
	$(LD) $(OBJS2) $(LDFLAGS) -o $(EXENAME2)
image.o: image.h image.cpp png.h rgbapixel.h rgbapixel.h
	$(CXX) $(CXXFLAGS) image.cpp
	
testimage.o : png.h rgbapixel.h image.h testimage.cpp
	 $(CXX) $(CXXFLAGS) testimage.cpp

png.o : png.cpp png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) rgbapixel.cpp
testscene.o :testscene.cpp scene.h png.h rgbapixel.h image.h
	$(CXX) $(CXXFLAGS) testscene.cpp

scene.o: scene.cpp scene.h image.h rgbapixel.h png.h
	$(CXX) $(CXXFLAGS) scene.cpp


clean :
	rm *.o testimage testscene
