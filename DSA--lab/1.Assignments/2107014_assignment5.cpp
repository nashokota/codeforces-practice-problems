#include "header_14.hpp"
using namespace std;

int main() {
    Deque<int> deque;
    Queue<int> queue;
    Stack<int> stack;

    deque.push_front(11);
    deque.push_back(22);
    deque.push_front(33);

    cout << "Deque: ";
    deque.display();
    cout << "Size: " << deque.size() << endl;

    deque.pop_front();
    deque.pop_back();

    cout << "Deque after pop: ";
    deque.display();
    cout << "Size: " << deque.size() << endl;

    queue.push(44);
    queue.push(55);
    queue.push(66);

    cout << "Queue: ";
    queue.display();
    cout << "Size: " << queue.size() << endl;

    queue.pop();

    cout << "Queue after pop: ";
    queue.display();
    cout << "Size: " << queue.size() << endl;

    stack.push(5);
    stack.push(15);
    stack.push(25);

    cout << "Stack: ";
    stack.display();
    cout << "Size: " << stack.size() << endl;

    stack.pop();

    cout << "Stack after pop: ";
    stack.display();
    cout << "Size: " << stack.size() << endl;

    return 0;
}
