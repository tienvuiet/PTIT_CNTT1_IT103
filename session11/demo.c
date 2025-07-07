#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
//them vao gan cuoi
//them vao gan dau

//in nguoc list
Node *createNode(int data)
{
    // b1: cap phat bo nho cho 1 node
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void printList(Node *head)
{
    printf("NULL <- ");
    Node *current = head;
    // Bạn không muốn mất địa chỉ nhà (tức là head), nên bạn tạo một bản sao địa chỉ (current) để đi dạo, trong khi vẫn giữ nguyên địa chỉ gốc head.
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" <-> ");
        }

        current = current->next;
    }
    printf(" -> NULL\n");
}
// lay ra toan bo phan tu get all
int getLength(Node *head)
{
    Node *current = head;
    int length = 0;
    while (current != NULL)
    {
        current = current->next;
        length++;
    }
    return length;
}

// lay ra 1 phan tu get one
Node *getOne(Node *head, int index)
{
    // b1: kiem tra xem gia tri index hop le
    if (index < 0 || index > getLength(head))
    {
        return NULL;
    }
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current;
}
Node *insertHead(Node *head, int data)
{
    // b1: tao node moi
    Node *node = createNode(data);
    // b2: lien ket node moi ->head
    node->next = head;
    // b3: lien ket node head ->node moi
    if (head != NULL)
    {
        head->prev = node;
    }
    // b4: tra ve node moi lam head cua dslk
    return node;
}

// them vao vi tri cuoi cung
Node *insertEnd(Node *head, int data)
{
    // b1: tao ra node moi
    Node *node = createNode(data);
    // b2: kiem tra neu danh sach rong tra ve node moi
    if (head == NULL)
    {
        return node;
    }
    // b3: lay ra thong tin cua node tail(cuoi cung)
    // bang vc duyet tu node head
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    // b4: tao ra su lien ket giua node cuoi(tail)<-> node moi
    current->next = node;
    node->prev = current;
    return head;
}

// them node vao vi tri bat ki
Node *insertAt(Node *head, int data, int index)
{
    // b1: kiem tra index co hop le ko
    if (index < 0 || index > getLength(head))
    {
        printf("index loi");
        return head;
    }
    if (index == 0)
    {
        return insertHead(head, data);
    }
    if (index == getLength(head))
    {
        return insertEnd(head, data);
    }
    // b4: duyet den vi tri node can chen
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    // b5: tao moi 1 node
    Node *node = createNode(data);
    Node *prev = current->prev;
    // tao ra su lien ket giua
    // node<->sau no: current

    node->next = current;
    current->prev = node;
    // node<-> truoc no:prev
    prev->next = node;
    node->prev = prev;
    return head;
}

// xoa node dau tien
Node *removeHead(Node *head)
{
    // b1: kiem tra dslk co trong ko
    if (head == NULL)
    {
        return NULL;
    }
    // b2: luu node muon xoa vao tam
    Node *temp = head;
    // b3: cho node canh head thanh node moi
    head = head->next; // co the null
    // b4: kiem tra neu node head co nhieu hon 1 phan tu
    if (head != NULL)
    {
        head->prev = NULL;
    }
    // giai ohong
    free(temp);
    return head;
}
// xoa cuoi
Node *removeEnd(Node *head)
{
    // b1: neu danh sach lien ket rong
    if (head == NULL)
    {
        return NULL;
    }
    // b2: kt dslk co 1 ptu ko
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    // b3: lay thong tin node cuoi cung
    // duyet tu head->
    Node *current = head;
    while (current->next != NULL)
    //neu thay current!= NULL thi no vuot qua node cuoi roi 
    {
        current = current->next;
    }
    // cap nhap lai node ke cuoi tro next toi null
    current->prev->next = NULL;
    // giai phong node cuoi cu
    free(current);
    return head;
}
// xoa bat ki
Node *removeAt(Node *head, int index)
{
    // b1: kt index
    if (index < 0 || index > getLength(head) - 1)
    {
        printf("index ko hop le");
        return head;
    }
    if (index == 0)
    {
        removeHead(head);
    }
    if (index == getLength(head) - 1)
    {
        removeEnd(head);
    }
    // b3:duyet den vi tri index de xoa node do
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    // b4: lay ra thong tin cua node dang truoc current
    Node *prev = current->prev;
    // b5: lay ra thong tin cua node dang sau current
    Node *next = current->next;
    // b6: luu tru thong tin cua node can xoa vao 1 bien tam
    Node *temp = current;
    // b7: cap nhat lai lien ket prev<->
    prev->next = next;
    next->prev = prev;

    // b8: xoa temp
    free(temp);
    return head;
}
int main()
{
    Node *head = createNode(10);
    Node *note2 = createNode(20);
    Node *note3 = createNode(30);   

    head->next = note2;
    note2->prev = head;

    note2->next = note3;
    note3->prev = note2;
    printList(head);
    int length = getLength(head);
    printf("%d", length);
    Node *findNode = getOne(head, 1);
    printf("\nNode1: %d\n", findNode->data);

    // them node vao dau cau danh sach lien ket
    head = insertHead(head, 91);
    head = insertHead(head, 19);
    printList(head);

    // them node vao vi tri cuoi cung
    head = insertEnd(head, 23);
    printList(head);

    // them node vao bat ki
    head = insertAt(head, 38, 3);   
    printList(head);

    // xoa dau
    head = removeHead(head);
    head = removeHead(head);
    printList(head);

    // xoa cuoi
    head = removeEnd(head);
    printList(head);

    // xoa bat ki
    head = removeAt(head, 2);
    printList(head);
    return 0;
}