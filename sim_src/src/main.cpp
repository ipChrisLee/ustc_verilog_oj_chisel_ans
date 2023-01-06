#include <iostream>

#include <VTop.h>

VTop vTop;

void singleCycle() {
	vTop.clock = 0;
	vTop.eval();
	vTop.clock = 1;
	vTop.eval();
}

int main() {
	std::cout << "GCD" << std::endl;
	vTop.io_value1 = 15;
	vTop.io_value2 = 12;
	vTop.io_loadingValues = 1;
	while (!vTop.io_outputValid) {
		singleCycle();
		if (vTop.io_loadingValues) { vTop.io_loadingValues = 0; }
		std::cout << vTop.io_outputGCD << " " << bool(vTop.io_outputValid) << std::endl;
	}
	return 0;
}