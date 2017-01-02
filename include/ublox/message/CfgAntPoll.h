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
/// @brief Contains definition of CFG-ANT (@b poll) message and its fields.

#pragma once

#include "ublox/Message.h"

namespace ublox
{

namespace message
{

/// @brief Accumulates details of all the CFG-ANT (@b poll) message fields.
/// @see CfgAntPoll
struct CfgAntPollFields
{
    using All = std::tuple<>;
};

/// @brief Definition of CFG-ANT (@b poll) message
/// @details Inherits from @b comms::MessageBase
///     while providing @b TMsgBase as common interface class as well as
///     various implementation options. @n
///     See @ref CfgAntPollFields and for definition of the fields this message contains.
/// @tparam TMsgBase Common interface class for all the messages.
template <typename TMsgBase = Message>
class CfgAntPoll : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_ANT>,
        comms::option::FieldsImpl<CfgAntPollFields::All>,
        comms::option::MsgType<CfgAntPoll<TMsgBase> >,
        comms::option::DispatchImpl
    >
{
    typedef comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<MsgId_CFG_ANT>,
        comms::option::FieldsImpl<CfgAntPollFields::All>,
        comms::option::MsgType<CfgAntPoll<TMsgBase> >,
        comms::option::DispatchImpl
    > Base;
public:

    /// @brief Index to access the fields
    enum FieldIdx
    {
        FieldIdx_numOfValues ///< number of available fields
    };

    static_assert(std::tuple_size<typename Base::AllFields>::value == FieldIdx_numOfValues,
        "Number of fields is incorrect");

    /// @brief Default constructor
    CfgAntPoll() = default;

    /// @brief Copy constructor
    CfgAntPoll(const CfgAntPoll&) = default;

    /// @brief Move constructor
    CfgAntPoll(CfgAntPoll&& other) = default;

    /// @brief Destructor
    virtual ~CfgAntPoll() = default;

    /// @brief Copy assignment
    CfgAntPoll& operator=(const CfgAntPoll&) = default;

    /// @brief Move assignment
    CfgAntPoll& operator=(CfgAntPoll&&) = default;
};


}  // namespace message

}  // namespace ublox

