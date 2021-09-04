#include <cstdlib>

int rand65536() {
	return rand() % 65536;
}

int rand5() {
	int x = 0;
	do {
		x = rand65536();
	} while (x == 65535);
	return x % 5;
}

int rand60000() {
	int x = 0;
	do {
		x = rand65536();
	} while (x >= 60000);
	return x % 60000;
}

int rand32w() {
	return rand5() * 60000 + rand60000();
}