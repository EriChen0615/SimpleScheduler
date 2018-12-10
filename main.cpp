#include <iostream>
#include "info_unit.h"
#include "row.h"
#include "table.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//InfoUnit<char> i;
	//InfoUnit<int> j;
//	string sen1 = "This is just a beginning";
//	string sen2 = "I have only just begun";
//	string sen3 = "This is string 3 to be tested";
//	Info_unit a(4,15,sen1);
//	Info_unit b(4,20,sen2);
//	Info_unit c(4,30,sen3);
//	a.Show();
////	Info_unit c(10,6,words);
////	a.SetHeight(6);
////	a.SetWidth(10);
////	a.Show(); 
//	a.SetRightUnit(&b);
//	b.SetRightUnit(&c);
////	a.SetDownUnit(&c);
////	a.SetDownUnit(&c);
//	a.Show();
//	a.SetVisibility(false);
////	b.SetPlaceholder('$');
////	b.SetHeight(6);
////	b.SetWidth(10);
//	a.Show();
//	string content[5] = {"A","B","C","D","E"};
//	int width[5] = {10,10,10,10,10};
//	Row row = Row(5,5,width,content);
//	row.Show();
//	row.Insert(3,10,"F");
//	row.Show();
//	row.Delete(2);
//	row.Show();
//	row.SetHeight(3);
//	row.Show();
//	string hi = "Hi!";
//	row.Modify(2,"Eric");
//	row.Show();
	string x_ticks[5] = {"1","2","3","4","5"};
	string y_ticks[2] = {"a","b"}; 
	Table table = Table(2,5,x_ticks,y_ticks);
	table.Show();
	table.SetRowHeight(0,2);
	table.Show();
	table.Insert(2,1,new Info_unit(5,5,"Hi!"));
	table.Show();
	table.Delete(2,1);
	table.Show();
	table.Replace(2,0,new Info_unit(5,5,"Hell"));
	table.Show();
	string content[5] = {"Q","W","E","R","T"};
	int width[5] = {10,10,10,10,10};
	Row *row = new Row(5,5,width,content);
	table.InsertRow(3,row);
	table.Show();
	table.DeleteRow(2);
	table.Show();
	table.ReplaceRow(1,new Row(5,5,width,content));
	table.Show();
	return 0;
}
