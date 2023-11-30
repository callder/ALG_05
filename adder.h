#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node {
public:
    Node* prev;
    Node* next;
    int key;
    T data;

    Node(T val, int k) {
        key = k;
        data = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

template <class T>
class LinkedList {
public:
    Node<T>* node_head;
    Node<T>* node_tail;
    int size = 0;

    void add(T s, int key) {
        Node<T>* newNode = new Node<T>(s, key);

        if (node_head == nullptr) {
            node_head = newNode;
            node_tail = newNode;
            ++size;
            return;
        }

        newNode->next = node_head;
        node_head->prev = newNode;
        node_head = newNode;
    }
};

template <class T>
class HashedArray {
public:
    int size;
    LinkedList<T>** basket;
    float increaseCoef = 1.5;
    int length;

    HashedArray() {
        size = 10;
        basket = new LinkedList<T>*[10];
        for (int i = 0; i < size; ++i) {
            basket[i] = new LinkedList<T>();
        }
        length = 0;
    }

    bool sizeInspector() {
        return size * 0.9 < length;
    }

    void sizeIncrease() {
        int newSize = static_cast<int>(size * increaseCoef);

        LinkedList<T>** newArray = new LinkedList<T>*[newSize];
        for (int i = 0; i < newSize; ++i) {
            newArray[i] = new LinkedList<T>();
        }

        for (int i = 0; i < size; ++i) {
            if (basket[i]->node_head != nullptr) {
                while (basket[i]->node_head != nullptr) {
                    T data = basket[i]->node_head->data;
                    int key = hashString(data);
                    if (newArray[key] == nullptr) {
                        newArray[key] = new LinkedList<T>();
                    }
                    newArray[key]->add(data, key);

                    basket[i]->node_head = basket[i]->node_head->next;
                }
                delete basket[i];
            }
        }

        delete[] basket;
        size = newSize;
        basket = newArray;
    }

    int hashString(T s) {
        int q = 31;
        int hash = 0;
        int length = s.length();

        for (int i = 0; i < length; ++i) {
            hash = q * hash + s.at(i);
        }
        hash = hash & 0x7FFFFFFF;
        hash = hash % size;
        return hash;
    }

    void add(T s) {
        if (size == 0) {
            basket = new LinkedList<T>*[10];
            for (int i = 0; i < 10; ++i) {
                basket[i] = new LinkedList<T>();
            }
            size = 10;
        }
        if (sizeInspector()) sizeIncrease();
        int key = hashString(s);
        basket[key]->add(s, key);
        length++;
    }

    void show() {
        for (int i = 0; i < size; ++i) {
            if (basket[i]->node_head != nullptr) {
                Node<T>* currentNode = basket[i]->node_head;
                while (currentNode != nullptr) {
                    cout << currentNode->data << '\t';
                    cout << currentNode->key << endl;
                    currentNode = currentNode->next;
                }
            }
        }
    }

    void searchData(T data) {
        int key = hashString(data);
        int flag = 0;
        for (int i = 0; i < size; ++i) {
            if (basket[i]->node_head != nullptr) {
                Node<T>* currentNode = basket[i]->node_head;
                while (currentNode != nullptr) {
                    if (currentNode->key == key && currentNode->data == data) {
                        cout << "Wyszukiwanie: " << '\t';
                        cout << currentNode->data << '\t';
                        cout << currentNode->key << endl;
                        flag++;
                    }
                    currentNode = currentNode->next;
                }
            }
        }
        if (flag == 0) cout << "NULL" << endl;
    }

    void erase() {
        for (int i = 0; i < size; ++i) {
            if (basket[i]->node_head != nullptr) {
                Node<T>* currentNode = basket[i]->node_head;
                while (currentNode != nullptr) {
                    Node<T>* nextNode = currentNode->next;
                    delete currentNode;
                    currentNode = nextNode;
                }
            }

            delete[] basket[i];
        }
        delete[] basket;
        size = 0;
        length = 0;
    }
};