#include <iostream>
#include "ProductManager.hpp"

int main() {
	Product pro1(111,"Tytuul", 23.99);
	Product pro2(113, "Tytul2", 59.99);
	ProductManager manager;
	manager.addProduct(pro1);
	manager.addProduct(pro2);
	manager.displayProducts();
	manager.removeProduct(111);
	manager.displayProducts();
	// Testowanie funkcji
	return 0;
}