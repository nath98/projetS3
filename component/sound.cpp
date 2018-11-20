#include "sound.h"

#include "mbed.h"

Sound::Sound(PinName pinout):m_pinout(pinout)
{
	
}

void Sound::Play_sound(int laNote, int octave, int duree)
{
    m_pinout.period(1.0/m_note[laNote]/(octave * 1.0));
    m_pinout = 0.5; //rapport cyclique 50% :  volume maximal
    wait(duree*.9*60.0/m_tempo); 
    m_pinout = 0.0; // rapport cyclique 0%:  volume nul
    wait(duree*.1*60.0/m_tempo); // court silence entre deux notes consécutives
}

void Sound::Beat_1(void)
{
    for ( int i = 0; i < 48 ; i++ ) 
	{
        Play_sound(m_melody[i][0],m_melody[i][1],m_melody[i][2]);
    }
}