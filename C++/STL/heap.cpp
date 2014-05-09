#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> max_heap;
priority_queue< int, vector<int>, greater<int> > min_heap;

void init();

int main()
{
    init();
    cout << "max" << "\t" << "min"  << endl;
    cout << max_heap.top() << "\t" << min_heap.top() << endl;
    max_heap.pop();
    min_heap.pop();
    cout << max_heap.top() << "\t" << min_heap.top() << endl;
    max_heap.pop();
    min_heap.pop();
    cout << max_heap.top() << "\t" << min_heap.top() << endl;
    max_heap.pop();
    min_heap.pop();

}

void init() {
    max_heap.push(6);
    max_heap.push(5);
    max_heap.push(7);

    min_heap.push(6);
    min_heap.push(5);
    min_heap.push(7);
}
