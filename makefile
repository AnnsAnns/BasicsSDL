#OBJS specifies which files to compile as part of the project
OBJS = src/*.cpp

#CC specifies which compiler we're using
CC_LINUX = g++
CC_WIN = x86_64-w64-mingw32-g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -I include

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main_exec

#This is the target that compiles our executable
linux : $(OBJS)
	$(CC_LINUX) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

win: $(OBJS)
	$(CC_WIN) $(OBJS) $(COMPILER_FLAGS) --static $(LINKER_FLAGS) -o $(OBJ_NAME).exe