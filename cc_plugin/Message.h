//
// Copyright 2015 (C). Alex Robenko. All rights reserved.
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


#pragma once

#include "comms_champion/comms_champion.h"
#include "ublox/Message.h"


namespace ublox
{

namespace cc_plugin
{

template <typename... TOptions>
class MessageT : public comms_champion::MessageBase<ublox::MessageT, TOptions...>
{
    typedef comms_champion::MessageBase<ublox::MessageT, TOptions...> Base;
public:
    virtual ~MessageT() = default;

    bool isPoll() const
    {
        return m_isPoll;
    }

protected:
    void setPoll()
    {
        m_isPoll = true;
    }

    virtual QString idAsStringImpl() const override
    {
        return QString("0x%1").arg(Base::getId(), 4, 16, QChar('0'));
    }

    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props;
        return Props;
    }

private:
    bool m_isPoll = false;
};

typedef MessageT<> Message;

}  // namespace cc_plugin

}  // namespace ublox
