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
/// @brief Contains definition of CFG-ANT message and its fields.

#pragma once

#include "ublox/Message.h"
#include "ublox/field/common.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the CFG-ANT message fields.
/// @see CfgAnt
struct CfgAntFields
{

    /// @brief Bits access enumeration for @ref flags bitmask field.
    enum
    {
        flags_svcs, ///< @b svcs bit index
        flags_csd, ///< @b csd bit index
        flags_ocd, ///< @b ocd bit index
        flags_pdwnOnSCD, ///< @b pdwnOnSCD bit index
        flags_recovery, ///< @b recovery bit index
        flags_numOfValues ///< number of available bits
    };

    /// @brief Use this enumeration to access member fields of @ref pins bitfield.
    enum
    {
        pins_pinSwitch, ///< @b index of @b pinSwith member field
        pins_pinSCD, ///< @b index of @b pinSCD member field
        pins_pinOCD, ///< @b index of @b pinOCD member field
        pins_reconfig, ///< @b index of @b reconfig member field
        pins_numOfValues ///< number of member fields
    };

    /// @brief Bits access enumeration for bits in @b reconfig member of
    ///     @ref pins bitfield field.
    enum
    {
        pins_reconfig_reconfig, ///< internal index of @b reconfig bit
        pins_reconfig_numOfValues ///< number of available bits
    };

    /// @brief Definition of "flags" field.
    using flags =
        field::common::X2T<
            comms::option::BitmaskReservedBits<0xffe0, 0>
        >;

    /// @brief Common definition of @b pinSwitch, @b pinSCD, and @b pinOCD member
    ///     fields of @ref pins bitfield field.
    using pinX =
        field::common::U1T<
            comms::option::FixedBitLength<5>,
            comms::option::ValidNumValueRange<0, 0x1f>
        >;

    /// @brief Definition of "pins" field.
    using pins =
        field::common::BitfieldT<
            std::tuple<
                pinX,
                pinX,
                pinX,
                field::common::X1T<
                    comms::option::FixedBitLength<1>
                >
            >
        >;

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        flags,
        pins
    >;
};

/// @brief Definition of CFG-ANT message
/// @details Inherits from @b comms::MessageBase
///     while providing @b TMsgBase as common interface class as well as
///     various implementation options. @n
///     See @ref CfgAntFields and for definition of the fields this message contains.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class CfgAnt : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_ANT>,
        comms::option::FieldsImpl<CfgAntFields::All>,
        comms::option::MsgType<CfgAnt<TMsgBase> >,
        comms::option::DispatchImpl
    >
{
    typedef comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_ANT>,
        comms::option::FieldsImpl<CfgAntFields::All>,
        comms::option::MsgType<CfgAnt<TMsgBase> >,
        comms::option::DispatchImpl
    > Base;
public:

#ifdef FOR_DOXYGEN_DOC_ONLY
    /// @brief Index to access the fields
    enum FieldIdx
    {
        FieldIdx_flags, ///< @b flags field, see @ref CfgAntFields::flags
        FieldIdx_pins, ///< @b pins field, see @ref CfgAntFields::pins
        FieldIdx_numOfValues ///< number of available fields
    };

    /// @brief Access to fields bundled as a struct
    struct FieldsAsStruct
    {
        CfgAntFields::flags& flags; ///< @b flags field, see @ref CfgAntFields::flags
        CfgAntFields::pins& pins; ///< @b pins field, see @ref CfgAntFields::pins
    };

    /// @brief Access to @b const fields bundled as a struct
    struct ConstFieldsAsStruct
    {
        const CfgAntFields::flags& flags; ///< @b flags field, see @ref CfgAntFields::flags
        const CfgAntFields::pins& pins; ///< @b pins field, see @ref CfgAntFields::pins
    };

    /// @brief Get access to fields bundled into a struct
    FieldsAsStruct fieldsAsStruct();

    /// @brief Get access to @b const fields bundled into a struct
    ConstFieldsAsStruct fieldsAsStruct() const;

#else
    COMMS_MSG_FIELDS_ACCESS(Base, flags, pins);
#endif // #ifdef FOR_DOXYGEN_DOC_ONLY

    /// @brief Default constructor
    CfgAnt() = default;

    /// @brief Copy constructor
    CfgAnt(const CfgAnt&) = default;

    /// @brief Move constructor
    CfgAnt(CfgAnt&& other) = default;

    /// @brief Destructor
    virtual ~CfgAnt() = default;

    /// @brief Copy assignment
    CfgAnt& operator=(const CfgAnt&) = default;

    /// @brief Move assignment
    CfgAnt& operator=(CfgAnt&&) = default;
};

}  // namespace message

}  // namespace ublox

