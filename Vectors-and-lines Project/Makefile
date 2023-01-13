# only runs if there are changes in the two task files
task: ball.cpp  hit.cpp table.cpp line.cpp vector.cpp point.cpp
	g++ *.cpp -o task 

#runs if there are changes in any file (probably won't be needed)
all: point.h point.cpp vector.h vector.cpp line.h line.cpp table.h table.cpp hit.h hit.cpp ball.h ball.cpp main.cpp
	g++ *.cpp -o all 

#used to remove the executable
clean: 
	$(RM) task
	$(RM) all