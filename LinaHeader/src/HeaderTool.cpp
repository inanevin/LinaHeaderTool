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
#include <unordered_map>

int main(int argc, char** argv)
{
    Lina::HeaderTool tool;
    tool.Run("../../");
    tool.SerializeReadData();
    return 0;
}

namespace Lina
{

#define LINA_CLASS_MACRO    "LINA_CLASS()"
#define LINA_PROPERTY_MACRO "LINA_PROPERTY("

    struct LinaProperty
    {
        std::string m_title        = "";
        std::string m_type         = "";
        std::string m_tooltip      = "";
        std::string m_dependsOn    = "";
        std::string m_propertyName = "";
    };

    std::vector<std::string> excludePaths{
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

    std::unordered_map<std::string, std::vector<LinaProperty>> m_classData;
    std::string                                                m_lastClass = "";
    LinaProperty                                               m_lastProperty;
    bool                                                       nextLineIsClass    = false;
    bool                                                       nextLineIsProperty = false;

    void HeaderTool::Run(const std::string& path)
    {
        // Scan each folder & sub-folders and find all .hpp files.
        for (const auto& entry : std::filesystem::directory_iterator(path))
        {
            if (entry.path().has_extension())
            {
                const std::string fullName  = entry.path().filename().string();
                const std::string extension = fullName.substr(fullName.find(".") + 1);

                if (extension.compare("hpp") == 0 || extension.compare("h") == 0)
                    ReadHPP(entry.path().string());
            }
            else
            {

                std::string replacedPath = entry.path().string();

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

    void HeaderTool::ReadHPP(const std::string& hpp)
    {
        std::ifstream file;
        file.open(hpp);
        std::stringstream ss;
        std::string       line;

        // Read the hpp line by line, find LINA_CLASS and LINA_PROPERTY macros.
        if (file.is_open())
        {
            while (file.good())
            {
                getline(file, line);

                if (nextLineIsClass)
                {
                    std::string className = line.substr(0, line.find(":"));
                    RemoveWordFromLine(className, "class");
                    RemoveWordFromLine(className, "struct");
                    RemoveWhitespaces(className);
                    nextLineIsClass = false;
                    m_lastClass     = className;
                }
                else if (nextLineIsProperty)
                {
                    // We have read the property macro, now we will read the property name
                    auto equals = line.find("=") != std::string::npos;

                    // Remove after =
                    if (equals)
                    {
                        auto equals = line.find("=");
                        line        = line.substr(0, equals - 1);
                    }
                    else
                        line = line.substr(0, line.find(";"));

                    line = line.substr(line.find_last_of(' '));
                    RemoveWhitespaces(line);
                    m_lastProperty.m_propertyName = line;
                    m_classData[m_lastClass].push_back(m_lastProperty);
                    nextLineIsProperty = false;
                }
                else
                {
                    if (line.find(LINA_CLASS_MACRO) != std::string::npos)
                        nextLineIsClass = true;
                    if (line.find(LINA_PROPERTY_MACRO) != std::string::npos)
                    {
                        ProcessPropertyMacro(line);
                        nextLineIsProperty = true;
                    }
                }
            }
        }
    }

    void HeaderTool::RemoveWordFromLine(std::string& line, const std::string& word)
    {
        auto n = line.find(word);
        if (n != std::string::npos)
        {
            line.erase(n, word.length());
        }
    }

    void HeaderTool::ProcessPropertyMacro(const std::string& line)
    {
        std::string trimmed           = line.substr(line.find("(") + 1);
        std::string insideParanthesis = trimmed.substr(0, trimmed.find(")"));
        RemoveWhitespaces(insideParanthesis);
        RemoveCommas(insideParanthesis);

        const int propertyCount = 4;
        for (int i = 0; i < propertyCount; i++)
        {
            const size_t      firstQuote  = insideParanthesis.find("\"");
            const size_t      secondQuote = insideParanthesis.find("\"", firstQuote + 1);
            const std::string property    = insideParanthesis.substr(firstQuote + 1, secondQuote - 1);
            insideParanthesis             = insideParanthesis.substr(secondQuote + 1);

            if (i == 0)
                m_lastProperty.m_title = property;
            else if (i == 1)
                m_lastProperty.m_type = property;
            else if (i == 2)
                m_lastProperty.m_tooltip = property;
            else if (i == 3)
                m_lastProperty.m_dependsOn = property;
        }
    }

    void HeaderTool::RemoveWhitespaces(std::string& str)
    {
        std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
        str.erase(end_pos, str.end());
    }

    void HeaderTool::RemoveCommas(std::string& str)
    {
        std::string::iterator end_pos = std::remove(str.begin(), str.end(), ',');
        str.erase(end_pos, str.end());
    }

    void HeaderTool::SerializeReadData()
    {
        std::ofstream file("reflection.linameta");

        if (file.is_open())
        {
            for (auto& [className, properties] : m_classData)
            {
                std::cout << "Class: " << className << std::endl;
                file << "Class: " << className << "\n";

                for (auto& prop : properties)
                {
                    file << "Property: " << prop.m_propertyName << "\n";
                    file << "Title: " << prop.m_title << "\n";
                    file << "Tooltip: " << prop.m_tooltip << "\n";
                    file << "Type: " << prop.m_type << "\n";
                    file << "Depends: " << prop.m_dependsOn << "\n";
                }
            }
        }
        
    }

} // namespace Lina
