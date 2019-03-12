all:
	cd socket && make;
	cd server && make;
clean:
	cd socket && make clean;
	cd server && make clean;