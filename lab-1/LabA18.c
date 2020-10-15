#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// ��������� �������� ������.
typedef struct LNode
{
    // ��������� �� ASCIIZ ������.
    char* data;
    // ��������� �� ��������� ������� ������.
    struct LNode* next;
} LNode;

// �������� ������� � ������.
void push(LNode** head, char* data)
{
    LNode* tmp;

    if (tmp = (LNode*)malloc(sizeof(LNode)))
    {
        tmp->data = data;
        tmp->next = (*head);
    }

    (*head) = tmp;
}

// �������� ������.
LNode* freeList(LNode* head)
{
    LNode* curr = head->next;

    while (curr)
    {
        LNode* tmp = curr;
        curr = curr->next;
        free(tmp->data);
        free(tmp);
    }

    free(head->data);
    head->next = NULL;

    return head;
}


// ���������� ������ ������� �������. ������� ���������� ��������� �� ������ ���������������� ������.
LNode* sort(LNode* head)
{
    LNode* a;
    LNode* b;
    LNode* c;
    LNode* res = NULL;

    // ���� �� ���� ������.
    while (head != NULL)
    {
        a = head; head = head->next;

        // ����� ����� �������.
        for (b = res, c = NULL; b != NULL && strcmp(a->data, b->data) > 0; c = b, b = b->next);

        // ��������� ����� ������.
        if (c == NULL)
        {
            a->next = res;
            res = a;
        }
        // ��������� ����� �����������.
        else
        {
            a->next = b;
            c->next = a;
        }
    }

    return res;
}



// ����� ��������� ������.
void printList(const LNode* head)
{
    if (head == NULL)
        return;

    while (head->next)
    {
        printf("%s -> ", head->data);
        head = head->next;
    }

    printf("%s", head->data);

    printf("\n");
}


int main(int argc, char* argv[])
{
    LNode* head = NULL;

    push(&head, "abbbbcd");
    push(&head, "bcb");
    push(&head, "bnbb");
    push(&head, "ggfds");
    push(&head, "ggsd");
    push(&head, "ccaa");

    puts("The Initial List:");
    printList(head);

    head = sort(head);
    puts("The Sorted List:");
    printList(head);

    getch();

    return 0;
}
