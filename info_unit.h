#ifndef INFO_UNIT_H
#define INFO_UNIT_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

enum VerticalAlign {
UP,
MIDDLE,
DOWN
}; 

enum HorizontalAlign {
LEFT,
CENTER,
RIGHT
};

class Info_unit
{
	private:
		// Varibles defining format and content
		int rows;
		int columns;
		int text_per_row;


		string content;
		bool visible;
		VerticalAlign v_align;
		HorizontalAlign h_align; 
		
		// Variables for controlling printing procedure
		size_t size;
		int index;
		int start_row;
		int start_column;
		int text_rows;
		char place_holder;
		
		Info_unit *rightUnit;
		Info_unit *downUnit;
		void _ShowLine(int r);
	public:
		Info_unit(int rows,int columns,string content,VerticalAlign va=MIDDLE,HorizontalAlign ha=CENTER);
		Info_unit();
		~Info_unit(void);
		void SetRightUnit(Info_unit* info);
		void SetDownUnit(Info_unit* info);
		void SetAlignment(VerticalAlign va,HorizontalAlign ha);
		void SetVisibility(bool v);
		void SetContent(string content);
		void SetPlaceholder(char ch);
		string GetContent(void);
		int GetWidth(void);
		int GetHeight(void);
		Info_unit* GetRightUnit(void);
		Info_unit* GetDownUnit(void);
		void Show(void);
};


#endif

