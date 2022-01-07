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
#include "Depth1/Depth2/Test2.hpp"
#include "Depth1/Depth2/Test2.hpp"
#include "Depth1/Depth2/Test2.hpp"
#include "Depth1/Depth2/Test2.hpp"
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
entt::meta<ECS::SpotLightComponent>().type().props(std::make_pair("Title"_hs, "Spot Light Component"), std::make_pair("Icon"_hs,ICON_FA_EYE), std::make_pair("Category"_hs,"Lights"));
entt::meta<ECS::SpotLightComponent>().data<&ECS::SpotLightComponent::m_isEnabled>("m_isEnabled"_hs);
entt::meta<ECS::SpotLightComponent>().data<&ECS::SpotLightComponent::m_distance>("m_distance"_hs).props(std::make_pair("Title"_hs,"Distance"),std::make_pair("Type"_hs,"Float"),std::make_pair("Tooltip"_hs,"Light Distance"),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::SpotLightComponent>().data<&ECS::SpotLightComponent::m_cutoff>("m_cutoff"_hs).props(std::make_pair("Title"_hs,"Cutoff"),std::make_pair("Type"_hs,"Float"),std::make_pair("Tooltip"_hs,"The light will gradually dim from the edges of the cone defined by the Cutoff, to the cone defined by the Outer Cutoff."),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::SpotLightComponent>().data<&ECS::SpotLightComponent::m_outerCutoff>("m_outerCutoff"_hs).props(std::make_pair("Title"_hs,"Outer Cutoff"),std::make_pair("Type"_hs,"Float"),std::make_pair("Tooltip"_hs,"The light will gradually dim from the edges of the cone defined by the Cutoff, to the cone defined by the Outer Cutoff."),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::SpotLightComponent>().func<&REF_CloneComponent<ECS::SpotLightComponent>, entt::as_void_t>("clone"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_SerializeComponent<ECS::SpotLightComponent>, entt::as_void_t>("serialize"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_DeserializeComponent<ECS::SpotLightComponent>, entt::as_void_t>("deserialize"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_SetEnabled<ECS::SpotLightComponent>, entt::as_void_t>("setEnabled"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_Get<ECS::SpotLightComponent>, entt::as_ref_t>("get"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_Reset<ECS::SpotLightComponent>, entt::as_void_t>("reset"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_Has<ECS::SpotLightComponent>, entt::as_void_t>("has"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_Remove<ECS::SpotLightComponent>, entt::as_void_t>("remove"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_Copy<ECS::SpotLightComponent>, entt::as_void_t>("copy"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_Paste<ECS::SpotLightComponent>, entt::as_void_t>("paste"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_Add<ECS::SpotLightComponent>, entt::as_void_t>("add"_hs);
entt::meta<ECS::SpotLightComponent>().func<&REF_ValueChanged<ECS::SpotLightComponent>, entt::as_void_t>("add"_hs);
entt::meta<ECS::LightComponent>().type().props(std::make_pair("Title"_hs, "Light Component"), std::make_pair("Icon"_hs,ICON_FA_EYE), std::make_pair("Category"_hs,"Lights"));
entt::meta<ECS::LightComponent>().data<&ECS::LightComponent::m_isEnabled>("m_isEnabled"_hs);
entt::meta<ECS::LightComponent>().data<&ECS::LightComponent::m_color>("m_color"_hs).props(std::make_pair("Title"_hs,"Color"),std::make_pair("Type"_hs,"Color"),std::make_pair("Tooltip"_hs,""),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::LightComponent>().data<&ECS::LightComponent::m_intensity>("m_intensity"_hs).props(std::make_pair("Title"_hs,"Intensity"),std::make_pair("Type"_hs,"Float"),std::make_pair("Tooltip"_hs,""),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::LightComponent>().data<&ECS::LightComponent::m_drawDebug>("m_drawDebug"_hs).props(std::make_pair("Title"_hs,"Draw Debug"),std::make_pair("Type"_hs,"Bool"),std::make_pair("Tooltip"_hs,"Enables debug drawing for this component."),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::LightComponent>().data<&ECS::LightComponent::m_castsShadows>("m_castsShadows"_hs).props(std::make_pair("Title"_hs,"Cast Shadows"),std::make_pair("Type"_hs,"Bool"),std::make_pair("Tooltip"_hs,"Enables dynamic shadow casting for this light."),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::LightComponent>().func<&REF_CloneComponent<ECS::LightComponent>, entt::as_void_t>("clone"_hs);
entt::meta<ECS::LightComponent>().func<&REF_SerializeComponent<ECS::LightComponent>, entt::as_void_t>("serialize"_hs);
entt::meta<ECS::LightComponent>().func<&REF_DeserializeComponent<ECS::LightComponent>, entt::as_void_t>("deserialize"_hs);
entt::meta<ECS::LightComponent>().func<&REF_SetEnabled<ECS::LightComponent>, entt::as_void_t>("setEnabled"_hs);
entt::meta<ECS::LightComponent>().func<&REF_Get<ECS::LightComponent>, entt::as_ref_t>("get"_hs);
entt::meta<ECS::LightComponent>().func<&REF_Reset<ECS::LightComponent>, entt::as_void_t>("reset"_hs);
entt::meta<ECS::LightComponent>().func<&REF_Has<ECS::LightComponent>, entt::as_void_t>("has"_hs);
entt::meta<ECS::LightComponent>().func<&REF_Remove<ECS::LightComponent>, entt::as_void_t>("remove"_hs);
entt::meta<ECS::LightComponent>().func<&REF_Copy<ECS::LightComponent>, entt::as_void_t>("copy"_hs);
entt::meta<ECS::LightComponent>().func<&REF_Paste<ECS::LightComponent>, entt::as_void_t>("paste"_hs);
entt::meta<ECS::LightComponent>().func<&REF_Add<ECS::LightComponent>, entt::as_void_t>("add"_hs);
entt::meta<ECS::LightComponent>().func<&REF_ValueChanged<ECS::LightComponent>, entt::as_void_t>("add"_hs);
entt::meta<ECS::PointLightComponent>().type().props(std::make_pair("Title"_hs, "Point Light Component"), std::make_pair("Icon"_hs,ICON_FA_EYE), std::make_pair("Category"_hs,"Lights"));
entt::meta<ECS::PointLightComponent>().data<&ECS::PointLightComponent::m_isEnabled>("m_isEnabled"_hs);
entt::meta<ECS::PointLightComponent>().data<&ECS::PointLightComponent::m_distance>("m_distance"_hs).props(std::make_pair("Title"_hs,"Distance"),std::make_pair("Type"_hs,"Float"),std::make_pair("Tooltip"_hs,"Light Distance"),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::PointLightComponent>().data<&ECS::PointLightComponent::m_bias>("m_bias"_hs).props(std::make_pair("Title"_hs,"Bias"),std::make_pair("Type"_hs,"Float"),std::make_pair("Tooltip"_hs,"Defines the shadow crispiness."),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::PointLightComponent>().data<&ECS::PointLightComponent::m_shadowNear>("m_shadowNear"_hs).props(std::make_pair("Title"_hs,"Shadow Near"),std::make_pair("Type"_hs,"Float"),std::make_pair("Tooltip"_hs,""),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::PointLightComponent>().data<&ECS::PointLightComponent::m_shadowFar>("m_shadowFar"_hs).props(std::make_pair("Title"_hs,"Shadow Far"),std::make_pair("Type"_hs,"Float"),std::make_pair("Tooltip"_hs,""),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::PointLightComponent>().func<&REF_CloneComponent<ECS::PointLightComponent>, entt::as_void_t>("clone"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_SerializeComponent<ECS::PointLightComponent>, entt::as_void_t>("serialize"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_DeserializeComponent<ECS::PointLightComponent>, entt::as_void_t>("deserialize"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_SetEnabled<ECS::PointLightComponent>, entt::as_void_t>("setEnabled"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_Get<ECS::PointLightComponent>, entt::as_ref_t>("get"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_Reset<ECS::PointLightComponent>, entt::as_void_t>("reset"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_Has<ECS::PointLightComponent>, entt::as_void_t>("has"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_Remove<ECS::PointLightComponent>, entt::as_void_t>("remove"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_Copy<ECS::PointLightComponent>, entt::as_void_t>("copy"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_Paste<ECS::PointLightComponent>, entt::as_void_t>("paste"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_Add<ECS::PointLightComponent>, entt::as_void_t>("add"_hs);
entt::meta<ECS::PointLightComponent>().func<&REF_ValueChanged<ECS::PointLightComponent>, entt::as_void_t>("add"_hs);
entt::meta<ECS::DirectionalLightComponent>().type().props(std::make_pair("Title"_hs, "Directional Light Component"), std::make_pair("Icon"_hs,ICON_FA_EYE), std::make_pair("Category"_hs,"Lights"));
entt::meta<ECS::DirectionalLightComponent>().data<&ECS::DirectionalLightComponent::m_isEnabled>("m_isEnabled"_hs);
entt::meta<ECS::DirectionalLightComponent>().data<&ECS::DirectionalLightComponent::m_shadowOrthoProjection>("m_shadowOrthoProjection"_hs).props(std::make_pair("Title"_hs,"Projection"),std::make_pair("Type"_hs,"Vector4"),std::make_pair("Tooltip"_hs,"Defines shadow projection boundaries."),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::DirectionalLightComponent>().data<&ECS::DirectionalLightComponent::m_shadowZNear>("m_shadowZNear"_hs).props(std::make_pair("Title"_hs,"Shadow Near"),std::make_pair("Type"_hs,"Float"),std::make_pair("Tooltip"_hs,""),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::DirectionalLightComponent>().data<&ECS::DirectionalLightComponent::m_shadowZFar>("m_shadowZFar"_hs).props(std::make_pair("Title"_hs,"Shadow Far"),std::make_pair("Type"_hs,"Float"),std::make_pair("Tooltip"_hs,""),std::make_pair("Depends"_hs,""_hs));
entt::meta<ECS::DirectionalLightComponent>().func<&REF_CloneComponent<ECS::DirectionalLightComponent>, entt::as_void_t>("clone"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_SerializeComponent<ECS::DirectionalLightComponent>, entt::as_void_t>("serialize"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_DeserializeComponent<ECS::DirectionalLightComponent>, entt::as_void_t>("deserialize"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_SetEnabled<ECS::DirectionalLightComponent>, entt::as_void_t>("setEnabled"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_Get<ECS::DirectionalLightComponent>, entt::as_ref_t>("get"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_Reset<ECS::DirectionalLightComponent>, entt::as_void_t>("reset"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_Has<ECS::DirectionalLightComponent>, entt::as_void_t>("has"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_Remove<ECS::DirectionalLightComponent>, entt::as_void_t>("remove"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_Copy<ECS::DirectionalLightComponent>, entt::as_void_t>("copy"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_Paste<ECS::DirectionalLightComponent>, entt::as_void_t>("paste"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_Add<ECS::DirectionalLightComponent>, entt::as_void_t>("add"_hs);
entt::meta<ECS::DirectionalLightComponent>().func<&REF_ValueChanged<ECS::DirectionalLightComponent>, entt::as_void_t>("add"_hs);
entt::meta<ECS::EntityDataComponent>().type().props("Title"_hs, "Entity Data Component");
        //REGFUNC_END - !! DO NOT CHANGE THIS LINE !!
    }
} // namespace Lina













































