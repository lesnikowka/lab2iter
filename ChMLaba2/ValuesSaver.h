#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;
using namespace System::IO;

void saveValuesToFile(const std::vector<std::vector<double>>& v, std::string name)
{
	std::stringstream stream;

	stream << v.size() - 2 << " " << v[0].size() - 2 << " ";

	for (int i = 1; i < v.size() - 1; i++)
	{
		for (int j = 1; j < v[i].size() - 1; j++)
		{
			stream << v[i][j] << " ";
		}
	}

	auto curDir = msclr::interop::marshal_as<std::string>(Directory::GetCurrentDirectory());

	std::ofstream ofs(curDir +  "\\..\\plane\\" + name);

	std::string data = stream.str();

	ofs << data.substr(0, data.size() - 1);

	ofs.close();

	STARTUPINFOA process_startup_info{ 0 };
	process_startup_info.cb = sizeof(process_startup_info); 

	PROCESS_INFORMATION process_info{ 0 };

	//std::string dir = "python " + curDir + "\\..\\plane\\visualize.py " + curDir + "\\..\\plane\\planeVals";
	std::string dir = curDir + "\\..\\plane\\visualize.exe " + curDir + "\\..\\plane\\planeVals";

	CreateProcessA(NULL, const_cast<char*>(dir.data()), NULL, NULL, TRUE, 0, NULL, NULL, &process_startup_info, &process_info);

	CloseHandle(process_info.hProcess);
	CloseHandle(process_info.hThread);


}