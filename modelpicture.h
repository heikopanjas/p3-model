///
// \file modelpicture.h
// \brief P3 Model Picture Asset
// \details Picture asset derived from Asset
//

#ifndef __P3_MODEL_PICTURE_H_INCL__
#define __P3_MODEL_PICTURE_H_INCL__

#pragma pack(push, 8)

#include "modelasset.h"
#include "modelpicturetype.h"

namespace ultralove::p3::model {
/// \brief Picture asset
/// \details Picture/image asset with type and dimensions
struct Picture : public Asset
{
    /// \brief Picture type/format
    PictureType type;

    /// \brief Picture width in pixels
    uint32_t width;

    /// \brief Picture height in pixels
    uint32_t height;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_PICTURE_H_INCL__
