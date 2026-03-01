#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
};

bool compare(Item a, Item b) {
    return (double)a.value/a.weight >
           (double)b.value/b.weight;
}

int main() {
    vector<Item> items = {{10,60},{20,100},{30,120}};
    int capacity = 50;

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for(auto &item : items) {
        if(capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value *
                         ((double)capacity/item.weight);
            break;
        }
    }

    cout << "Maximum value: " << totalValue << endl;
    return 0;
}
