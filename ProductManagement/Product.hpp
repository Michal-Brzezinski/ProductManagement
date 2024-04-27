#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>


class Product {
private:
	int id;
	std::string name;
	double price;
public:
	Product(int m_id, std::string m_name, double m_price);
	~Product();
	
	void set_id(int n_id);
	int get_id() const;//getter i setter id
	
	void set_name(std::string& n_name);
	const std::string& get_name() const;//getter i setter nazwy
	
	void set_price(double n_price);
	double get_price() const;//getter i setter ceny

};

#endif