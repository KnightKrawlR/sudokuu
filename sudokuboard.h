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

#ifndef SUDOKU
#define SUDOKU

#include <iostream>
#include <cstdlib>
using namespace std;

class SudokuBoard {
 public:
  typedef char Type;
  SudokuBoard();

  void place(int r, int c, Type n); // Place number n at position (r,c)
  void print() const;// Write the board to cout
  int get(int r, int c) const; // return the numeral at position (r,c)
  void remove(int r, int c); // remove the numeral position (r,c)
  bool canPlace(int r, int c, Type n) const; // true if the board allows 
                                             //placing n @ (r,c)
  bool empty(int r, int c) const; // returns true if cell is empty
  bool solved() const; // true if no blanks spots on the board

 private:
  string rows[9];
};
  
# endif
