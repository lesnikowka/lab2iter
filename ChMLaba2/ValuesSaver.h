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

void saveValuesToFile(const std::vector<std::vector<double>>& v)
{
	std::stringstream stream;

	stream << v.size() << " " << v[0].size() << " ";

	for (auto& i : v)
	{
		for (auto& j : i)
		{
			stream << j << " ";
		}
	}

	auto curDir = msclr::interop::marshal_as<std::string>(Directory::GetCurrentDirectory());

	std::ofstream ofs(curDir +  "\\..\\plane\\planeVals");

	std::string data = stream.str();

	ofs << data.substr(0, data.size() - 1);

	ofs.close();
}