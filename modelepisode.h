///
// \file modelepisode.h
// \brief P3 Model Episode
// \details Episode struct representing a single podcast episode
//

#ifndef __P3_MODEL_EPISODE_H_INCL__
#define __P3_MODEL_EPISODE_H_INCL__

#pragma pack(push, 8)

#include "modelcontribution.h"
#include "modelenclosure.h"
#include "modelenumerations.h"
#include "modelfabric.h"
#include "modelpicture.h"
#include "modeltagreference.h"
#include "runtimestring.h"
#include "runtimetimespan.h"
#include "runtimetimestamp.h"
#include <vector>

namespace ultralove::p3::model {
/// \brief Episode representation
/// \details Represents a single podcast episode
struct Episode : public Fabric
{
    /// \brief Episode number
    uint32_t episodeNumber;

    /// \brief Episode title
    runtime::String title;

    /// \brief Episode subtitle
    runtime::String subtitle;

    /// \brief Episode description
    runtime::String description;

    /// \brief Episode summary
    runtime::String summary;

    /// \brief Episode type
    EpisodeType type;

    /// \brief Publication date
    runtime::Timestamp publicationDate;

    /// \brief Episode duration
    runtime::Timespan duration;

    /// \brief Episode cover art
    Picture coverArt;

    /// \brief Episode media enclosures
    std::vector<Enclosure> enclosures;

    /// \brief Associated tags
    std::vector<TagReference> tags;

    /// \brief Contributors
    std::vector<Contribution> contributors;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_EPISODE_H_INCL__
