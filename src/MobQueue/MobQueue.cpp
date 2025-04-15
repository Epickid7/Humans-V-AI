#include "MobQueue.h"

MobQueue::MobQueue()
{
}

MobQueue::~MobQueue()
{
}

//should load one line from the file
void MobQueue::loadFromLevelFile(std::string file)
{
	std::fstream input;
	input.open(file, std::ios::in);

	string line;
	
	getline(input, line, '\n');
	 
	// (each 'wave' should be one line of ten mobs) 
	//this makes sense for now and it can be changed by changing the csv file and the number 
	// in the for loop
	while (!input.eof()) {
		for (int i = 0; i < 9; i++) {
			getline(input, line, ',');
			this->mQueue.push(line);
		}
		getline(input, line, '\n');
	}
	
}
//
//Machine MobQueue::getMachineType(std::string machineAbrv)
//{
//	Machine m;
//	if (machineAbrv == "TR") {
//		//return 
//	}
//	return ;
//}
