#include <iostream>
#include "info_unit.h"
#include "row.h"
#include "table.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//InfoUnit<char> i;
	//InfoUnit<int> j;
	string sen1 = "This is just a beginning";
	string sen2 = "I have only just begun";
	string sen3 = "This is string 3 to be tested";
	Info_unit a(4,15,sen1);
	Info_unit b(4,20,sen2);
	Info_unit c(4,30,sen3);
	a.Show();
//	Info_unit c(10,6,words);
//	a.SetHeight(6);
//	a.SetWidth(10);
//	a.Show(); 
	a.SetRightUnit(&b);
	b.SetRightUnit(&c);
//	a.SetDownUnit(&c);
//	a.SetDownUnit(&c);
	a.Show();
	a.SetVisibility(false);
//	b.SetPlaceholder('$');
//	b.SetHeight(6);
//	b.SetWidth(10);
	a.Show();
//	string content[5] = {"A","B","C","D","E"};
//	int width[5] = {10,10,10,10,10};
//	Row row = Row(5,5,width,content);
//	row.Show();
//	row.Insert(3,10,"F");
//	row.Show();
//	row.Delete(2);
//	row.Show();
//	string x_ticks[5] = {"1","2","3","4","5"};
//	string y_ticks[2] = {"a","b"}; 
//	Table table = Table(2,5,x_ticks,y_ticks);
//	table.Show();
	return 0;
}
