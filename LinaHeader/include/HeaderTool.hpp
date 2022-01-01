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

/*
Class: HeaderTool



Timestamp: 12/14/2021 2:03:29 PM
*/

#pragma once

#ifndef HeaderTool_HPP
#define HeaderTool_HPP
#include <string>
#include <unordered_map>

namespace Lina
{
    struct LinaProperty
    {
        std::string m_title        = "";
        std::string m_type         = "";
        std::string m_tooltip      = "";
        std::string m_dependsOn    = "";
        std::string m_propertyName = "";
    };

    struct LinaClass
    {
        bool                      m_isStruct             = false;
        std::string               m_name                 = "";
        std::string               m_nameWithNamespace    = "";
        std::string               m_title                = "";
        std::string               m_icon                 = "";
        std::string               m_category             = "";
        bool                      m_canAddComponent      = false;
        bool                      m_listenToValueChanged = false;
        std::vector<LinaProperty> m_properties;
    };

    class HeaderTool
    {
    public:
        HeaderTool() = default;
        ~HeaderTool();

        void Run(const std::string& path);
        void ReadHPP(const std::string& hpp);
        void RemoveWordFromLine(std::string& line, const std::string& word);
        void ProcessPropertyMacro(const std::string& line);
        void ProcessClassMacro(const std::string& line);
        void RemoveWhitespaces(std::string& str);
        void RemoveComma(std::string& str);
        void RemoveString(std::string& str, const std::string& toErase);
        void RemoveBrackets(std::string& str);
        void SerializeReadData();
        void AddDataToCPP();

    private:
        std::unordered_map<std::string, LinaClass*>              m_classData;
        std::unordered_map<std::string, std::vector<LinaClass*>> m_namespaceClassMap;
        std::string                                              m_lastClass     = "";
        std::string                                              m_lastNamespace = "";
        LinaProperty                                             m_lastProperty;
        LinaClass                                                m_lastClassData;
        bool                                                     nextLineIsClass    = false;
        bool                                                     nextLineIsProperty = false;
    };
} // namespace Lina

#endif
