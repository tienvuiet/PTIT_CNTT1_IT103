    #include <stdio.h>
    #include <stdlib.h>
    typedef struct Node
    {
        int data;
        struct Node *next;
        struct Node *prev;

    } Node;
    Node *createNode(int data)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
    void printList(Node *head)
    {
        Node *current = head;
        printf("NULL <- ");
        while (current != NULL)
        {
            printf("%d", current->data);
            if (current->next != NULL)
            {
                printf(" <-> ");
            }
            else
            {
                printf(" -> NULL\n");
            }
            current = current->next;
        }
    }
    int lengthList(Node *head)
    {
        Node *current = head;
        int length = 0;
        while (current != NULL)
        {
            length++;
            current = current->next;
        }
        return length;
    }
    Node *insertHead(Node *head, int data)
    {
        Node *current = createNode(data);
        current->next = head;
        if (head != NULL)
        {
            head->prev = current;
        }

        return head;
    }
    Node *insertEnd(Node *head, int data)
    {
        Node *node = createNode(data);
        if (head == NULL)
        {
            return head;
        }
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = node;
        node->prev = current;
        return head;
    }
    Node *insertAt(Node *head, int data, int index)
    {
        if (index > lengthList(head) || index < 0)
        {
            return head;
        }
        if (index == lengthList(head))
        {
            return insertEnd(head, data);
        }
        if (index == 0)
        {
            return insertHead(head, data);
        }
        Node* current = head;
        for(int i =0 ; i< index; i++){
            current = current->next;
        }
        Node* node = createNode(data);
        Node* prev = current ->prev;

        node->next = current;
        current->prev = node;

        prev->next = node;
        node->prev = prev;
        return head;
    }


    int main()
    {
        Node *head = createNode(10);
        Node *node2 = createNode(20);
        Node *node3 = createNode(30);

        head->next = node2;
        node2->prev = head;
        node2->next = node3;
        node3->prev = node2;

        printList(head);
        int n ;
        printf("nhap vao phan tu muon chen: \n");
        scanf("%d", &n);
        int index;
        printf("nhap vao gia tri index muon chen: \n");
        scanf("%d", &index);
        head = insertAt(head, n, index);
        printList(head);
        return 0;
    }