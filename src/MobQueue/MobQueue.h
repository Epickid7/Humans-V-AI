#pragma once

#include <iostream>
#include <queue>

using std::string;



class MobQueue {
public:
	MobQueue();
	~MobQueue();
private:
	std::queue<string> q;
	
};