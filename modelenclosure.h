///
// \file modelenclosure.h
// \brief P3 Model Enclosure Asset
// \details Enclosure asset derived from Asset
//

#ifndef __P3_MODEL_ENCLOSURE_H_INCL__
#define __P3_MODEL_ENCLOSURE_H_INCL__

#pragma pack(push, 8)

#include "modelasset.h"
#include "modelenumerations.h"
#include "runtimestring.h"

namespace ultralove::p3::model {
/// \brief Enclosure asset
/// \details Media enclosure asset with type, MIME type and file size
struct Enclosure : public Asset
{
    /// \brief Enclosure type
    EnclosureType type;

    /// \brief MIME type
    runtime::String mimeType;

    /// \brief File size in bytes
    uint64_t fileSize;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_ENCLOSURE_H_INCL__
