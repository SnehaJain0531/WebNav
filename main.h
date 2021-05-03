typedef struct Node Node;
typedef struct 
{
    char webpage[32];
    struct Node *next; // Pointer to next node
    struct Node *prev; // Pointer to previous node
};
int menu(Node** start);
