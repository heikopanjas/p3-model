///
// \file modelpodcast.h
// \brief P3 Model Podcast
// \details Podcast struct representing a podcast series
//

#ifndef __P3_MODEL_PODCAST_H_INCL__
#define __P3_MODEL_PODCAST_H_INCL__

#pragma pack(push, 8)

#include "modelcontribution.h"
#include "modelfabric.h"
#include "modelpicture.h"
#include "modelpublisher.h"
#include "modelseason.h"
#include "modeltagreference.h"
#include "runtimestring.h"
#include "runtimetimestamp.h"
#include <vector>

namespace ultralove::p3::model {
/// \brief Podcast representation
/// \details Represents a complete podcast series
struct Podcast : public Fabric
{
    /// \brief Podcast title
    runtime::String title;

    /// \brief Podcast subtitle
    runtime::String subtitle;

    /// \brief Podcast description
    runtime::String description;

    /// \brief Podcast summary
    runtime::String summary;

    /// \brief Podcast language
    runtime::String language;

    /// \brief Podcast categories
    std::vector<runtime::String> categories;

    /// \brief Publication date
    runtime::Timestamp publicationDate;

    /// \brief Last build date
    runtime::Timestamp lastBuildDate;

    /// \brief Managing editor
    runtime::String managingEditor;

    /// \brief Webmaster
    runtime::String webmaster;

    /// \brief Copyright information
    runtime::String copyright;

    /// \brief Website link
    runtime::String link;

    /// \brief Podcast publisher
    Publisher publisher;

    /// \brief Cover art
    Picture coverArt;

    /// \brief Associated tags
    std::vector<TagReference> tags;

    /// \brief Contributors
    std::vector<Contribution> contributors;

    /// \brief Seasons
    std::vector<Season> seasons;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_PODCAST_H_INCL__
