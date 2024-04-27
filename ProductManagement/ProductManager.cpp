#include "ProductManager.hpp"

void ProductManager::addProduct(const Product& product) {
	// implementacja dodawania produktu
	// obs³uga wyj¹tków w przypadku konfliktu ID
}
void ProductManager::removeProduct(int id) {
	// implementacja usuwania produktu
	// obs³uga wyj¹tków w przypadku braku produktu o podanym ID
}
void ProductManager::displayProducts() {
	// implementacja wyœwietlania produktów
	// wykorzystanie RTTI do okreœlenia typu obiektów
}
void ProductManager::saveToFile(const std::string& filename) {
	// implementacja zapisu do pliku binarnego
}
void ProductManager::loadFromFile(const std::string& filename) {
	// implementacja odczytu z pliku binarnego
}