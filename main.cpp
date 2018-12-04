#include "mbed.h"

#include "arch/board.h"
#include "game/pong.h"
#include "component/coord.h"

Board board;

int main(){
	while(1){
		printf("sens2 : %d\n", board.rotary_encoder.read());
		wait(0.1);
	}
}


