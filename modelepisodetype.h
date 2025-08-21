///
// \file modelepisodetype.h
// \brief P3 Model Episode Type Enumeration
// \details Episode type classifications
//

#ifndef __P3_MODEL_EPISODE_TYPE_H_INCL__
#define __P3_MODEL_EPISODE_TYPE_H_INCL__

#pragma pack(push, 8)

namespace ultralove::p3::model {
/// \brief Episode type classifications
enum class EpisodeType
{
    FULL,    ///< Full episode
    TRAILER, ///< Trailer episode
    BONUS    ///< Bonus episode
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_EPISODE_TYPE_H_INCL__
