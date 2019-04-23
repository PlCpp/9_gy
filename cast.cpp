#include <iostream>
#include <typeinfo>

class Base {
	public:
		int a;
		Base(): a(50) {}
		
		virtual void dummy() {}
		void d() {}
};
class Derived : public Base {
	public:
		int c;
};
class A {
	public:
		int a;
		A(): a(2) {}
};

void print (A* obj) {
	std::cout << "Print: " << obj->a << std::endl;
}

void printNumber(int* i) {
	*i = 23;
	std::cout << "PrintNumber: " << *i << std::endl;
}

int main() {
	Base b;
	Derived d;
	Base* bp = new Derived;
	Derived* dp = new Derived;
	int x = 5;
	int* p;
	A a;
	
	//0. c-like (c-szerű)
	
	std::cout << ((Base)d).a << std::endl;
	std::cout << ((Derived*)bp)->c << std::endl; //random memória szemét, c-nek nem adtunk kedőértéket
	//std::cout << ((Derived)b).c << std::endl; //Fordítási hiba
	Base* bp2 = (Base*) &a;
	std::cout << bp2->a << std::endl; //definiálatlan viselkedés
	p = (int*) &d;
	std::cout << "C1: " << *p << std::endl; //Működik, de értelmetlen
	
	//1. dynamic cast
	
	//std::cout << dynamic_cast<Base>(d).a << std::endl;
	//Fordítási hiba, csak referencia vagy pointer esetén működik
	//javítás:
	std::cout << "Dyn1: " << dynamic_cast<Base*>(&d)->a << std::endl;
	std::cout << "Dyn2: " << dynamic_cast<Base*>(dp)->a << std::endl;
	std::cout << "Dyn3: " << dynamic_cast<Derived*>(bp)->c << std::endl;
	//Ha a forrás osztály (Base) nem polimorfikus (nincs felüldefiniálható metódusa), akkor ez is fordítási hiba
	//Érdekesség: itt c értéke 0 és nem random memória szemét, mert dinamikus területen van, nem a stack-en
	
	//std::cout << "Dyn4: " << dynamic_cast<A*>(bp)->a << std::endl;
	//Ez lefordul, de futáshiba
	
	
	//2. static cast
	
	std::cout << "Stat1: " << static_cast<Derived*>(bp)->c << std::endl;
	//Ez akkor is működne, ha a forrásosztály nem lenne polimorfikus
	std::cout << "Stat2: " << static_cast<Base>(d).a << std::endl;
	std::cout << "Stat3: " << static_cast<char>(x) << std::endl;
	std::cout << "Stat4: " << static_cast<Derived*>(&b)->c << std::endl;
	//Működik, de definiálatlan viselkedés
	//std::cout << "Stat5: " << static_cast<Derived>(b).a << std::endl;
	//Fordítási hiba, a Derived class-nak nincs Base típust fogadó copy ctora 
	
	//3. reinterpret cast
	//std::cout << "Re1: " << reinterpret_cast<Base>(d).a << std::endl; //Fordítási hiba
	std::cout << "Re2: " << reinterpret_cast<Derived*>(bp)->c << std::endl;
	std::cout << "Re3: " << reinterpret_cast<A*>(bp)->a << std::endl;
	//Működik, de definiálatlan
	std::cout << "Re4: " << reinterpret_cast<A*>(&x)->a << std::endl;
	//Működik, de definiálatlan
	
	//4. const cast
	const A a2;
	const A* ap = &a2;
	//print(&a2); // fordítási hiba, a2 konstans, sima pointer nem mutathat rá
	print(const_cast<A*>(&a2));
	const int y = 30;
	printNumber(const_cast<int*>(&y));
	std::cout << y << std::endl;
	
	//Típus lekérdezés
	
	std::cout << typeid(int).name() << std::endl; //type_info objektumot ad vissza
	std::cout << typeid(b).name() << std::endl;
	std::cout << typeid(bp).name() << std::endl;
	std::cout << typeid(*bp).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
	std::cout << (typeid(d) == typeid(Derived)) << std::endl;
	
	
	return 0;
}