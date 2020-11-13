// structs
struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int size;
};


// function declaration
struct Node* add(int data, struct LinkedList* list);
void print(struct LinkedList* list);
int size(struct LinkedList* list);
int peek(int position, struct LinkedList* list);


// add method
struct Node* add(int data, struct LinkedList* list) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!list->head) {
        list->head = newNode;
        list->head->data = data;
        list->head->next = NULL;
        list->tail = list->head;
    } else {
        newNode->data = data;
        newNode->next = NULL;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size += 1;
    return list->tail;
}

// print method
void print(struct LinkedList* list) {
    struct Node* ptr = list->head;
    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// size method
int size(struct LinkedList* list) {
    return list->size;
}

// peek method
int peek(int position, struct LinkedList* list) {
    struct Node* ptr = list->head;
    for (int i=0; i<position; i++) {
        ptr = ptr->next;
    }
    return ptr->data;
}

// push method
struct Node* push(int data, int position, struct LinkedList* list) {
    if (position <= list->size) {
        struct Node* previous;
        struct Node* current = list->head;
        for (int i=0; i<position; i++) {
            previous = current;
            current = current->next;
        }
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = current;
        if (position == 0) {
            list->head = newNode;
        } else {
            previous->next = newNode;
        }
        list->size += 1;
        return newNode;
    } else {
        return NULL;
    }
}
