#include <iostream>
using namespace std;

typedef int Info;
struct Node
{
    Node* left,
        * right;
    Info info_num;
    string info_word;
};

Node* CreateTree(int nodeCount);
void PrintTree(Node* root, int level);
void InfixOrder(Node* root, Node** maxNode);
Node* SearchMax(Node* root);

int main()
{
    int N;
    cout << "\n Enter nodes count: "; cin >> N;

    Node* root = CreateTree(N);
    cout << "\n --------------\n ";
    PrintTree(root, 0);

    cout << "\n InfixOrder: ";
    Node* maxNode = NULL;
    InfixOrder(root, &maxNode); cout << endl;

    if (maxNode != NULL)
    {
        cout << "\nMax node: " << maxNode->info_num << maxNode->info_word << endl;
    }
    else
    {
        cout << "\n Tree is empty!" << endl;
    }

    return 0;
}

Node* CreateTree(int nodeCount)
{
    if (nodeCount == 0)
        return NULL;
    else
    {
        Node* newNode = new Node;

        cout << "\n Enter node number and then word: ";
        cin >> newNode->info_num; cin >> newNode->info_word;

        int leftCount = nodeCount / 2;
        int rightCount = nodeCount - leftCount - 1;

        newNode->left = CreateTree(leftCount);
        newNode->right = CreateTree(rightCount);

        return newNode;
    }
}

void PrintTree(Node* root, int level)
{
    if (root != NULL)
    {
        PrintTree(root->right, level + 1);
        for (int i = 1; i <= level; i++)
            cout << "  ";
        cout << root->info_num << root->info_word << endl;
        PrintTree(root->left, level + 1);
    }
}

void InfixOrder(Node* root, Node** maxNode)
{
    if (root != NULL)
    {
        cout << root->info_num << root->info_word << " ";

        InfixOrder(root->left, maxNode);

        if (*maxNode == NULL || root->info_num > (*maxNode)->info_num)
        {
            *maxNode = root;
        }
        InfixOrder(root->right, maxNode);
    }
}


Node* SearchMax(Node* root)
{
    Node* maxNode = NULL;
    InfixOrder(root, &maxNode);
    return maxNode;
}
