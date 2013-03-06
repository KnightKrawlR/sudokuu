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

#include "sudokuboard.h"
#include <cassert>
#include <iostream>
#include <cstdlib>
using namespace std;


SudokuBoard::SudokuBoard()
{
  for(size_t i=0;i<9;i++)          // Initializing the board
    rows[i] = "         ";
}

void SudokuBoard::place(int r, int c, char n)
{
  assert(r>=0);
  assert(c>=0);
  assert(r<9);
  assert(c<9);

  rows[r][c] = n; 
  
}

void SudokuBoard::print() const
{
  for (int i=0; i<9; i++)
    cout << rows[i] << endl;
}

int SudokuBoard::get(int r, int c) const
{
  assert(r>=0);
  assert(c>=0);
  assert(r<9);
  assert(c<9);
  
 
  char num = rows[r][c];
  return num - '0';                    // Changing char to int
}

void SudokuBoard::remove(int r, int c)
{  
  assert(r>=0);
  assert(c>=0);
  assert(r<9);
  assert(c<9);
  
  rows[r][c] = ' ';                   // ' ' Signifies empty slot

}

bool SudokuBoard::canPlace(int r, int c, char n) const
{
  assert(r>=0);
  assert(c>=0);
  assert(r<9);
  assert(c<9);

  int ro = (r/3)*3;
  int co = (c/3)*3;  
  
  for (int i=0; i<9; i++){      // Checking the rows and columns
    if (rows[r][i] == n)
      return false;
    if (rows[i][c] == n)
      return false;
  }
  for (int j=0; j<3; j++){      // Checking each of the 3 by 3 squares.
    for (int k=0; k<3; k++){
      if (rows[ro+j][co+k] == n)
	return false;
      
    }
  }	
  return true;     
}

bool SudokuBoard::empty(int r, int c) const
{
  assert(r>=0);
  assert(c>=0);
  assert(r<9);
  assert(c<9);
  
  return rows[r][c] == ' ';          // Returning true if given slot is empty
}

bool SudokuBoard::solved() const
{
  for (int i=0; i<9; i++){          // Linear search through the entire board
    for (int j=0; j<9; j++){
      if (rows[i][j] == ' ')
	return false;
	}
  }
  return true;
}
