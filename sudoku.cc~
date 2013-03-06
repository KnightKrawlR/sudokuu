#include "sudokuboard.h"
#include <cstdlib>
#include "stack.h"
#include <cassert>


SudokuBoard sudo;
Stack boardStack;


void makeBoard()
{
  // This Function initializes the Board.

  string row;
  
  for (int r=0; r<9; r++){
    getline(cin, row);
    for (int c=0; c<9; c++){
      sudo.place(r, c, row[c]);
    }
  }
}


bool constrained(int & newR, int & newC)
{
  // This function finds the slot with the lowest available moves. 

  string numStr = "123456789";
  int count = 0;             // Keep track of individual slots
  int finCount=9;

  for (int r=0; r<9; r++){   // Linear Search through all slots on board.
    for (int c=0; c<9; c++){ 
      
      count = 0;      

      if (sudo.empty(r, c)){                // Do not test occupied slots
	for (int k=0; k<9; k++){
	  if (sudo.canPlace(r, c, numStr[k])){
	    count++;
	  }
	}
	if (count == 0)    // Back track if a empty slot does not have a move
	  return false;
	  
	if (count < finCount){ // first time run
	  finCount = count;
	  newR = r;                         // Reference varible
	  newC = c;
	}
      }
      
    }
  }
  
  return true;                   // Successfully found a move
}

    
int lowest(int r, int c)
{
  // Function returns an interger with the lowest possible moves 
  
  string numS = "123456789";
  int numVal = 0;
  
  for(int i=0; i<9; i++)
    if (sudo.canPlace(r, c, numS[i])){
      numVal = numS[i];
      break;
    }
  return numVal;
}


int main()
{
  int newR = 0;
  int newC = 0;
  string n = "123456789";
  int val = 0;
  bool done = false;
  
  makeBoard();
  
  while (!sudo.solved()){
    done = false;
    // Place lowest available move on the board and push it on a stack.
    if (constrained(newR, newC)){
      sudo.place(newR, newC, lowest(newR, newC));   
      boardStack.push(newR);
      boardStack.push(newC);
    }
    else{
      // Need to Backtrack
      while(!done){
	if (!boardStack.empty()){
	  newC = boardStack.pop();
	  newR = boardStack.pop();
	}
	val = sudo.get(newR, newC);
	sudo.remove(newR, newC);
	for (int i= val; i<9; i++){
	  if (sudo.canPlace(newR, newC, n[i])){
	    sudo.place(newR, newC, n[i]);
	    boardStack.push(newR);
	    boardStack.push(newC);
	    done = true;
	    break;
	    
	  }
	  if (boardStack.empty() && i==8)
	    return 0;                     // Puzzle cannot be solved.
	}
      }
    }
  }
  sudo.print();
  return 0;
}
