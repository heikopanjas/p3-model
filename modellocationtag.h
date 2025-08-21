///
// \file modellocationtag.h
// \brief P3 Model Location Tag
// \details Location tag derived from Tag
//

#ifndef __P3_MODEL_LOCATION_TAG_H_INCL__
#define __P3_MODEL_LOCATION_TAG_H_INCL__

#pragma pack(push, 8)

#include "modeltag.h"
#include "runtimestring.h"

namespace ultralove::p3::model {
/// \brief Location tag
/// \details Tag representing a geographical location
struct LocationTag : public Tag
{
    /// \brief Location address
    runtime::String address;

    /// \brief Latitude coordinate
    double latitude;

    /// \brief Longitude coordinate
    double longitude;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_LOCATION_TAG_H_INCL__
