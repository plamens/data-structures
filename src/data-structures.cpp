#include <iostream>
#include "treap/Treap.h"
using namespace std;

int main() {
    Treap t;
    cout << t.containsKey(4) << endl;

    for (int i = 0; i < 1024*1024; i++) {
        t.insert(i);
    }
    cout << "treap? " << t.isTreap() << endl;

    cout << t.containsKey(1024*1024) << endl;
    cout << t.containsKey(8) << endl;

    for (int i = 20; i < 1024*1024; i += 2) {
        t.remove(i);
    }
    for (int i = 11; i < 1024*1024; i += 2) {
        t.remove(i);
    }
    cout << "treap? " << t.isTreap() << endl;

    cout << t.containsKey(12) << endl;
    cout << t.containsKey(13) << endl;

    t.print();
    cout << t.height() << endl;
    return 0;
}
