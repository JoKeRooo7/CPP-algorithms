CPP = g++ -Wall -Werror -Wextra

all: create_build
	# chmod +x *.cpp
	$(СPP) main.cpp -o build/run1
	$(CPP) main_algoritm.cpp -o build/run2

create_build: clean
	mkdir build;

run1: create_build
	$(СPP) main.cpp -o build/run1

run2: create_build
	$(CPP) main_algoritm.cpp -o build/run2

clean:
	rm -rf build *.txt

leak:
	CK_FORK=no leaks --atExit -- build/run1 -e on4fdase -e twogsdfgsdf main.cpp -f pattern1.txt
	CK_FORK=no leaks --atExit -- build/run2 -e on4fdase -e twogsdfgsdf main_algoritm.cpp -f pattern2.txt

clang:
	clang-format -i $(WAY)*.cpp
	clang-format -n $(WAY)*.cpp