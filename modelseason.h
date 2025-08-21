///
// \file modelseason.h
// \brief P3 Model Season
// \details Season struct representing a podcast season
//

#ifndef __P3_MODEL_SEASON_H_INCL__
#define __P3_MODEL_SEASON_H_INCL__

#pragma pack(push, 8)

#include "modelcontribution.h"
#include "modelepisode.h"
#include "modelfabric.h"
#include "modelpicture.h"
#include "modeltagreference.h"
#include "runtimestring.h"
#include "runtimetimestamp.h"
#include <vector>

namespace ultralove::p3::model {
/// \brief Season representation
/// \details Represents a podcast season within a series
struct Season : public Fabric
{
    /// \brief Season number
    uint32_t seasonNumber;

    /// \brief Season title
    runtime::String title;

    /// \brief Season description
    runtime::String description;

    /// \brief Season publication date
    runtime::Timestamp publicationDate;

    /// \brief Season cover art
    Picture coverArt;

    /// \brief Associated tags
    std::vector<TagReference> tags;

    /// \brief Contributors
    std::vector<Contribution> contributors;

    /// \brief Episodes in this season
    std::vector<Episode> episodes;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_SEASON_H_INCL__
