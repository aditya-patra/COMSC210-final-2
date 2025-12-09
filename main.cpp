#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <deque>

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
    deque<list<string>> muffins;
    vector<list<string>> bracelets;
    while(getline(file, name)) {
        list<string> order_pair;
        // cout << name << endl;
        order_pair.push_back(name);
        getline(file, order);
        order_pair.push_back(order);
        orders.push_back(order_pair);
    }
    int cnt_coffee = 0;
    int cnt_muffins = 0;
    int cnt_bracelets = 0;
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
        muffins.push_back(order_pair); 
        cnt_muffins++;
        bracelets.push_back(order_pair); 
        cnt_bracelets++;
        cnt_coffee++;
        if (cnt_coffee == 3) {
            break;
        }
    }
    Coffee* temp = head;
    cout << "Coffee Queue: " << endl;
    while(temp != nullptr) {
        cout << temp->name << "  " << temp->order << endl;
        temp = temp->next;
    }
    cout << "\nMuffins Queue: " << endl;
    for(const auto& pair: muffins) {
        for (auto it = pair.begin(); it != pair.end(); it++) {
            cout << *it << "  ";
        }
        cout << endl;
    }
    cout << "\nBracelet Queue: " << endl;
    for(const auto& pair: bracelets) {
        for (auto it = pair.begin(); it != pair.end(); it++) {
            cout << *it << "  ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < 10; i++) {
        cout << "\nSimulation " << (i+1) << ": \n";
        if (head != nullptr) {
            Coffee* serve = head;
            head = head->next;
            delete serve;
        }
        if (muffins.size() > 0) {
            muffins.pop_front();
        }
        if (bracelets.size() > 0) {
            bracelets.erase(bracelets.begin());
        }
        int rand_var = (int)(rand() % 100);
        if ((int)(rand() % 100) > 49) {
            int curr_idx = 0;
            for(const auto& order_pair : orders) { 
                if (curr_idx < cnt_coffee) {
                    curr_idx++;
                    continue;
                }
                else {
                    cnt_coffee++;
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
        if ((int)(rand() % 100) > 49) {
            int curr_idx = 0;
            for(const auto& order_pair : orders) { 
                if (curr_idx < cnt_muffins) {
                    curr_idx++;
                    continue;
                }
                else {
                    cnt_muffins++;
                }
                int name_extracted = 0;
                muffins.push_back(order_pair);
                break;
            }
        }
        if ((int)(rand() % 100) > 49) {
            int curr_idx = 0;
            for(const auto& order_pair : orders) { 
                if (curr_idx < cnt_muffins) {
                    curr_idx++;
                    continue;
                }
                else {
                    cnt_muffins++;
                }
                int name_extracted = 0;
                muffins.push_back(order_pair);
                break;
            }
        }
        Coffee* temp = head;
        cout << "\nCoffee Queue: " << endl;
        while(temp != nullptr) {
            cout << temp->name << "  " << temp->order << endl;
            temp = temp->next;
        }
        cout << "\nMuffins Queue: " << endl;
        for(const auto& pair: muffins) {
            for (auto it = pair.begin(); it != pair.end(); it++) {
                cout << *it << "  ";
            }
            cout << endl;
        }
        cout << "\nBracelet Queue: " << endl;
        for(const auto& pair: bracelets) {
            for (auto it = pair.begin(); it != pair.end(); it++) {
                cout << *it << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
}