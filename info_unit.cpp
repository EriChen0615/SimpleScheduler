#include"info_unit.h"

Info_unit::Info_unit(int r,int c,string cont,VerticalAlign va,HorizontalAlign ha)
{
	rows = r;
	columns = c;
	text_per_row = columns-2;
	place_holder = 	'-';
	visible = true;
	
	index = 0;
	rightUnit = NULL;
	downUnit = NULL;
	// dynamically allocate an array of type string
	content = cont;
	// Calculate start_row and start_column
	v_align = va;
	h_align = ha;
	size = content.length();
	
	int total_space = rows*columns; 
	(size%text_per_row==0) ? (text_rows=size/text_per_row) : (text_rows=size/text_per_row +1); // integer division
	switch(v_align)
	{
		case UP:
		{
			start_row = 0;
		 }break;
		case MIDDLE:
		{
			start_row = (rows-text_rows)/2;
		 }break;
		case DOWN:
		{
			start_row = rows-text_rows;
		 }break; 
	}
	
}


Info_unit::Info_unit()
{
	rightUnit = NULL;
	downUnit = NULL;
}


Info_unit::~Info_unit()
{
	//delete[] content;
} 

void Info_unit::SetRightUnit(Info_unit* info)
{
	rightUnit = info;	
}

void Info_unit::SetDownUnit(Info_unit* info)
{
	downUnit = info;	
}

void Info_unit::SetAlignment(VerticalAlign va,HorizontalAlign ha)
{
	v_align = va;
	h_align = ha;
}

void Info_unit::SetVisibility(bool v)
{
	visible = v;
}

void Info_unit::SetContent(string c)
{
	content = c;
}

void Info_unit::SetPlaceholder(char ch)
{
	place_holder = ch;	
}
void Info_unit::SetHeight(int height)
{
	this->rows = height;
	switch(v_align)
	{
		case UP:
		{
			start_row = 0;
		 }break;
		case MIDDLE:
		{
			start_row = (rows-text_rows)/2;
		 }break;
		case DOWN:
		{
			start_row = rows-text_rows;
		 }break; 
	}
}
void Info_unit::SetWidth(int width)
{
	this->columns = width;
}
string Info_unit::GetContent(void)
{
	return content;
}
int Info_unit::GetWidth(void)
{
	return columns;
}
int Info_unit::GetHeight(void)
{
	return rows;
}	
Info_unit* Info_unit::GetRightUnit(void)
{
	return this->rightUnit;
}
Info_unit* Info_unit::GetDownUnit(void)
{
	return this->downUnit; 
}
void Info_unit::_ShowLine(int r)
{
	
	if(index==size && r==0) index = 0; // reset index
	if(!visible)  // omit without placeholding
	{
		if(rightUnit!=NULL)	(*rightUnit)._ShowLine(r);
		return;		
	}
	
	if(r>=start_row&&r<start_row+text_rows)
	{
		
		if(size-index>=text_per_row)
		{
			switch(h_align)
			{
				case LEFT:
				{
					start_column = 0;
				}break;
				case CENTER:
				{
					start_column = (columns-text_per_row)/2;
				}break;
				case RIGHT:
				{
					start_column = columns-text_per_row;
				}break;
			}
		}
		// special case: printing the last line
		else
		{
			int remaining_text = size-index;
			switch(h_align)
			{
				case LEFT:
				{
					start_column = 0;
				}break;
				case CENTER:
				{
					start_column = (columns-remaining_text)/2;
				}break;
				case RIGHT:
				{
					start_column = columns-remaining_text;
				}break;
			}
		}
		for(int i=0;i<columns;i++)
		{
			if(i>=start_column&&i<start_column+text_per_row&&index<size) 
			{
				cout << content[index++];
			}
			else
			{
				cout << place_holder;
			}
			
		}
	}
	else
	{
		for(int i=0;i<columns;i++)
		{
			cout << place_holder;
		}
	}
	if(rightUnit!=NULL)	(*rightUnit)._ShowLine(r);
}


void Info_unit::Show(void)
{
	for(int r=0;r<rows;r++)
	{
		_ShowLine(r);
		cout << endl; 
	}
	if(downUnit!=NULL) (*downUnit).Show();
}

