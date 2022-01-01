/*
This file is a part of: Lina Engine
https://github.com/inanevin/LinaEngine

Author: Inan Evin
http://www.inanevin.com

Copyright (c) [2018-2020] [Inan Evin]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "HeaderTool.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <filesystem>

int main(int argc, char** argv)
{
    Lina::HeaderTool tool;
    tool.Run("../../");
    return 0;
}


namespace Lina
{

    std::vector<std::string> excludePaths 
    {
        ".vs",
        ".git",
        "build",
        "CMake",
        "Docs",
        "vendor",
        "VSItem",
        ".clang",
        ".travis",
        "LICENSE",
        "README",
        ".sln",
    };

    void HeaderTool::ReadHPP(const std::string& hpp)
    {
        std::ifstream file;
        file.open(hpp);
        std::stringstream ss;
        std::string       line;

        if (file.is_open())
        {
            while (file.good())
            {
                getline(file, line);

                std::cout << line << "\n";
            }
        }
    }
    
	void HeaderTool::Run(const std::string& path)
    {
        std::cout << "Scanning folder " << path << std::endl;

        for (const auto& entry : std::filesystem::directory_iterator(path))
        {
            if (entry.path().has_extension())
            {
                const std::string fullName = entry.path().filename().string();
                const std::string extension = fullName.substr(fullName.find(".") + 1);;

                if (extension.compare("hpp") == 0)
                {
                    std::cout << entry.path().string() << "\n";
                    ReadHPP(entry.path().string());

                }
            }
            else
            {

                std::string replacedPath = entry.path().string();
                std::cout << "Scanning subs " << replacedPath << std::endl;

                bool shouldExclude = false;
                for (auto& excludeStr : excludePaths)
                {
                    if (replacedPath.find(excludeStr) != std::string::npos)
                    {
                        shouldExclude = true;
                        break;
                    }
                }
                
                if (!shouldExclude)
                {
                    std::replace(replacedPath.begin(), replacedPath.end(), '\\', '/');
                    Run(replacedPath);
                }
       
            }
        }
    }
}

