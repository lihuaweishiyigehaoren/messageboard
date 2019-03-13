all:
	cd socket && make;
	cd server && make;
	cd client && make;
clean:
	cd socket && make clean;
	cd server && make clean;
	cd client && make clean;