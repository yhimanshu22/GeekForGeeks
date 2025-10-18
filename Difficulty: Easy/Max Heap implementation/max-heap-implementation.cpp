#include <vector>
#include <algorithm>
using namespace std;

class maxHeap {
private:
    vector<int> heap;

    // Heapify up after insertion
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else break;
        }
    }

    // Heapify down after removal
    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else break;
        }
    }

public:
    // Insert element into heap
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    // Remove top element (maximum)
    void pop() {
        if (heap.empty()) return;
        swap(heap[0], heap.back());
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    // Return top element or -1 if empty
    int peek() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    // Return number of elements
    int size() {
        return heap.size();
    }
};
