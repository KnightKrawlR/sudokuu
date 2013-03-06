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
                                                                      

#include <cstdlib>
#include <cassert>
#include "stack.h" 
using namespace std;

Stack::Stack()
{
  top = NULL;
}

bool Stack::empty()
{
  return top == NULL;
}

void Stack::push(Stack::Type item)
{
  Node * newTop = new Node;
  newTop->data = item;
  newTop->next = top;
  top = newTop;
}

Stack::Type Stack::pop()
{
  assert(!empty());
  Type x = top->data;
  Node *oldTop = top;
  top = top->next;
  delete oldTop;
  return x;
}
