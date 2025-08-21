///
// \file modeltagreference.h
// \brief P3 Model Tag Reference
// \details Reference to tag with weight
//

#ifndef __P3_MODEL_TAG_REFERENCE_H_INCL__
#define __P3_MODEL_TAG_REFERENCE_H_INCL__

#pragma pack(push, 8)

#include "modeltag.h"

namespace ultralove::p3::model {
/// \brief Tag reference
/// \details Reference to a tag with associated weight
struct TagReference
{
    /// \brief Referenced tag
    Tag tag;

    /// \brief Tag weight/relevance (0.0-1.0)
    double weight;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_TAG_REFERENCE_H_INCL__
