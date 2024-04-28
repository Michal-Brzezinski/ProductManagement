#include <iostream>
#include "ProductManager.hpp"

int main() {
	Product pro1(111,"Talon na balon", 23.99);
	Product pro2(113, "Oryginal G (OG)", 59.99);
	ProductManager manager;
	
	std::cout << "\033[34;1mAdd 1st product to a container\n\033[0m";
	manager.addProduct(pro1);
	
	std::cout << "\033[34;1mAdd 2nd product to a container\n\033[0m";
	manager.addProduct(pro2);
	
	std::cout << "\033[34;1m\nDisplay all products currently stored in the container\n\033[0m";
	manager.displayProducts();
	
	std::cout << "\033[34;1mRemove product with id = 111 from a container\n\033[0m";
	manager.removeProduct(111);
	
	std::cout << "\033[34;1m\nDisplay all products currently stored in the container\n\033[0m";
	manager.displayProducts();
	
	std::cout << "\033[34;1mSave all products from the container to a binary file\n\033[0m";
	manager.saveToFile("test_file.bin");
	
	Product pro3(222, "New g", 101.99);
	std::cout << "\033[34;1m\nAdd 3rd product to a container\n\033[0m";
	manager.addProduct(pro3);
	
	std::cout << "\033[34;1mLoad all products from a binary file to the container\n\033[0m";
	manager.loadFromFile("test_file.bin");
	
	std::cout << "\033[34;1m\nDisplay all products currently stored in the container\n\033[0m";
	manager.displayProducts();
	
	return 0;
}
/*
OUTPUT:

Add 1st product to a container
Add 2nd product to a container

Display all products currently stored in the container

Products list:
ID: 111, Name: Talon na balon, Price: 23.99 PLN
Product type: class Product

ID: 113, Name: Oryginal G (OG), Price: 59.99 PLN
Product type: class Product

Remove product with id = 111 from a container

Display all products currently stored in the container

Products list:
ID: 113, Name: Oryginal G (OG), Price: 59.99 PLN
Product type: class Product

Save all products from the container to a binary file

Successfully loaded product data into a binary file.

Add 3rd product to a container
Load all products from a binary file to the container

Products loaded from a binary file:
ID: 113, Name: Oryginal G (OG), Price: 59.99 PLN

Display all products currently stored in the container

Products list:
ID: 113, Name: Oryginal G (OG), Price: 59.99 PLN
Product type: class Product

ID: 222, Name: New g, Price: 101.99 PLN
Product type: class Product

*/