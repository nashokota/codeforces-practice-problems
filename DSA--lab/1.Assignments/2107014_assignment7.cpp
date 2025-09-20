#include <vector>
#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Comparator = std::less<T>>
class PriorityQueue
{
public:
    PriorityQueue() {}

    T top() const
    {
        return heap[0];
    }

    bool empty() const
    {
        return heap.empty();
    }

    size_t size() const
    {
        return heap.size();
    }

    void push(const T &value)
    {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    T pop()
    {
        if (empty())
        {
            throw std::runtime_error("Cannot pop from an empty queue");
        }
        T topElement = heap[0];
        std::swap(heap[0], heap.back());
        heap.pop_back();
        siftDown(0);
        return topElement;
    }

private:
    std::vector<T> heap;
    Comparator comp;

    void siftUp(size_t index)
    {
        while (index > 0)
        {
            size_t parent = (index - 1) / 2;
            if (comp(heap[parent], heap[index]))
            {
                break;
            }
            std::swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void siftDown(size_t index)
    {
        size_t size = heap.size();
        while (index < size)
        {
            size_t leftChild = 2 * index + 1;
            size_t rightChild = 2 * index + 2;
            size_t smallest = index;

            if (leftChild < size && comp(heap[leftChild], heap[smallest]))
            {
                smallest = leftChild;
            }
            if (rightChild < size && comp(heap[rightChild], heap[smallest]))
            {
                smallest = rightChild;
            }

            if (smallest == index)
            {
                break;
            }
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }
};
int main()
{

    PriorityQueue<int> pq;

    int choice;
    while (true)
    {
        cout << "Select an operation:" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Get top element" << endl;
        cout << "4. Get size" << endl;
        cout << "5. Check if empty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter the element to push: ";
            cin >> value;
            pq.push(value);
            cout << "Element pushed successfully" << endl;
            break;
        }
        case 2:
        {
            if (pq.empty())
            {
                cout << "Priority queue is empty" << endl;
            }
            else
            {
                int poppedElement = pq.pop();
                cout << "Element " << poppedElement << " popped successfully" << endl;
            }
            break;
        }
        case 3:
        {
            if (pq.empty())
            {
                cout << "Priority queue is empty" << endl;
            }
            else
            {
                cout << "Top element: " << pq.top() << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Size: " << pq.size() << endl;
            break;
        }
        case 5:
        {
            if (pq.empty())
            {
                cout << "Priority queue is empty" << endl;
            }
            else
            {
                cout << "Priority queue is not empty" << endl;
            }
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}