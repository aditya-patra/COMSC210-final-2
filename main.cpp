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
    while(getline(file, name)) {
        cout << name << endl;
    }
}