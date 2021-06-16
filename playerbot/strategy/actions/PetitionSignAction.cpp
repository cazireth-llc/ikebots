#include "botpch.h"
#include "../../playerbot.h"
#include "PetitionSignAction.h"
#ifndef MANGOSBOT_ZERO
#ifdef CMANGOS
#include "Arena/ArenaTeam.h"
#endif
#ifdef MANGOS
#include "ArenaTeam.h"
#endif
#endif

using namespace std;
using namespace ai;

bool PetitionSignAction::Execute(Event event)
{
    WorldPacket p(event.getPacket());
    p.rpos(0);
    ObjectGuid petitionGuid;
    ObjectGuid inviter;
    uint8 unk = 0;
    bool isArena = false;
    p >> petitionGuid >> inviter;

    QueryResult* result = CharacterDatabase.PQuery("SELECT `type` FROM `petition` WHERE `petitionguid` = '%u'", petitionGuid.GetCounter());
    if (!result)
    {
        return false;
    }

    Field* fields = result->Fetch();
    uint32 type = fields[0].GetUInt32();
    delete result;

    bool accept = true;

    if (type != 9)
    {
#ifndef MANGOSBOT_ZERO
        isArena = true;
        uint8 slot = ArenaTeam::GetSlotByType(ArenaType(type));
        if (bot->GetArenaTeamId(slot))
        {
            // player is already in an arena team
            ai->TellError("Sorry, I am already in such team");
            accept = false;
        }
#endif
    }
    else
    {
        if (bot->GetGuildId())
        {
            ai->TellError("Sorry, I am in a guild already");
            accept = false;
        }

        if (bot->GetGuildIdInvited())
        {
            ai->TellError("Sorry, I am invited to a guild already");
            accept = false;
        }
    }

    Player* _inviter = sObjectMgr.GetPlayer(inviter);
    if (!inviter)
        return false;

    if (!accept /*|| !ai->GetSecurity()->CheckLevelFor(PLAYERBOT_SECURITY_INVITE, false, _inviter, true)*/)
    {
        WorldPacket data(MSG_PETITION_DECLINE);
        p << petitionGuid;
        bot->GetSession()->HandlePetitionDeclineOpcode(data);
        sLog.outBasic("Bot #%d <%s> declines %s invite", bot->GetGUIDLow(), bot->GetName(), isArena ? "Arena" : "Guild");
        return false;
    }
    if (accept)
    {
        WorldPacket data(CMSG_PETITION_SIGN, 20);
        data << petitionGuid << unk;
        bot->GetSession()->HandlePetitionSignOpcode(data);
        bot->Say("Thanks for the invite!", LANG_UNIVERSAL);
        sLog.outBasic("Bot #%d <%s> accepts %s invite", bot->GetGUIDLow(), bot->GetName(), isArena ? "Arena" : "Guild");
        return true;
    }
    return false;
}
