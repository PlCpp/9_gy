#include <iostream>
#include <memory>

int main() {
	std::unique_ptr<int> sptr(new int(5));
	
	std::cout << *sptr << std::endl;
	
	std::unique_ptr<int[]> sptr2(new int[10]);
	sptr2[0] = 345;
	std::cout << sptr2[0] << std::endl;
	sptr2.reset(); //így is felszabadíthatjuk a dinamikusan foglalt területet
}