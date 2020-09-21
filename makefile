#OBJS specifies which files to compile as part of the project
OBJS = src/*.cpp

#CC specifies which compiler we're using
CC_LINUX = g++
CC_WIN = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

FLAGS_WIN_ONLY = -DSDL_MAIN_HANDLED

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -I include

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main_exec

#This is the target that compiles our executable
linux : $(OBJS)
	$(CC_LINUX) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

win: $(OBJS)
	$(CC_WIN) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(FLAGS_WIN_ONLY) -o $(OBJ_NAME).exe