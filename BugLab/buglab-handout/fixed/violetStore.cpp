#include <iostream>
#include <string>
#define min(a,b) (a<=b?a:b)

class price 
{
private:
    int n;                  // item's number
    std::string* items;     // item's name
    int* prices;            // item's price
    std::string store;      // store's name
public:
    price()
    {
        store = "Violet";   
        items = new std::string[3]; // I'm poor, max 3 items
        prices = new int[3];
        n = 0;
    }
    ~price()
    {
        delete[] items;
        delete[] prices;
    }
    void add_item(std::string name, int price) 
    {
        items[n] = name;
        prices[n] = price;
        n++;
    }
    void print_items() 
    {
        std::cout << "items of " << store << ":\n";
        for(int i = 0; i < n; ++i)
            std::cout << *(items + i) << ':' << *(prices + i) << std::endl;
    }
    int cheapest_item() // suppose only 3 items
    {
        return min(min(prices[0], prices[1]), prices[2]);
    }
};
int main()
{
    price* test = new price;
    test->add_item("apple", 1);
    test->add_item("banana", 3);
    test->add_item("cherry", 2);
    test->print_items();
    std::cout << "cheapest price: " <<  test->cheapest_item() << std::endl;
    delete test;
    return 0;
}
