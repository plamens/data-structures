#include <iostream>
#include "treap/Treap.h"
using namespace std;

int main() {
    Treap t;
    cout << t.containsKey(4) << endl;
    t.insert(10);
    t.insert(8);
    t.insert(1);
    t.insert(3);
    t.insert(15);
    t.insert(7);
    t.insert(5);
    t.insert(12);
    t.insert(16);
    t.insert(11);
    t.print();
    t.insert(9);

    cout << t.containsKey(4) << endl;
    cout << t.containsKey(8) << endl;
    cout << t.containsKey(15) << endl;
    cout << t.containsKey(5) << endl;
    t.print();
    return 0;
}
