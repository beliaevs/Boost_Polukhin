CPP=g++
CPPOPT=-std=c++17 -Wall -Wpedantic -Wextra

non_copyable.exe: main.cpp myclass.h
	$(CPP) $(CPPOPT) main.cpp -o non_copyable.exe

clean:
	rm -f non_copyable.exe
