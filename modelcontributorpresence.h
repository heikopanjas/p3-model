///
// \file modelcontributorpresence.h
// \brief P3 Model Contributor Presence
// \details Represents presence of contributor in podcast content
//

#ifndef __P3_MODEL_CONTRIBUTOR_PRESENCE_H_INCL__
#define __P3_MODEL_CONTRIBUTOR_PRESENCE_H_INCL__

#pragma pack(push, 8)

#include "runtimetimespan.h"

namespace ultralove::p3::model {
/// \brief Contributor presence
/// \details Represents when and how long a contributor is present
struct ContributorPresence
{
    /// \brief Start time of presence
    runtime::Timespan startTime;

    /// \brief End time of presence
    runtime::Timespan endTime;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_CONTRIBUTOR_PRESENCE_H_INCL__
