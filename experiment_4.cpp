#include <iostream>
using namespace std;

class MinHeap {
    int* heap;
    int size;

public:
    MinHeap(int capacity) {
        heap = new int[capacity];
        size = 0;
    }

    void insert(int value) {
        heap[size] = value;
        int current = size;
        size++;

        while (current > 0) {
            int parent = (current - 1) / 2;
            if (heap[current] < heap[parent]) {
                swap(heap[current], heap[parent]);
                current = parent;
            } else {
                break;
            }
        }
        cout << "Inserted " << value << endl;
    }

    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {
                cout << "Found " << value << " at index " << i << endl;
                return i;
            }
        }
        cout << value << " not found" << endl;
        return -1;
    }

    void deleteValue(int value) {
        int index = search(value);
        if (index == -1) return;

        size--;
        heap[index] = heap[size];

        int current = index;
        while (current < size) {
            int left = 2 * current + 1;
            int right = 2 * current + 2;
            int smallest = current;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != current) {
                swap(heap[current], heap[smallest]);
                current = smallest;
            } else {
                break;
            }
        }
        cout << "Deleted " << value << endl;
    }

    void display() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    ~MinHeap() {
        delete[] heap;
    }
};

int main() {
    MinHeap heap(100);
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                heap.insert(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                heap.search(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                heap.deleteValue(value);
                break;
            case 4:
                heap.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}