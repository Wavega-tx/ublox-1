//
// Copyright 2015 - 2016 (C). Alex Robenko. All rights reserved.
//

// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/// @file
/// @brief Contains definition of CFG-RXM message and its fields.

#pragma once

#include <algorithm>

#include "ublox/Message.h"
#include "ublox/field/common.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the CFG-RXM message fields.
/// @see CfgRxm
struct CfgRxmFields
{
    /// @brief Value enumeration for @ref lpMode field.
    enum class LowPowerMode : std::uint8_t
    {
        MaxPerformance, ///< Max performance mode
        PowerSave, ///< Power save mode
        Eco = 4 ///< Eco mode
    };

    /// @brief Custom value validator for @ref lpMode field.
    struct LowPowerModeValidator
    {
        template <typename TField>
        bool operator()(const TField& field) const
        {
            auto value = field.value();

            static const LowPowerMode ValidValues[] = {
                LowPowerMode::MaxPerformance,
                LowPowerMode::PowerSave,
                LowPowerMode::Eco
            };

            auto iter = std::lower_bound(std::begin(ValidValues), std::end(ValidValues), value);
            return (iter != std::end(ValidValues)) && (*iter == value);
        }
    };

    /// @brief Definition of "reserved1" field.
    using reserved1 =
        field::common::U1T<
            comms::option::DefaultNumValue<8>,
            comms::option::ValidNumValueRange<8, 8>
        >;

    /// @brief Definition of "lpMode" field.
    using lpMode =
        field::common::EnumT<
            LowPowerMode,
            comms::option::ContentsValidator<LowPowerModeValidator>
        >;

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        reserved1,
        lpMode
    >;
};

/// @brief Definition of CFG-RXM message
/// @details Inherits from @b comms::MessageBase
///     while providing @b TMsgBase as common interface class as well as
///     various implementation options. @n
///     See @ref CfgRxmFields and for definition of the fields this message contains.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class CfgRxm : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_RXM>,
        comms::option::FieldsImpl<CfgRxmFields::All>,
        comms::option::MsgType<CfgRxm<TMsgBase> >,
        comms::option::DispatchImpl
    >
{
    typedef comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_RXM>,
        comms::option::FieldsImpl<CfgRxmFields::All>,
        comms::option::MsgType<CfgRxm<TMsgBase> >,
        comms::option::DispatchImpl
    > Base;
public:

#ifdef FOR_DOXYGEN_DOC_ONLY
    /// @brief Index to access the fields
    enum FieldIdx
    {
        FieldIdx_reserved1, ///< @b reserved1 field, see @ref CfgRxmFields::reserved1
        FieldIdx_lpMode,  ///< @b lpMode field, see @ref CfgRxmFields::lpMode
        FieldIdx_numOfValues ///< number of available fields
    };
    /// @brief Access to fields bundled as a struct
    struct FieldsAsStruct
    {
        CfgRxmFields::reserved1& reserved1; ///< @b reserved1 field, see @ref CfgRxmFields::reserved1
        CfgRxmFields::lpMode& lpMode;  ///< @b lpMode field, see @ref CfgRxmFields::lpMode
    };

    /// @brief Access to @b const fields bundled as a struct
    struct ConstFieldsAsStruct
    {
        const CfgRxmFields::reserved1& reserved1; ///< @b reserved1 field, see @ref CfgRxmFields::reserved1
        const CfgRxmFields::lpMode& lpMode;  ///< @b lpMode field, see @ref CfgRxmFields::lpMode
    };

    /// @brief Get access to fields bundled into a struct
    FieldsAsStruct fieldsAsStruct();

    /// @brief Get access to @b const fields bundled into a struct
    ConstFieldsAsStruct fieldsAsStruct() const;

#else
    COMMS_MSG_FIELDS_ACCESS(Base, reserved1, lpMode);
#endif // #ifdef FOR_DOXYGEN_DOC_ONLY

    /// @brief Default constructor
    CfgRxm() = default;

    /// @brief Copy constructor
    CfgRxm(const CfgRxm&) = default;

    /// @brief Move constructor
    CfgRxm(CfgRxm&& other) = default;

    /// @brief Destructor
    virtual ~CfgRxm() = default;

    /// @brief Copy assignment
    CfgRxm& operator=(const CfgRxm&) = default;

    /// @brief Move assignment
    CfgRxm& operator=(CfgRxm&&) = default;
};


}  // namespace message

}  // namespace ublox

