/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ClientConfigPackets_h__
#define ClientConfigPackets_h__

#include "Packet.h"
#include "AddonMgr.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace ClientConfig
    {
        class AddonInfo final : public ServerPacket
        {
            static uint8 const PublicKey[256];

        public:
            AddonInfo() : ServerPacket(SMSG_ADDON_INFO) { }

            WorldPacket const* Write() override;

            std::list<::AddonInfo> const* Addons = nullptr;
            std::list<BannedAddon> const* BannedAddons = nullptr;
        };

        class AccountDataTimes final : public ServerPacket
        {
        public:
            AccountDataTimes() : ServerPacket(SMSG_ACCOUNT_DATA_TIMES, 4 + 4 * NUM_ACCOUNT_DATA_TYPES) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGuid;
            uint32 ServerTime = 0;
            uint32 AccountTimes[NUM_ACCOUNT_DATA_TYPES];
        };
    }
}

#endif // ClientConfigPackets_h__