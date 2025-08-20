/*!
 * \file model.h
 * \brief P3 Model Library Header
 * \details Main header file for the Podcast Production and Publishing (P3) Model library
 *
 * \dot
 * digraph model_overview {
 *   rankdir=TB;
 *   node [shape=record, style=filled, fillcolor=white, fontname="Arial"];
 *   edge [fontname="Arial"];
 *
 *   Model [label="{Model|+ GetVersion() : string\\l+ GetLibraryName() : string\\l+ Initialize() : bool\\l+ Shutdown() : void\\l}"];
 *
 *   Model -> "Library Entry Point" [style=dashed, label="provides"];
 * }
 * \enddot
 */

#ifndef __P3_MODEL_H_INCL__
#define __P3_MODEL_H_INCL__

#pragma pack(push, 8)

// Include all utility structs
#include "runtimeguid.h"
#include "runtimestring.h"
#include "runtimetimespan.h"
#include "runtimetimestamp.h"

namespace ultralove::p3::model {
// Alias runtime namespace for convenience
namespace runtime = ultralove::p3::runtime;

/// \brief Main entry point for the P3 Model library
/// \details This struct provides basic information about the P3 Model library
struct Model
{
    /// \brief Get the library version
    /// \return Version string in format "major.minor.patch"
    static runtime::String GetVersion();

    /// \brief Get the library name
    /// \return The name of the library
    static runtime::String GetLibraryName();

    /// \brief Initialize the P3 Model library
    /// \return True if initialization was successful, false otherwise
    static bool Initialize();

    /// \brief Cleanup and shutdown the P3 Model library
    static void Shutdown();

    // Deleted constructors and assignment operators - this is a utility struct
    Model()                        = delete;
    virtual ~Model()               = delete;
    Model(const Model&)            = delete;
    Model& operator=(const Model&) = delete;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_H_INCL__
