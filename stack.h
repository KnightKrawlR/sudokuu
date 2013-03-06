/*************************************************************************** 
 * Wlajimir Alexis                                                         *  
 *                                                                         *  
 * Lab #3                                                                  *  
 *                                                                         *  
 * Files:  sudoku.cc sudokuboard.h sudokuboard.cc stack.h stack.cc Makefile*  
 *                                                                         *  
 * This lab solves Sudoku Puzzles using Stacks as the storage device to    *  
 * maintain a backtracking system.                                         *  
 */                                                                          

#ifndef STACK
#define STACK

class Stack {
 public:
  typedef char Type;
  Stack();
  // push
  // PRE: this stack contains:  <v1,v2,...,vn>  (possibly empty)
  // POST: this stack contains: <item,v1,v2,...,vn>
  void push(Type item);

  // pop
  // PRE: this stack contains:  <v0,v1,v2,....,vn> and !empty()
  // POST: this stack constains: <v1,v2,...,vn>
  //       and v0 is returned.
  Type pop();

  // empty
  // PRE: none
  // POST: returns true if and only if there are no items on the stack.
  bool empty();

 private:
  struct Node {
    Type data;
    Node * next;
  };
  
  Node * top; // point to the top of the stack
};

#endif
