///
// \file modelenclosuretype.h
// \brief P3 Model Enclosure Type Enumeration
// \details Audio/video enclosure format types
//

#ifndef __P3_MODEL_ENCLOSURE_TYPE_H_INCL__
#define __P3_MODEL_ENCLOSURE_TYPE_H_INCL__

#pragma pack(push, 8)

namespace ultralove::p3::model {
/// \brief Audio/video enclosure format types
enum class EnclosureType
{
    MP3, ///< MP3 audio format
    MP4, ///< MP4 video format
    OGG, ///< OGG audio format
    OPUS ///< OPUS audio format
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_ENCLOSURE_TYPE_H_INCL__
