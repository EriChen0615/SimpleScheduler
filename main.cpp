#include <iostream>
#include <ctime> 
#include "info_unit.h"
#include "row.h"
#include "table.h"
#include "link_list.h"


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

//	string x_ticks[5] = {"1","2","3","4","5"};
//	string y_ticks[2] = {"a","b"}; 
//	Table table = Table(2,5,x_ticks,y_ticks);
//	table.Show();
//	table.SetRowHeight(0,2);
//	table.Show();
//	table.Insert(2,1,new Info_unit(5,5,"Hi!"));
//	table.Show();
//	table.Delete(2,1);
//	table.Show();
//	table.Replace(2,0,new Info_unit(5,5,"Hell"));
//	table.Show();
//	string content[5] = {"Q","W","E","R","T"};
//	int width[5] = {10,10,10,10,10};
//	Row *row = new Row(5,5,width,content);
//	table.InsertRow(3,row);
//	table.Show();
//	table.DeleteRow(2);
//	table.Show();
//	table.ReplaceRow(1,new Row(5,5,width,content));
//	table.Show();

//	string s1 = "Hello";
//	string s3 = "World";
//	Node<string> node1 = Node<string>();
//	node1.SetValue(s1);
//	string s2 = node1.GetValue();
//	cout << s2 << endl;
//	Node<string> node2 = node1;
//	cout << node2.GetValue() << endl;
//
//	Link_list<string> l1 = Link_list<string>(&node1); 
//	l1.Show();
//	l1.Insert(1,&node2);
//	l1.Show();
//	Node<string> node3 = Node<string>(s3,NULL);
//	Node<string> node4 = node3;
//	l1.Append(&node3);
//	l1.Show();
//	l1.Delete(1);
//	l1.Show();
//	l1.Replace(0,&node4);
//	l1.Show();

	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt;
	tm* ltm = localtime(&now);
	cout << 1900+ltm->tm_year << endl;
	cout << 1+ltm->tm_mon << endl;
	
	return 0;
}
