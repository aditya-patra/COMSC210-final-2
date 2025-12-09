#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

struct Coffee {
    public:
        string name;
        string order;
        Coffee* next = nullptr;
};

int main() {
    Coffee* head;
    ifstream file("orders.txt");
    string name;
    string order;
    vector<list<string>> orders;
    while(getline(file, name)) {
        list<string> order_pair;
        cout << name << endl;
        order_pair.push_back(name);
        getline(file, order);
        order_pair.push_back(order);
        orders.push_back(order_pair);
    }
    for(list<string> order_pair : orders) {
        for(auto it = order_pair.begin(); it != order_pair.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
}