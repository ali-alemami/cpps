#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char** argv)
{
	std::string		fileName;
	std::string		newFileName;
	std::string		oldStr;
	std::string		newStr;
	std::string		content;
	std::ifstream	file;
	std::ofstream	newFile;

	if (argc != 4)
		return (1);
	fileName = argv[1];
	newFileName = fileName + ".replace";
	oldStr = argv[2];
	newStr = argv[3];

	if (oldStr == "")
		return (0);
	file.open(fileName.c_str());
	if (file.is_open())
	{
		content.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		file.close();
	}
	else
	{
		std::cerr << "issue in openning the file" << std::endl;
		return (1);
	}
	newFile.open(newFileName.c_str());
	if (newFile.is_open())
	{
		for (size_t i = 0; i < content.size(); i++)
		{
			if (content[i] == oldStr[0] && (content.substr(i, oldStr.size()) == oldStr))
			{
				newFile << newStr;
				i += (oldStr.size() - 1);
			}
			else
			{
				newFile << content[i];
			}
		}
		newFile.close();
	}
	else
	{
		std::cerr << "issue in openning the new file" << std::endl;
		return (1);
	}
	return (0);
}

// this is my revenge against norminette