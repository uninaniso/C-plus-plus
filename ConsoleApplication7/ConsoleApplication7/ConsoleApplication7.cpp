#include <iostream>
#include <vector>

using namespace std;

class Product {
    static int lastComparisons;
    
    string nameProduct;
    int price;
    int quantity;

    int temporaryMemory;

public:
    static int LastComparisons() { return lastComparisons; }

    string NameProduct() { return this->nameProduct; }
    void NameProduct(const string& name) { this->nameProduct = name; }

    int Price() { return this->price; }
    void Price(int price) { this->price = price; }

    int Quantity() { return this->quantity; }
    void Quantity(int quantity) { this->quantity = quantity; }

    int TemporaryMemory() { return temporaryMemory; }

    int Comparisons(int otherPrice) {
        if (this->price == otherPrice) {
            this->lastComparisons = 1;
        }
        else if (this->price > otherPrice) {
            this->temporaryMemory = this->price - otherPrice;
            this->lastComparisons = 2;
        }
        else {
            this->temporaryMemory = otherPrice - this->price;
            this->lastComparisons = 3;
        }
        return this->lastComparisons;
    }

    Product(const string& name, int price, int quantity) {
        if (!name.empty())this->nameProduct = name;
        else this->nameProduct = "default";

        if (price > 1)this->price = price;
        else this->price = 1;

        if (quantity > 1)this->quantity = quantity;
        else this->quantity = 1;
    }
};


class Warehouse {
    vector<Product> products;

public:
    void AddProduct(const Product& product) { this->products.push_back(product); }
    void AddProduct(const string& name, int price, int quantity) { this->products.push_back(Product(name, price, quantity)); }

    void RemoveProduct(int productId) {
        if (productId >= 0 && productId < this->products.size()) {
            this->products.erase(this->products.begin() + productId);
        }
    }

    int QuantityProduct() { return this->products.size(); }

    void FindProductPrice(int price) {
        if (price > 0) {
            for (int i = 0; i < this->products.size(); i++) {
                if (this->products[i].Price() == price)
                    cout << "index " << i << "\nProduct " << this->products[i].NameProduct()
                    << " price " << this->products[i].Price() << " quantity " << this->products[i].Quantity() << endl;
            }
        }
    }

    void FindProductName(const string& name) {
        if (!name.empty()) {
            for (int i = 0; i < this->products.size(); i++) {
                if (this->products[i].NameProduct() == name)
                    cout << "index " << i << "\nProduct " << this->products[i].NameProduct()
                    << " price " << this->products[i].Price() << " quantity " << this->products[i].Quantity() << endl;
            }
        }
    }

    void FindProductQuantity(int quantity) {
        if (quantity > 0) {
            for (int i = 0; i < this->products.size(); i++) {
                if (this->products[i].Quantity() == quantity)
                    cout << "index " << i << "\nProduct " << this->products[i].NameProduct()
                    << " price " << this->products[i].Price() << " quantity " << this->products[i].Quantity() << endl;
            }
        }
    }

    void AllProduct() {
        for (int i = 0; i < this->products.size(); i++) {
            cout << "index " << i << "\nProduct " << this->products[i].NameProduct()
                << " price " << this->products[i].Price() << " quantity " << this->products[i].Quantity() << endl;
        }
    }
};

int main() {
    Warehouse w;
    w.AddProduct(Product("CID0", 20, 130));
    w.AddProduct(Product("CID1", 20, 55));
    w.AddProduct(Product("CID2", 40, 55));

    w.AllProduct();

    cout << "\n\n";

    w.FindProductPrice(20);

    cout << "\n\n";

    w.RemoveProduct(2);

    cout << "\n\n";

    w.AllProduct();

    cout << "\n\nquantity " << w.QuantityProduct();

    return 0;
}
