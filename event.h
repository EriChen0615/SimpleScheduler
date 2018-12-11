#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <c_time>
#include "link_list.h"

class Event
{
	private:
		time_t start_time;
		time_t end_time;
		string where;
		string who;
		string what;
		Event* parent;
		Link_list<Event*> children;
		bool active;
	public:
		Event(void);
		Event(string what);
		void SetStartTime(const time_t* time);
		void SetEndTime(const time_t* time);
		void SetWhere(const string where);
		void SetWho(const string who);
		void SetWhat(const string what);
		void SetParent(Event* parent);
		void AddChild(Event* child);
		void DeleteChild(Event* child);
		bool operator==(Event other); // equal if what and start_time are identical
		void operator=(Event other);
		
}

#endif

