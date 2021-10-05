#include <vector>
#include <iostream>
#include <assert.h>

class LinkedList {
    public:
        LinkedList(std::vector<int> input) {
            root = tail = nullptr;
            for (int datum : input) {
                insert(datum);
            }
        }

        ~LinkedList() {
            while (root->next) {
                Node* temp = root->next;
                delete root;
                root = temp;
            }
            delete root;
        }

        void insert(int datum) {
            Node* node_ptr = new Node{nullptr, datum};
            if (root != nullptr) {
                tail->next = node_ptr;
                tail = node_ptr;
                return;
            }
            root = tail = node_ptr;
        }

        int search(int datum) {
            Node* iterator = root;
            int index = 0;
            while (iterator) {
                if (iterator->datum == datum) {
                    return index;
                }
                ++index;
                iterator = iterator->next;
            }
            return -1;
        }

    private:
        struct Node {
            Node* next;
            int datum;
        };
        Node* root;
        Node* tail;
};

int main(int argc, char** argv) {
    std::vector<int> input{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList list(input);
    assert(list.search(0) == 0);
    assert(list.search(5) == 5);
    assert(list.search(9) == 9);
    assert(list.search(100) == -1);
    exit(0);
}