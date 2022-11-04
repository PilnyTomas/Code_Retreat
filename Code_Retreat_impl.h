// The game of life

// Map of neighbors (index):
// 0 1 2
// 7   3
// 6 5 4

// I am bit index i for the neighbour n
// n -> i
// 0 -> 4
// 1 -> 5
// 2 -> 6
// 3 -> 7
// 4 -> 0
// 5 -> 1
// 6 -> 2
// 7 -> 3


// 2 flags: my current state and my next state

class Cell{
public:
  bool current_state;
  Cell *neighbour[8];
  bool next_state;
};
