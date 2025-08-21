///
// \file modelcontribution.h
// \brief P3 Model Contribution
// \details Contribution relationship between contributor and content
//

#ifndef __P3_MODEL_CONTRIBUTION_H_INCL__
#define __P3_MODEL_CONTRIBUTION_H_INCL__

#pragma pack(push, 8)

#include "modelcontributor.h"
#include "runtimestring.h"

namespace ultralove::p3::model {
/// \brief Contribution relationship
/// \details Represents a contributor's contribution to content
struct Contribution
{
    /// \brief Contributing person
    Contributor contributor;

    /// \brief Contribution type/role
    runtime::String type;

    /// \brief Additional contribution notes
    runtime::String notes;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_CONTRIBUTION_H_INCL__
