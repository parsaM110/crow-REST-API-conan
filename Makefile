prepare:
	rmdir /s /q build
	mkdir build
	cd build && conan install .. && cd ..