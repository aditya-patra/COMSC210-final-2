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
        int name_extracted = 0;
        for(auto it = order_pair.begin(); it != order_pair.end(); it++) {
            if (!name_extracted) {
                name = *it;
                name_extracted = 1;
                cout << name << " ";
            }
            else {
                order = *it;
                cout << order << endl;
            }
        }
        if (head != nullptr) {
            Coffee* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
                cout << "next";
            }
            Coffee* new_order = new Coffee;
            new_order->name = name;
            new_order->order = order;
            temp->next = new_order;
        }
        else {
            Coffee* new_order = new Coffee;
            new_order->name = name;
            new_order->order = order;
            head = new_order;
        }
    }
    /*
    Coffee* temp = head;
    while(temp != nullptr) {
        // cout << temp->name << " " << temp->order << endl;
        temp = temp->next;
    }*/
}