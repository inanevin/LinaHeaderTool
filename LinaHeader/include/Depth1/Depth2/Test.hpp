/*
This file is a part of: Lina Engine
https://github.com/inanevin/LinaEngine

Author: Inan Evin
http://www.inanevin.com

Copyright (c) [2018-] [Inan Evin]

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

#pragma once

#ifndef Renderable_HPP
#define Renderable_HPP

#include "Core/Component.hpp"
#include "Core/CommonReflection.hpp"

namespace Lina::World
{
    LINA_COMPONENT("Renderable")
    class RenderableComponent : public Component
    {
    public:
        virtual TypeID GetTID()
        {
            return GetTypeID<RenderableComponent>();
        }

        LINA_FIELD("Dummy", "Int", "Hehe", "", "Default")
        int dummy;
    };
} // namespace Lina::World

namespace Lina::Reflection
{
    // template <>
    // inline MetaType Reflect<GetTypeID<World::RenderableComponent>()>()
    // {
    //     constexpr TypeID tid = GetTypeID<World::RenderableComponent>();
    //     const auto&      it  = g_metaData.find(tid);
    //     if (it != g_metaData.end())
    //         return it->second;
    // 
    //     MetaType type;
    // 
    //     type.createFunc        = std::bind(&REF_Create<World::RenderableComponent>);
    //     type.createFromPtrFunc = std::bind(&REF_CreateFromPtr<World::RenderableComponent>, std::placeholders::_1);
    //     type.destroyFunc       = std::bind(&REF_Destroy<World::RenderableComponent>, std::placeholders::_1);
    // 
    //     type.AddField<&World::RenderableComponent::dummy, World::RenderableComponent>("dum"_hs);
    //     type.GetField("dum"_hs)->AddProperty("type"_hs, "int");
    //     type.AddProperty("sa"_hs, "yoo");
    // 
    //     g_metaData[tid] = type;
    //     return type;
    // }
} // namespace Lina::Reflection

#endif
