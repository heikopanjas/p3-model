///
// \file modeltag.h
// \brief P3 Model Tag
// \details Base tag struct for content classification
//

#ifndef __P3_MODEL_TAG_H_INCL__
#define __P3_MODEL_TAG_H_INCL__

#pragma pack(push, 8)

#include "modelcontributor.h"
#include "modelfabric.h"
#include "runtimestring.h"

namespace ultralove::p3::model {
/// \brief Base tag class
/// \details Base class for all content classification tags
struct Tag : public Fabric
{
    /// \brief Tag name/label
    runtime::String name;

    /// \brief Tag description
    runtime::String description;

    /// \brief Tag creator
    Contributor creator;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_TAG_H_INCL__
