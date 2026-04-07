
#ifndef LSTACK_H
#define LSTACK_H

#include <string>
using namespace std;

inline void Assert(bool val, string s);

// Include the link class
#include "link.h"

// First, get the declaration for the base stack class
#include "stack.h"

// This is the declaration for LStack.
// Linked stack implementation
template <typename E> class LStack: public Stack<E> {
private:
  Link<E>* top;            // Pointer to first element
  int size;                   // Number of elements

  //COMMENT: RISPETTO ALLO STACK ASTRATTO IN CUI ABBIAMO IL TOP IN FONDO (IN BASSO), QUI è COME SE ANDASSE DA SINISTRA VERSO DESTRA

public:
  LStack()                        // Constructor
    { top = NULL; size = 0; }

  ~LStack() { clear(); }          // CLEAR E DISTRUTTORE SONO PRATICAMENTE LA STESSA COSA (RICHIAMA CLEAR)

  void clear() {                  // RIPORTA ALLO STATO DI LISTA VUOTA
    while (top != NULL) {         // Delete link nodes
      Link<E>* temp = top;
      top = top->next;
      delete temp;
    }
    size = 0;
  }

  void push(const E& it) { // Put "it" on stack
    top = new Link<E>(it, top);
    size++;
  }

  E pop() {                // Remove "it" from stack
    Assert(top != NULL, "Stack is empty");
    E it = top->element;
    Link<E>* ltemp = top->next;
    delete top;
    top = ltemp;
    size--;
    return it;
  }

  const E& topValue() const { // Return top value
    Assert(top != 0, "Stack is empty");
    return top->element;
  }

  int length() const { return size; } // Return length
};

#endif