#include <stdio.h>
#include <stdlib.h>

typedef struct Mark
{
    int mark;
    struct Mark *next;
} Mark;

typedef struct
{
    char name[256];
    int age;
    Mark marks;
} Student;

typedef struct Node
{
    Student val_student;
    struct Node *next;
} Node;

void popBack(Node **head);
Node* getLastStudent(Node *head);
Mark* getLastMark(Mark *head);
void pushMark(Mark **head, int data);
void pushStudent(Node **head_node, Mark **head_mark,  char *name, int age, int mark);
void pushBackMark(Mark *head, int value);
void popBack(Node **head);


Node* getLastStudent(Node *head)
{
    while (head->next)
    {
        head = head->next;
    }
    return head;
}

Mark* getLastMark(Mark *head)
{
    while (head->next)
    {
        head = head->next;
    }
    return head;
}

void pushMark(Mark **head, int data)
{
    Mark *tmp = (Mark *)malloc(sizeof(Mark));
    tmp->mark = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void pushStudent(Node **head_node, Mark **head_mark,  char *name, int age, int mark)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    sprintf(tmp->val_student.name, "%s", name);
    //tmp->val_student.name, name;
    tmp->val_student.age = age;
    pushMark(head_mark, mark);
    tmp->val_student.marks = (**head_mark);
    tmp->next = (*head_node);
    (*head_node) = tmp;
}

void pushBackStudent(Node *head_node, Mark *head_mark, char *name, int age, int mark)
{
    Node *last = getLastStudent(head_node);

    Node *tmp = (Node *)malloc(sizeof(Node));

    sprintf(tmp->val_student.name, "%s", name);
    tmp->val_student.age = age;
    pushBackMark(head_mark, mark);
    tmp->val_student.marks = (*head_mark);

    tmp->next = NULL;

    if (last)
    {
        last->next = tmp;
    }
}

void pushBackMark(Mark *head, int value)
{
    Mark *last = getLastMark(head);

    Mark *tmp = (Mark *)malloc(sizeof(Node));
    tmp->mark = value;
    tmp->next = NULL;

    if (last)
    {
        last->next = tmp;
    }
}

void popBack(Node **head)
{
    Node *Fwd = NULL;  //текущий
    Node *Bwd = NULL;  //предыдущий

    if ((*head))
    {
        Fwd = *head;
        while (Fwd->next)
        {
            Bwd = Fwd;
            Fwd = Fwd->next;
        }

        if (Bwd == NULL)
        {
            free(&((*head)->val_student.marks));
            free(*head);
            *head = NULL;
        }
        else
        {
            free(Fwd->next);
            Bwd->next = NULL;
        }
    }
}

void printList(Node *headNode, Mark *headMark)
{
    while(headNode->next)
    {
        printf("%s ", headNode->val_student.name);
        printf("%d ", headNode->val_student.age);
        printf("%d ", headMark->mark);
        printf("\n");
        headNode = headNode->next;
        headMark = headMark->next;

    }

    if (headNode->next == NULL)
    {
        printf("%s ", headNode->val_student.name);
        printf("%d ", headNode->val_student.age);
        printf("%d ", headMark->mark);
        printf("\n");
    }
}


int main()
{

    Node *headNode = NULL;
    Mark *headMark = NULL;

    int age;
    char name[256];
    int mark;

    int choise = 0;
    int flag = 0;

    printf("1 - push back;\n2 - pop back;\n3 - print;\n");

    while (scanf("%d", &choise))
    {
        switch (choise)
        {
            case 1:
                if (flag)
                {
                    scanf("%s %d %d", name, &age, &mark);
                    pushBackStudent(headNode, headMark, name, age, mark);
                }
                else
                {
                    flag = 1;
                    scanf("%s %d %d", name, &age, &mark);
                    pushStudent(&headNode, &headMark,  name, age, mark);
                }
                break;

            case 2:
                if (flag)
                    popBack(&headNode);
                else
                    printf("empty");
                break;

            case 3:
                if (flag)
                    printList(headNode, headMark);
                else
                    printf("empty");
                break;

            default:
                printf("input error");
                break;
        }

        fflush(stdin);
    }

    return 0;
}
