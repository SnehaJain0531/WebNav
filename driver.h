typedef struct Node
{
    char webpage[32];
    struct Node *next; // Pointer to next node
    struct Node *prev; // Pointer to previous node
}Node;
Node * getNode(char *);
Node * insert(Node* );
Node * delete(Node* );
void intro();
void display(Node* );
void destroy(Node* );
void search(Node* );
int main();
