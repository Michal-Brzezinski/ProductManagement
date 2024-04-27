#include "ProductManager.hpp"

ProductManager::ProductManager(){}
ProductManager::~ProductManager(){}

void ProductManager::addProduct(const Product& product) {
    products.push_back(product);
}
void ProductManager::removeProduct(int id) {
    for (auto it = products.begin(); it != products.end(); ++it) //poruszanie siê po wektorze za pomoc¹ iteratora
    {
        if (it->get_id() == id) {
            products.erase(it);
            break;
        }
    }
}
void ProductManager::displayProducts() const {
    std::cout << "Lista produktów:\n";
    for (const auto& product : products) 
    {
        std::cout << "ID: " << product.get_id()<< ", Nazwa: " << product.get_name()<< ", Cena: " << product.get_price() << " z³\n";
    }
}
void ProductManager::saveToFile(const std::string& filename) {
	// implementacja zapisu do pliku binarnego
}
void ProductManager::loadFromFile(const std::string& filename) {
	// implementacja odczytu z pliku binarnego
}
