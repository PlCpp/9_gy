#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	int x = 10;
	void* p = &x;
	//std::cout << *p << std::endl; // fordítási hiba
	std::cout << *(int*)p << std::endl;
	void* y = malloc(sizeof(char) * strlen("alma") + 1);
	strcpy((char*) y, "alma");
	//delete y; fordítási hiba, nem tudja mennyi helyet kell felszabadítani.
	printf("%s", (char*) y);
	delete (char*) y;
	//free(y); -> kevésbé hatékony mint a delete operátor, nem hívja meg a destruktorokat, C-ben vol használatos
	
	return 0;
}