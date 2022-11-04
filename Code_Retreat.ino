#include "Code_Retreat_impl.h"
#define ARRAY_SIZE 24
//Cell **cell_map;
Cell cell_map[ARRAY_SIZE][ARRAY_SIZE];

// cell_map of neighbors (index):
// 0 1 2
// 7   3
// 6 5 4

void place_glider(int x, int y){
	cell_map[x+1][y].current_state = true;

	cell_map[x+2][y+1].current_state = true;

	cell_map[x][y+2].current_state = true;
	cell_map[x+1][y+2].current_state = true;
	cell_map[x+2][y+2].current_state = true;
}

void setup(){
	/*
	cell_map = new Cell*[ARRAY_SIZE];
	for(int y = 0; y <= ARRAY_SIZE; ++y){
		cell_map[y] = new Cell[ARRAY_SIZE];
	}
	*/
	display_setup();
		for(int y = 0; y < ARRAY_SIZE; ++y){
		for(int x = 0; x < ARRAY_SIZE; ++x){
				cell_map[x][y].neighbour[0] = x-1 >= 0 && y-1 >= 0 && x <= ARRAY_SIZE-1 && y-1 <= ARRAY_SIZE-1 ? &(cell_map[x-1][y-1]) : NULL;
				cell_map[x][y].neighbour[1] = x >= 0 && y-1 >= 0 && x <= ARRAY_SIZE-1 && y-1 <= ARRAY_SIZE-1 ? &(cell_map[x][y-1])   : NULL;
				cell_map[x][y].neighbour[2] = x+1 >= 0 && y-1 >= 0 && x+1 <= ARRAY_SIZE-1 && y-1 <= ARRAY_SIZE-1 ? &(cell_map[x+1][y-1]) : NULL;
				cell_map[x][y].neighbour[3] = x+1 >= 0 && y >= 0 && x+1 <= ARRAY_SIZE-1 && y <= ARRAY_SIZE-1 ? &(cell_map[x+1][y])   : NULL;
				cell_map[x][y].neighbour[4] = x+1 >= 0 && y+1 >= 0 && x+1 <= ARRAY_SIZE-1 && y+1 <= ARRAY_SIZE-1 ? &(cell_map[x+1][y+1]) : NULL;
				cell_map[x][y].neighbour[5] = x >= 0 && y+1 >= 0 && x <= ARRAY_SIZE-1 && y+1 <= ARRAY_SIZE-1 ? &(cell_map[x][y+1])   : NULL;
				cell_map[x][y].neighbour[6] = x-1 >= 0 && y+1 >= 0 && x-1 <= ARRAY_SIZE-1 && y+1 <= ARRAY_SIZE-1 ? &(cell_map[x-1][y+1]) : NULL;
				cell_map[x][y].neighbour[7] = x-1 >= 0 && y >= 0 && x-1 <= ARRAY_SIZE-1 && y <= ARRAY_SIZE-1 ? &(cell_map[x-1][y])   : NULL;
				//cell_map[x][y].current_state = (rand() % 10 >= 5 ? true : false ); // Create alive cells
				//cell_map[x][y].current_state = true;
				//printf("[x=%d][y=%d] current_state=%d, addr=%p, neighbour 3 addr = %p\n",x,y,cell_map[x][y].current_state, &cell_map[x][y], cell_map[x][y].neighbour[3]);
			  for(int a = 0; a < 8; ++a){
					//printf("[x=%d][y=%d]addr=%p, neighbour[%d] addr=%p\n",x,y, &cell_map[x][y], a, cell_map[x][y].neighbour[a]);
			  }
			}
			place_glider(0,0);
	}
	draw();
	while(1)delay(1000);
}


void loop(){

}
