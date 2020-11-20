// Node struct
struct Node {
    int data;
    struct Node* next;
};

// LinkedList struct
// usage: struct LinkedList list = {NULL, NULL, 0};
struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int size;
};


// function declarations
struct Node* push(int data, struct LinkedList* list);
void print(struct LinkedList* list);
int size(struct LinkedList* list);
int peek(int position, struct LinkedList* list);
struct Node* insert(int data, int position, struct LinkedList* list);


// push function
// usage: push(1, &list);
struct Node* push(int data, struct LinkedList* list) {
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

// print function
// usage: print(&list);
void print(struct LinkedList* list) {
    struct Node* ptr = list->head;
    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// size function
// usage: size(&list);
int size(struct LinkedList* list) {
    return list->size;
}

// peek function
// usage: peek(1, &list);
int peek(int position, struct LinkedList* list) {
    struct Node* ptr = list->head;
    for (int i=0; i<position; i++) {
        ptr = ptr->next;
    }
    return ptr->data;
}

// push function
// usage: insert(1, 1, &list);
struct Node* insert(int data, int position, struct LinkedList* list) {
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