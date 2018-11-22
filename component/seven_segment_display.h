/**************************************************************************
 ***	author : nathanael MERAUD			october 2018	***
 ***									***
 ***	this class is created to help usage of modules composed of 4	***
 ***	seven-segment display.						***
 ***	the class comport 2 modes of fuctionnement :			***
 ***		-the first one print element contain in m_value		***
 ***		-the second one print an annimation defined on		***
 ***		 m_annim_tab						***
 ***		-those two mode can be combined to create a new one 	***
 ***		 for people who want annim display (for exemple a blink ***
 ***		 annimation)						***
 ***									***
 **************************************************************************/



#ifndef SEVEN_SEGMENT_DISPLAY
#define SEVEN_SEGMENT_DISPLAY

#include "mbed.h"
#include <vector>

class Seven_segment_display
{
	/* this transcoding_tab is use to convert an uint8_t containning in
	   [0, 15] to a table which represent it’s hexadecimal representation
	   on a seven-segment display*/ 
	uint8_t transcoding_tab[16][7] = {{1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}, {1,1,1,0,1,1,1}, {0,0,1,1,1,1,1}, {1,0,0,1,1,1,0}, {0,1,1,1,1,0,1}, {1,0,0,1,1,1,1}, {1,0,0,0,1,1,1}}; 

	public:
		/* you need to pass DigitalOut pointer to the class. Those pointer
		   represent board’s pins.*/
		Seven_segment_display(PinName select1, PinName select2, PinName select3, PinName select4, PinName seg1, PinName seg2, PinName seg3, PinName seg4, PinName seg5, PinName seg6, PinName seg7);
		~Seven_segment_display();
		void right_shift(uint8_t number);
		void left_shift(uint8_t number);
//		void print_one(uint8_t position, uint8_t value);//position need to be 0,1,2 or 3 anp value between 0 and 15


		// starter/stopper
		void start_print();
		//void start_print_time();
		void show_annim();
		void start_print_with_mask();
		void stop();

		//setters
		void set_value(const uint8_t value[]);
		void set_value(uint32_t value);
		void set_number(uint8_t position, uint8_t number);
		void set_time_between_2_print(float time);
		void set_time_between_2_annim_image(float times);
		void set_annim(std::vector<uint8_t*>);
		void set_operator_mask(std::vector<uint16_t*>);
		//getter
		uint8_t* get_value()const;
	
	//	void print(uint8_t tab[]);

	private:
		uint8_t m_common_anode;

		void next_annim();
		void step_next_annim();

		void step_print();
		void print_time();
		void annim_step();

		
		bool m_annim;		
		bool m_print;
		bool m_annim_mask;
		
		std::vector<uint8_t* > m_annim_tab;//vector witch contain table of 4 integer, one integer is represent the state of the 7 segment (b6 = A, b5 = B,…, b0=G)
		std::vector<uint16_t* > m_operator_annim_tab;//vector whitch contain a table of 4 integer, they represent the opperation to do between annim_tab and and m_value_to_print the value is composed of 7 paire of bit represent like this XX MG2MG1 MF2MF1 … MC2MC1 MB2MB1 MA2MA1
		uint8_t m_annim_step;
		uint8_t m_value_to_print[4];
		DigitalOut* m_select_pin[4];//tab (size 4)
		DigitalOut* m_value_pin[7];//tab (size 7)
		Ticker m_timer;
		Ticker m_timer2;
		float m_time_between_2_print;
		float m_time_between_2_annim_image;
		uint8_t m_times_between_2_annim;
};


#endif//SEVEN_SEGMENT_DISPLAY
