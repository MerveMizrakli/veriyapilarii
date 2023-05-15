#include <stdio.h>
#include <stdlib.h>

// Kuyruk düðümü
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL; // Kuyruðun önü
struct Node* rear = NULL;  // Kuyruðun sonu

// Eleman ekleme
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    
    printf("Eleman eklendi: %d\n", value);
}

// Eleman silme
void dequeue() {
    if (front == NULL) {
        printf("Kuyruk bos!\n");
    } else {
        struct Node* temp = front;
        front = front->next;
        
        if (front == NULL) {
            rear = NULL;
        }
        
        printf("Eleman silindi: %d\n", temp->data);
        free(temp);
    }
}

// Kuyruðu görüntüleme
void display() {
    if (front == NULL) {
        printf("Kuyruk boþ!\n");
    } else {
        struct Node* temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("1. Eleman Ekle\n");
        printf("2. Eleman Sil\n");
        printf("3. Kuyruguu Goruntule\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Eklenecek elemani girin: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program sonlandiriliyor...\n");
                exit(0);
            default:
                printf("Gecersiz secim!\n");
        }
        
        printf("\n");
    }
    
    return 0;
}


