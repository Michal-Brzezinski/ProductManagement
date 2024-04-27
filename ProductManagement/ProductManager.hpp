#ifndef PRODUCTMANAGER_HPP
#define PRODUCTMANAGER_HPP

#include "Product.hpp"
#include <vector>
#include <fstream>
#include <stdexcept>
#include <typeinfo>
#include <iostream>


class ProductManager {
private:
	std::vector<Product> products;
public:
	ProductManager();
	~ProductManager();
	void addProduct(const Product& product);
	void removeProduct(int id);
	void displayProducts() const;
	void saveToFile(const std::string& filename);
	void loadFromFile(const std::string& filename);
};

#endif