#ifndef SEVEN_SEGMENT_DISPLAY
#define SEVEN_SEGMENT_DISPLAY

#include "mbed.h"
#include <vector>


class Seven_segment_display
{
	uint8_t transcoding_tab[16][7] = {{1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}, {1,1,1,0,1,1,1}, {0,0,1,1,1,1,1}, {1,0,0,1,1,1,0}, {0,1,1,1,1,0,1}, {1,0,0,1,1,1,1}, {1,0,0,0,1,1,1}}; 

	public:
		Seven_segment_display(DigitalOut* select_pin[4], DigitalOut* value_pin[7]);
		~Seven_segment_display();
		void set_value(const uint8_t value[]);
		void set_value(uint16_t value);
		void set_number(uint8_t position, uint8_t number);
		uint8_t* get_value()const;
		void start_print();
		void stop_print();
		void right_shift(uint8_t number);
		void left_shift(uint8_t number);
		void show_annim();
		void set_time_between_2_print(float time);
		void set_times_between_2_annim(uint8_t times);
		void set_annim(std::vector<uint8_t*>);
		void print_one(uint8_t position, uint8_t value);//position need to be 0,1,2 or 3 anp value between 0 and 15
		void next_annim();
	//	void print(uint8_t tab[]);

	private:

		void step_print();
		void annim_step();
		
		bool m_annim;		
		bool m_print;
		std::vector<uint8_t*> m_anim;//vector witch contain table of 4 integer, one integer is represent the state of the 7 segment (b6 = A, b5 = B,…, b0=G)
		uint8_t m_value_to_print[4];
		DigitalOut** m_select_pin;//tab (size 4)
		DigitalOut** m_value_pin;//tab (size 7)
		Timeout m_timer;
		float m_time_between_2_print;
		uint8_t m_times_between_2_annim;
};


#endif//SEVEN_SEGMENT_DISPLAY
