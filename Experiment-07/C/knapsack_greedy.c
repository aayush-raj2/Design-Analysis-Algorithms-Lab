#include <stdio.h>

struct Item {
    int weight;
    int value;
};

float max(float a, float b) {
    return (a > b) ? a : b;
}

int main() {
    struct Item items[] = {{10,60},{20,100},{30,120}};
    int n = 3;
    int capacity = 50;

    float totalValue = 0.0;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            float r1 = (float)items[i].value/items[i].weight;
            float r2 = (float)items[j].value/items[j].weight;
            if(r2 > r1){
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(capacity >= items[i].weight){
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value *
                          ((float)capacity/items[i].weight);
            break;
        }
    }

    printf("Maximum value: %.2f\n", totalValue);
    return 0;
}
