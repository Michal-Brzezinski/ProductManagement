#include "ProductManager.hpp"

void ProductManager::addProduct(const Product& product) {
	// implementacja dodawania produktu
	// obs�uga wyj�tk�w w przypadku konfliktu ID
}
void ProductManager::removeProduct(int id) {
	// implementacja usuwania produktu
	// obs�uga wyj�tk�w w przypadku braku produktu o podanym ID
}
void ProductManager::displayProducts() {
	// implementacja wy�wietlania produkt�w
	// wykorzystanie RTTI do okre�lenia typu obiekt�w
}
void ProductManager::saveToFile(const std::string& filename) {
	// implementacja zapisu do pliku binarnego
}
void ProductManager::loadFromFile(const std::string& filename) {
	// implementacja odczytu z pliku binarnego
}