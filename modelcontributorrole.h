///
// \file modelcontributorrole.h
// \brief P3 Model Contributor Role Enumeration
// \details Role types for contributors in podcast production
//

#ifndef __P3_MODEL_CONTRIBUTOR_ROLE_H_INCL__
#define __P3_MODEL_CONTRIBUTOR_ROLE_H_INCL__

#pragma pack(push, 8)

namespace ultralove::p3::model {
/// \brief Role types for contributors in podcast production
enum class ContributorRole
{
    OWNER,     ///< Podcast owner
    HOST,      ///< Episode host
    GUEST,     ///< Episode guest
    PUBLISHER, ///< Content publisher
    AUTHOR     ///< Content author
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_CONTRIBUTOR_ROLE_H_INCL__
