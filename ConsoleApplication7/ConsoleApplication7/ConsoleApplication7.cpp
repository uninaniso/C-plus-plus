#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

class Product {
	static int lastComparisons;


	string nameProduct;
	int price;
	int quantity;

	int temporaryMemory;

public:

	static int LastComparisons() { return lastComparisons; }

	int Price(int price) { this->price = price; }
	int Price() { return this->price; }

	int Quantity(int quantity) { this->quantity = quantity; }
	int Quantity() { return this->quantity; }

	int TemporaryMemory() { return temporaryMemory; }

	int Comparisons(int price) {
		if (this->price != price){

			this->lastComparisons = 0;
			return this->lastComparisons;
		}

		else if (this->price == price) {

			this->lastComparisons = 1;
			return this->lastComparisons;
		}

		else if (this->price > price) {

			this->temporaryMemory = this->price - price;

			this->lastComparisons = 2;
			return this->lastComparisons;
		}

		else if (this->price < price) {

			this->temporaryMemory = price - this->price;

			this->lastComparisons = 3;
			return this->lastComparisons;
		}
	}


	Product(string name, int price, int quantity) {
		if (name.size() == 0)throw runtime_error("LongTextZero");
		else this->nameProduct = name;

		if (price < 1)throw runtime_error("UnacceptablePriceProducts");
		else this->price = price;

		if (quantity < 1)throw runtime_error("UnacceptableQuantityProducts");
		else this->quantity = quantity;
	}
};

class Warehouse {
	vector<Product> products;

public:

	void AddProduct(Product product) { this->products.push_back(product); }
	void AddProduct(string name, int price, int quantity) { this->products.push_back(Product(name, price, quantity)); }

	void RemoveProduct(Product product) {
		for (int i = 0; i < this->products.size(); i++) {

		}
	}
};

int main()
{

}