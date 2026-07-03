/*
 * PLAN
 * ----
 * Data design:
 *   Item represents one node in the stack. It stores a double value and a
 *   pointer to the Item beneath it. Stack stores a pointer to the top Item
 *   and an integer size. When the stack is empty, top == nullptr and size == 0.
 *
 * push():
 *   - Allocate a new Item using new.
 *   - Set its value to the number being pushed.
 *   - Set its next pointer to the current stack->top.
 *   - Update stack->top to point to the new Item.
 *   - Increment stack->size.
 *
 * pop():
 *   - If the stack is empty, do nothing.
 *   - Otherwise:
 *       * Save the current top pointer in a temporary variable.
 *       * Move stack->top to the next item.
 *       * Delete the old top.
 *       * Decrement size.
 *
 * Edge cases:
 *   - top(): If empty, return HUGE_VAL.
 *   - pop(): If empty, do nothing.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Item {
    double value;
    Item* next;
};

struct Stack {
    Item* top;
    int size;
};

void push(Stack* stack, double num) {
    Item* item = new Item;
    item->value = num;
    item->next = stack->top;
    stack->top = item;
    stack->size++;
}

double top(Stack* stack) {
    if (stack->top == nullptr)
        return HUGE_VAL;
    return stack->top->value;
}

void pop(Stack* stack) {
    if (stack->top == nullptr)
        return;

    Item* oldTop = stack->top;
    stack->top = oldTop->next;
    delete oldTop;
    stack->size--;
}

void print(Stack* stack) {
    cout << setw(12) << "----------" << endl;

    Item* current = stack->top;
    while (current != nullptr) {
        cout << setw(12) << current->value;
        if (current == stack->top)
            cout << " < TOP";
        cout << endl;
        current = current->next;
    }

    cout << setw(12) << "----------" << endl;
    cout << setw(12) << stack->size << " ITEMS" << endl;
}

int main() {
    Stack s;
    s.top = nullptr;
    s.size = 0;

    push(&s, 20.5);
    push(&s, 60.004);
    push(&s, 10.08);
    push(&s, 40.3);
    push(&s, -160.93);

    print(&s);
    cout << endl;

    pop(&s);
    print(&s);
    cout << endl;

    while (s.size > 0)
        pop(&s);

    print(&s);
    cout << endl;

    push(&s, 5.5);
    push(&s, 99.99);
    push(&s, -42.0);

    print(&s);

    return 0;
}