///
// \file modelenumerations.h
// \brief P3 Model Enumerations
// \details Enumeration definitions for the Podcast Production and Publishing (P3) Model library
//

#ifndef __P3_MODEL_ENUMERATIONS_H_INCL__
#define __P3_MODEL_ENUMERATIONS_H_INCL__

#pragma pack(push, 8)

#include "runtimestring.h"

namespace ultralove::p3::model {
/// \brief Role types for contributors in podcast production
enum class ContributorRole
{
    OWNER,     ///< Podcast owner
    HOST,      ///< Episode host
    GUEST,     ///< Episode guest
    PUBLISHER, ///< Content publisher
    AUTHOR     ///< Content author
};

/// \brief Episode type classifications
enum class EpisodeType
{
    FULL,    ///< Full episode
    TRAILER, ///< Trailer episode
    BONUS    ///< Bonus episode
};

/// \brief Contributor presence platform types
enum class ContributorPresenceType
{
    ANY,    ///< Generic presence
    TWITTER ///< Twitter presence
};

/// \brief Tag reference source types
enum class TagReferenceType
{
    ANY,       ///< Generic reference
    WIKIPEDIA, ///< Wikipedia reference
    WIKIDATA   ///< Wikidata reference
};

/// \brief Picture format types
enum class PictureType
{
    JPG, ///< JPEG format
    PNG  ///< PNG format
};

/// \brief Audio/video enclosure format types
enum class EnclosureType
{
    MP3, ///< MP3 audio format
    MP4, ///< MP4 video format
    OGG, ///< OGG audio format
    OPUS ///< OPUS audio format
};

/// \brief Utility functions for enumeration conversions
namespace EnumUtils {
/// \brief Convert ContributorRole to string
/// \param role The role to convert
/// \return String representation of the role
runtime::String ToString(const ContributorRole role);

/// \brief Convert EpisodeType to string
/// \param type The episode type to convert
/// \return String representation of the episode type
runtime::String ToString(const EpisodeType type);

/// \brief Convert ContributorPresenceType to string
/// \param type The presence type to convert
/// \return String representation of the presence type
runtime::String ToString(const ContributorPresenceType type);

/// \brief Convert TagReferenceType to string
/// \param type The reference type to convert
/// \return String representation of the reference type
runtime::String ToString(const TagReferenceType type);

/// \brief Convert PictureType to string
/// \param type The picture type to convert
/// \return String representation of the picture type
runtime::String ToString(const PictureType type);

/// \brief Convert EnclosureType to string
/// \param type The enclosure type to convert
/// \return String representation of the enclosure type
runtime::String ToString(const EnclosureType type);
} // namespace EnumUtils
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_ENUMERATIONS_H_INCL__
