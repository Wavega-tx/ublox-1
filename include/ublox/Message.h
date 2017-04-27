//
// Copyright 2015 - 2017 (C). Alex Robenko. All rights reserved.
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
/// @brief Contains common interface for all the messages of ublox binary protocol.

#pragma once

#include "comms/comms.h"

#include "MsgId.h"

namespace ublox
{

/// @brief Interface class of all the Ublox binary protocol messages.
/// @details The class publicly inherits from
///     <a href="https://dl.dropboxusercontent.com/u/46999418/comms_champion/comms/html/classcomms_1_1Message.html" target="_black">comms::Message</a>
///     class while providing the following default options:
///     @li @b comms::option::MsgIdType<MsgId> > - use @ref MsgId as the type of message ID.
///     @li @b comms::option::LittleEndian - use little endian for serialisation
///
///     All other options provided with TOptions template parameter will also be passed
///     to the @b comms::Message base class to define the interface.
/// @tparam TOptions Zero or more extra options to be passed to the @b comms::Message
///     base class to define the interface.
template <typename... TOptions>
class MessageT : public
    comms::Message<
        TOptions...,
        comms::option::LittleEndian,
        comms::option::MsgIdType<MsgId> >
{
public:

    /// @brief Default constructor
    MessageT() = default;

    /// @brief Copy constructor
    MessageT(const MessageT&) = default;

    /// @brief Move constructor
    MessageT(MessageT&&) = default;

    /// @brief Destructor
    virtual ~MessageT() = default;

    /// @brief Copy assignment operator
    MessageT& operator=(const MessageT&) = default;

    /// @brief Move assignment operator
    MessageT& operator=(MessageT&&) = default;

};

/// @brief Default Ublox interface class.
/// @details It is a redefinition of MessageT class with extra following options:
///     @li <b> comms::option::ReadIterator<const std::uint8_t*></b> -
///         Enables read operation and specifies <b>const std::uint8_t*</b> as
///         the iterator used for reading.
///     @li <b> comms::option::WriteIterator<std::uint8_t*></b> -
///         Enables write operation and specifies <b>std::uint8_t*</b> as
///         the iterator used for writing.
using Message = MessageT<
    comms::option::ReadIterator<const std::uint8_t*>,
    comms::option::WriteIterator<std::uint8_t*>
>;

}  // namespace ublox


