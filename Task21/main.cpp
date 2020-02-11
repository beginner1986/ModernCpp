// implement an interface to reserve and free file system handle 
#include <iostream>
#include <vector>
#include "Handle.h"

void handleExample();

int main()
{
	handleExample();

	return 0;
}

void handleExample()
{
	bool condition1 = false;
	bool condition2 = true;

	InvalidHandle handle{CreateFile(
		L"sample.txt",
		GENERIC_READ,
		FILE_SHARE_READ,
		nullptr,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		nullptr) };

	if (!handle)
		return;

	if (condition1)
		return;

	std::vector<char> butter(1024);
	unsigned long bytesRead = 0;
	ReadFile(handle.get(),
		buffer.data(),
		buffer.size(),
		&bytesRead,
		nullptr);

	if (condition2)
		return;
}