#include "row.h"

Row::Row(int height,int columns,const int *width,const string *x_ticks,const string separator)
{
	this->height = height;
	this->columns = columns;
	this->head_unit = new Info_unit(height,width[0],x_ticks[0]); 
	this->separator = separator;
	Info_unit *current_unit = head_unit;
	for(int i=1;i<columns;i++)
	{
		current_unit->SetRightUnit(new Info_unit(height,width[i],x_ticks[i]));
		current_unit = current_unit->GetRightUnit();
//		units[i] = Info_unit(height,width[i],x_ticks[i]);
//		units[i].Show(); 
//		if(i!=columns-1)
//		{
//			units[i].SetRightUnit(units+i+1);
//		}
	}
}

Row::~Row(void)
{
	
}  

void Row::Show(void)
{
	//units[0].Show();
	head_unit->Show();
	Info_unit* current = head_unit;
	int total_width = 0;
	for(int i=0;i<columns;i++)
	{
		//total_width += units[i].GetWidth();
		total_width+= current->GetWidth();
		current = current->GetRightUnit(); 
	}
	for(int i=0;i<total_width;i++) cout << separator;
	cout << endl;
}

void Row::Insert(int pos,int width,string x_tick)
{
	Info_unit *tmp = new Info_unit(height,width,x_tick);
	if(pos==0)
	{
		tmp->SetRightUnit(head_unit);
		tmp->SetDownUnit(head_unit->GetDownUnit());
		head_unit->SetDownUnit((Info_unit*)NULL);
		head_unit = tmp;
	}
	else
	{
		Info_unit* current = head_unit->GetRightUnit(); 
		Info_unit* before = head_unit;
		for(int i=1;i<pos;i++)
		{
			before = before->GetRightUnit();
			current = current->GetRightUnit();
		}
		before->SetRightUnit(tmp);
		tmp->SetRightUnit(current);
	}
}

void Row::Delete(int pos)
{
	if(pos==0)
	{
		Info_unit *tmp = head_unit->GetRightUnit();
		tmp->SetDownUnit(head_unit->GetDownUnit());
		delete head_unit;
		head_unit = tmp;
	}
	else
	{
		Info_unit* current = head_unit->GetRightUnit(); 
		Info_unit* before = head_unit;
		for(int i=1;i<pos;i++)
		{
			before = before->GetRightUnit();
			current = current->GetRightUnit();
		}
		before->SetRightUnit(current->GetRightUnit());
		delete current;
	}
}
