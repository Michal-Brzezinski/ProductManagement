#include "Product.hpp"

Product::Product(int m_id, std::string m_name, double m_price): id(m_id), name(m_name), price(m_price){}//Kontruktor obiektu klasy Product
Product:: ~Product(){} //destruktor obiektu klasy Product

void Product::set_id(int n_id)
{
	id = n_id;
}

int Product::get_id() const
{
	return id;
}

void Product::set_name(std::string& n_name)
{
	name = n_name;
}

const std::string& Product::get_name() const
{
	return name;
}

void Product::set_price(double n_price)
{
	price = n_price;
}

double Product::get_price() const
{
	return price;
}