#include <stdio.h>

#ifdef _WIN32
#include "windows.h"
int WINAPI WinMain (HINSTANCE h, HINSTANCE hh, LPSTR cmd, int show) {
#else
int main(int argc, char *argv[]) {
#endif
	printf("test\n");
};


