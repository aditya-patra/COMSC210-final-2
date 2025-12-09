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
    Coffee* head = nullptr;
    ifstream file("orders.txt");
    string name;
    string order;
    vector<list<string>> orders;
    while(getline(file, name)) {
        list<string> order_pair;
        // cout << name << endl;
        order_pair.push_back(name);
        getline(file, order);
        order_pair.push_back(order);
        orders.push_back(order_pair);
    }
    int cnt = 0;
    for(const auto& order_pair : orders) {
        int name_extracted = 0;
        for(auto it = order_pair.begin(); it != order_pair.end(); it++) {
            if (!name_extracted) {
                name = *it;
                name_extracted = 1;
            }
            else {
                order = *it;
            }
        }
        if (head != nullptr) {
            Coffee* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
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
        cnt++;
        if (cnt == 3) {
            break;
        }
    }
    Coffee* temp = head;
    cout << "Current Line: " << endl;
    while(temp != nullptr) {
        cout << temp->name << " " << temp->order << endl;
        temp = temp->next;
    }
    for(int i = 0; i < 10; i++) {
        if (head != nullptr) {
            Coffee* serve = head;
            head = head->next;
            delete serve;
        }
        int rand_var = (int)(rand() % 100);
        if ((int)(rand() % 100) > 49) {
            int curr_idx = 0;
            for(const auto& order_pair : orders) { 
                if (curr_idx < cnt) {
                    curr_idx++;
                    continue;
                }
                else {
                    cnt++;
                }
                int name_extracted = 0;
                for(auto it = order_pair.begin(); it != order_pair.end(); it++) {
                    if (!name_extracted) {
                        name = *it;
                        name_extracted = 1;
                    }
                    else {
                        order = *it;
                    }
                }
                if (head != nullptr) {
                    Coffee* temp = head;
                    while (temp->next != nullptr) {
                        temp = temp->next;
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
                break;
            }
        }
        Coffee* temp = head;
        cout << "Current Line: " << endl;
        while(temp != nullptr) {
            cout << temp->name << " " << temp->order << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}