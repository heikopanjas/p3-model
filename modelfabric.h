///
// \file modelfabric.h
// \brief P3 Model Base Fabric Class
// \details Base class for all P3 Model entities providing common functionality
//

#ifndef __P3_MODEL_FABRIC_H_INCL__
#define __P3_MODEL_FABRIC_H_INCL__

#pragma pack(push, 8)

#include "runtimeguid.h"
#include "runtimestring.h"
#include "runtimetimestamp.h"

namespace ultralove::p3::model {
// Alias runtime namespace for convenience
namespace runtime = ultralove::p3::runtime;

/// \brief Base class for all P3 Model entities
/// \details Provides common properties and functionality for all model objects
///
/// @dot
/// digraph fabric_hierarchy {
///     rankdir=TB;
///     node [shape=box, style=filled, fillcolor=white, fontname="Arial"];
///     edge [fontname="Arial"];
///
///     Fabric [label="Fabric\n(Base Class)", fillcolor=lightblue];
///     Podcast [label="Podcast"];
///     Season [label="Season"];
///     Episode [label="Episode"];
///     Contributor [label="Contributor"];
///     Publisher [label="Publisher"];
///     Tag [label="Tag"];
///
///     Fabric -> Podcast;
///     Fabric -> Season;
///     Fabric -> Episode;
///     Fabric -> Contributor;
///     Fabric -> Publisher;
///     Fabric -> Tag;
/// }
/// @enddot
struct Fabric
{
    /// \brief Unique identifier for this entity
    runtime::Guid id;

    /// \brief Type identifier for this entity
    runtime::Guid typeId;

    /// \brief When this entity was created
    runtime::Timestamp creationDate;

    /// \brief When this entity was last modified
    runtime::Timestamp modificationDate;

    /// \brief User comment for this entity
    runtime::String comment;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_FABRIC_H_INCL__
