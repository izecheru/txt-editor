#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node(T data_param) : data(data_param), left(nullptr), right(nullptr) {}
};

template <typename T>
void print(T value)
{
    if (typeid(T) == typeid(int))
    {
        printf("%d ", value);
    }
    if (typeid(T) == typeid(char))
    {
        printf("%c ", value);
    }
}

template <typename T>
void inorder(Node<T> *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        print(root->data);
        inorder(root->right);
    }
}

template <typename T>
void postorder(Node<T> *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        print(root->data);
    }
}
template <typename T>
Node<T> *insertNode(Node<T> *root, T value)
{
    Node<T> *new_node = new Node<T>(value);

    if (root->data < value)
    {
        root->right = insertNode(root->right, value);
    }
    else
    {
        root->left = insertNode(root->left, value);
    }
    return root;
}