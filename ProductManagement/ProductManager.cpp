#include "ProductManager.hpp"

ProductManager::ProductManager(){}
ProductManager::~ProductManager(){}

void ProductManager::addProduct(const Product& product) {
    products.push_back(product);
}
void ProductManager::removeProduct(int id) {
    for (auto it = products.begin(); it != products.end(); ++it) //poruszanie si� po wektorze za pomoc� iteratora
    {
        if (it->get_id() == id) {
            products.erase(it);
            break;
        }
    }
}
void ProductManager::displayProducts() const {
    std::cout << "Lista produkt�w:\n";
    for (const auto& product : products) 
    {
        std::cout << "ID: " << product.get_id()<< ", Nazwa: " << product.get_name()<< ", Cena: " << product.get_price() << " z�\n";
    }
}
void ProductManager::saveToFile(const std::string& filename) {
	// implementacja zapisu do pliku binarnego
}
void ProductManager::loadFromFile(const std::string& filename) {
	// implementacja odczytu z pliku binarnego
}
