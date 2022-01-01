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

#include "Core/ReflectionRegistry.hpp"
#include "Core/CommonECS.hpp"
#include "ECS/Registry.hpp"
#include "Log/Log.hpp"
#include "Utility/StringId.hpp"
#include <entt/meta/resolve.hpp>
#include <entt/meta/factory.hpp>
#include <entt/meta/meta.hpp>
#include <entt/meta/node.hpp>

/// <summary>
/// *****************************************************************************
/// *
/// *   THIS IS AN AUTOMATICALLY UPDATED FILE, DO NOT CHANGE THE IDENTIFIER LINES
/// *   BEFORE EACH BUILD, LINA HEADER TOOL PROCESSES ALL THE HEADERS WITHIN THE PROJECT
/// *   AND FILES THE REFLECTED COMPONENTS & PROPERTIES, WHICH ARE THEN ADDED TO THIS FILE
/// *   AUTOMATICALLY.
/// *
/// *****************************************************************************
/// </summary>

//INC_BEGIN - !! DO NOT MODIFY THIS LINE !!
#include "Depth1/Depth2/Test.hpp"
//INC_END - !! DO NOT MODIFY THIS LINE !!

namespace Lina
{
    using namespace entt::literals;

    template <typename Type>
    void REF_CloneComponent(ECS::Entity from, ECS::Entity to)
    {
        Type component = ECS::Registry::Get()->template get<Type>(from);
        ECS::Registry::Get()->template emplace<Type>(to, component);
    }

    template <typename Type>
    void REF_SerializeComponent(entt::snapshot& snapshot, cereal::PortableBinaryOutputArchive& archive)
    {
        snapshot.component<Type>(archive);
    }

    template <typename Type>
    void REF_DeserializeComponent(entt::snapshot_loader& loader, cereal::PortableBinaryInputArchive& archive)
    {
        loader.component<Type>(archive);
    }

    template <typename Type>
    void REF_SetEnabled(ECS::Entity ent, bool enabled)
    {
        ECS::Registry::Get()->template get<Type>(ent).SetIsEnabled(enabled);
    }

    template <typename Type>
    Type& REF_Get(ECS::Entity entity)
    {
        return ECS::Registry::Get()->template get<Type>(entity);
    }

    template <typename Type>
    void REF_Add(ECS::Entity entity)
    {
        ECS::Registry::Get()->template emplace<Type>(entity);
    }

    template <typename Type>
    bool REF_Has(ECS::Entity entity)
    {
        return ECS::Registry::Get()->all_of<Type>(entity);
    }

    template <typename Type>
    void REF_Reset(ECS::Entity entity)
    {
        TypeID tid = GetTypeID<Type>();

        if (tid == GetTypeID<EntityDataComponent>())
        {
            EntityDataComponent& comp = ECS::Registry::Get()->get<EntityDataComponent>(entity);
            comp.SetLocalLocation(Vector3::Zero);
            comp.SetLocalRotation(Quaternion());
            comp.SetLocalScale(Vector3::One);
        }
        else
            ECS::Registry::Get()->template replace<Type>(entity, Type());
    }

    template <typename Type>
    void REF_Remove(ECS::Entity entity)
    {
        ECS::Registry::Get()->template remove<Type>(entity);
    }

    template<typename Type>
    void REF_Copy(ECS::Entity entity, TypeID tid)
    {
    }

    template <typename Type>
    void REF_Paste(ECS::Entity entity)
    {
    }

    template <typename Type>
    void REF_ValueChanged(ECS::Entity ent, const char* propertyName)
    {

    }

    void ReflectionRegistry::RegisterReflectedComponents()
    {
        //REGFUNC_BEGIN - !! DO NOT CHANGE THIS LINE !!
entt::meta<ECS::EntityDataComponent>().type().props(std::make_pair("Title"_hs, "EntityDataComponent"), std::make_pair("Icon"_hs,"ICON_FA_MESH"), std::make_pair("Category"_hs,"Data"));
entt::meta<ECS::EntityDataComponent>().func<&REF_CloneComponent<ECS::EntityDataComponent>, entt::as_void_t>("clone"_hs);
entt::meta<ECS::EntityDataComponent>().func<&REF_SerializeComponent<ECS::EntityDataComponent>, entt::as_void_t>("serialize"_hs);
entt::meta<ECS::EntityDataComponent>().func<&REF_DeserializeComponent<ECS::EntityDataComponent>, entt::as_void_t>("deserialize"_hs);
entt::meta<ECS::EntityDataComponent>().func<&REF_SetEnabled<ECS::EntityDataComponent>, entt::as_void_t>("setEnabled"_hs);
entt::meta<ECS::EntityDataComponent>().func<&REF_Get<ECS::EntityDataComponent>, entt::as_ref_t>("get"_hs);
entt::meta<ECS::EntityDataComponent>().func<&REF_Reset<ECS::EntityDataComponent>, entt::as_void_t>("reset"_hs);
entt::meta<ECS::EntityDataComponent>().func<&REF_Has<ECS::EntityDataComponent>, entt::as_void_t>("has"_hs);
entt::meta<ECS::EntityDataComponent>().func<&REF_Remove<ECS::EntityDataComponent>, entt::as_void_t>("remove"_hs);
entt::meta<ECS::EntityDataComponent>().func<&REF_Copy<ECS::EntityDataComponent>, entt::as_void_t>("copy"_hs);
entt::meta<ECS::EntityDataComponent>().func<&REF_Paste<ECS::EntityDataComponent>, entt::as_void_t>("paste"_hs);
entt::meta<ECS::EntityDataComponent>().func<&REF_ValueChanged<ECS::EntityDataComponent>, entt::as_void_t>("add"_hs);
        //REGFUNC_END - !! DO NOT CHANGE THIS LINE !!
    }
} // namespace Lina











