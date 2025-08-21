///
// \file modelpublisher.h
// \brief P3 Model Publisher
// \details Publisher struct for podcast publishers
//

#ifndef __P3_MODEL_PUBLISHER_H_INCL__
#define __P3_MODEL_PUBLISHER_H_INCL__

#pragma pack(push, 8)

#include "modelfabric.h"
#include "runtimeguid.h"
#include "runtimestring.h"

namespace ultralove::p3::model {
/// \brief Publisher representation
/// \details Represents a podcast publisher/network
struct Publisher : public Fabric
{
    /// \brief Publisher name
    runtime::String name;

    /// \brief Publisher email
    runtime::String email;

    /// \brief Publisher website URL
    runtime::String url;

    /// \brief Publisher description
    runtime::String description;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_PUBLISHER_H_INCL__
