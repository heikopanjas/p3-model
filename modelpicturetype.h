///
// \file modelpicturetype.h
// \brief P3 Model Picture Type Enumeration
// \details Picture format types
//

#ifndef __P3_MODEL_PICTURE_TYPE_H_INCL__
#define __P3_MODEL_PICTURE_TYPE_H_INCL__

#pragma pack(push, 8)

namespace ultralove::p3::model {
/// \brief Picture format types
enum class PictureType
{
    JPG, ///< JPEG format
    PNG  ///< PNG format
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_PICTURE_TYPE_H_INCL__
