all: *.cpp
	g++ *.cpp -o rotator

clean:
	rm -rf rotator
