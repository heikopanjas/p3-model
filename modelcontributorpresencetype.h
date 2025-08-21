///
// \file modelcontributorpresencetype.h
// \brief P3 Model Contributor Presence Type Enumeration
// \details Contributor presence platform types
//

#ifndef __P3_MODEL_CONTRIBUTOR_PRESENCE_TYPE_H_INCL__
#define __P3_MODEL_CONTRIBUTOR_PRESENCE_TYPE_H_INCL__

#pragma pack(push, 8)

namespace ultralove::p3::model {
/// \brief Contributor presence platform types
enum class ContributorPresenceType
{
    ANY,    ///< Generic presence
    TWITTER ///< Twitter presence
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_CONTRIBUTOR_PRESENCE_TYPE_H_INCL__
