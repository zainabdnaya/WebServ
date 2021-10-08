Name = tst
CC = clang++
Inc = student.h 
SRC = maps.cpp Student.cpp
obj = $(SRC:%.cpp=%.o);
.PHONY = all clean

all : $(Name) $(obj)
re:
$(Name) :
	@${CC}  $(SRC) $< -o $(Name)

clean:
	@echo "Cleaning up..."
	@rm -rf  $(Name) $(obj)
re: clean all