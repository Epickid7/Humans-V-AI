#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <fstream>

using std::string;
using std::fstream;



class MobQueue {
public:
	MobQueue();
	~MobQueue();

	void loadFromLevelFile(std::string file);
private:
	std::queue<string> mQueue;
	
};