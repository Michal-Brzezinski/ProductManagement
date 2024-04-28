#include "ProductManager.hpp"

ProductManager::ProductManager(){}
ProductManager::~ProductManager(){}

void ProductManager::addProduct(const Product& product) {
    try {
        // Check if the product ID already exists
        for (const auto& existingProduct : products) {
            if (existingProduct.get_id() == product.get_id()) {
                throw std::runtime_error("Product with the same ID already exists.");
            }
        }

        // Add the product to the vector
        products.push_back(product);
    }
    catch (const std::exception& e) {
        std::cerr << "Error adding product: " << e.what() << std::endl;
    }
}

void ProductManager::removeProduct(int id) {
    try {
        // Find the product with the specified ID
        auto it = std::find_if(products.begin(), products.end(), [id](const Product& p) {
            return p.get_id() == id;
            });

        if (it != products.end()) {
            // Remove the product
            products.erase(it);
        }
        else {
            throw std::runtime_error("Product with the specified ID does not exist.");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error removing product: " << e.what() << std::endl;
    }
}



void ProductManager::displayProducts() const{
    std::cout << "\nProducts list:\n";
    for (const auto& product : products) {
        std::cout << "ID: " << product.get_id() << ", Name: " << product.get_name() << ", Price: " << product.get_price() << " PLN\n";

        // Use RTTI to determine the actual type of the product
        const std::type_info& typeInfo = typeid(product);
        std::cout << "Product type: " << typeInfo.name() << "\n\n";
    }
}


void ProductManager::saveToFile(const std::string& filename) {
    
    try {
        std::ofstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Error opening file for writing.");
        }

        for (const auto& product : products) {
            double price = product.get_price();
            int id = product.get_id();
            size_t nameLength = product.get_name().length();
            file.write(reinterpret_cast<const char*>(&nameLength), sizeof(size_t));
            file.write(product.get_name().c_str(), nameLength);
            file.write(reinterpret_cast<const char*>(&price), sizeof(double));
            file.write(reinterpret_cast<const char*>(&id), sizeof(int));
        }

        file.close();
        std::cout << "\nSuccessfully loaded product data into a binary file.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error occured: " << e.what() << std::endl;
    }

}
void ProductManager::loadFromFile(const std::string& filename) {

    std::cout << std::endl;
    try {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Error opening file for reading.");
        }

        // Clear existing products (if any)
        prod_loading.clear();

        while (file) {
            size_t nameLength = 0;
            double price = 0;
            int id = 0;

            // Read the length of the product name
            file.read(reinterpret_cast<char*>(&nameLength), sizeof(size_t));

            if (!file) break; // Check if the read operation was successful

            // Read the product name
            std::string productName(nameLength, '\0');
            file.read(&productName[0], nameLength);

            if (!file) break; // Check if the read operation was successful

            // Read the product price
            file.read(reinterpret_cast<char*>(&price), sizeof(double));

            if (!file) break; // Check if the read operation was successful

            // Read the product id
            file.read(reinterpret_cast<char*>(&id), sizeof(int));

            if (!file) break; // Check if the read operation was successful

            // Create a new Product object
            Product product(id, productName, price); // You might need to adjust the ID

            // Add the product to the vector
            prod_loading.push_back(product);

            // Display the loaded product
            std::cout << "Products loaded from a binary file:\n";
            std::cout << "ID: " << id << ", Name: " << productName << ", Price: " << price<< " PLN\n";
        }

        file.close();
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred while loading from file: " << e.what() << std::endl;
    }

}
