# All Targets
all: cyber

# Tool invocations
# Executable "cyber" depends on the files cyber.o and run.o.
cyber: bin/cyberworm.o bin/cyberdns.o bin/cyberexpert.o bin/cyberpc.o bin/main.o
	@echo 'Building target: cyber'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/cyber bin/cyberworm.o bin/cyberdns.o bin/cyberexpert.o bin/cyberpc.o bin/main.o
	@echo 'Finished building target: cyber'
	@echo ' '

# Depends on the source and header files
bin/cyberworm.o: src/cyberworm.cpp
	g++ -g -Wall -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/cyberworm.o src/cyberworm.cpp
bin/cyberpc.o: src/cyberpc.cpp
	g++ -g -Wall -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/cyberpc.o src/cyberpc.cpp
bin/cyberexpert.o: src/cyberexpert.cpp
	g++ -g -Wall -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/cyberexpert.o src/cyberexpert.cpp
bin/cyberdns.o: src/cyberdns.cpp
	g++ -g -Wall -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/cyberdns.o src/cyberdns.cpp
bin/main.o: src/main.cpp
	g++ -g -Wall -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/main.o src/main.cpp

#Clean the build directory
clean: 
	rm -f bin/*