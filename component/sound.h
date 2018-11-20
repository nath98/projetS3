#ifndef SOUND
#define SOUND

#include "mbed.h"

class Sound {
	public:
		Sound(PinName pinout);
		void Beat_1();
		
	private:
		void Play_sound(int laNote, int octave, int duree);
	
		const int m_tempo = 250;  // nombre de demi-temps par seconde

// fréquence associée à chaque note
//                                 do    do#    ré     ré#     mi    fa     fa#    sol    sol#     la       la#     si
		const float m_note[12]= {65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47};
		PwmOut m_pinout;


// chaque note de la mélodie comporte 3 paramètres:
// note (de 0 à 11:  0 pour do, 1 pour do#, etc)
// octave (1 à 3)
// durée (1 pour croche, 2 pour noire, 4 pour ronde)
		const int m_melody[48][3] = 
		{ {7,1,4},{10,1,1},{1,2,1},{7,2,1},{10,2,1},{1,3,1},
		  {10,1,3},{1,2,1},{5,2,1},{10,2,1},{1,3,1},{5,3,1},
		  {5,1,3},{8,1,1},{0,2,1},{5,2,1},{8,2,1},{0,3,1},
		  {0,1,3},{3,1,1},{7,1,1},{0,2,1},{3,2,1},{7,2,1},
		  {1,1,3},{5,1,1},{8,1,1},{1,2,1},{5,2,1},{8,2,1},
		  {10,1,3},{1,2,1},{5,2,1},{10,2,1},{1,3,1},{5,3,1},
		  {3,1,3},{7,1,1},{10,1,1},{3,2,1},{7,2,1},{10,2,1},
		  {8,1,3},{0,2,1},{3,2,1},{8,2,1},{0,3,1},{3,3,1},
		};
};
	
#endif//SOUND