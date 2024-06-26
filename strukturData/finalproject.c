#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 10

typedef struct {
        char item[10];
        int qty;
        float prc;
} orderItem;

typedef struct {
    char orderId[10];
    time_t timestamp;
    orderItem items[MAX_ITEMS]
    int itemCount;
} orderData;

int nextOrderID = 0;

char* getTimestampString(time_t timestamp) {
    char* buffer = malloc(sizeof(char) * 20);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", localtime(&timestamp));
    return buffer;
}

orderData createOrder() {
    orderData order;
    order.orderId = nextOrderId++;
    order.timestamp = time(NULL);
    order.itemCount = 0;
    return order;
}

void addItemToOrder(Order *order, const char *name, int quantity, double price) {
    if (order->itemCount < MAX_ITEMS) {
        OrderItem item;
        snprintf(item.name, sizeof(item.name), "%s", name);
        item.quantity = quantity;
        item.price = price;
        order->items[order->itemCount++] = item;
    } else {
        printf("Cannot add more items to the order. Maximum limit reached.\n");
    }
}

int main() {
    
}