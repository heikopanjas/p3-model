///
// \file modelasset.h
// \brief P3 Model Asset Base Class
// \details Base class for all digital assets used in podcast production
//

#ifndef __P3_MODEL_ASSET_H_INCL__
#define __P3_MODEL_ASSET_H_INCL__

#pragma pack(push, 8)

#include "runtimestring.h"

namespace ultralove::p3::model {
// Forward declaration
struct Contributor;

/// \brief Base class for all digital assets
/// \details Represents any digital asset used in podcast production
struct Asset
{
    /// \brief Asset URI/location
    runtime::String uri;

    /// \brief Asset author
    const Contributor* author;

    /// \brief License information
    runtime::String license;

    /// \brief Copyright information
    runtime::String copyright;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_ASSET_H_INCL__
