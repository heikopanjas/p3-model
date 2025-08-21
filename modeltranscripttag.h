///
// \file modeltranscripttag.h
// \brief P3 Model Transcript Tag
// \details Transcript tag derived from Tag
//

#ifndef __P3_MODEL_TRANSCRIPT_TAG_H_INCL__
#define __P3_MODEL_TRANSCRIPT_TAG_H_INCL__

#pragma pack(push, 8)

#include "modeltag.h"
#include "runtimestring.h"
#include "runtimetimespan.h"

namespace ultralove::p3::model {
/// \brief Transcript tag
/// \details Tag containing transcript text with timing
struct TranscriptTag : public Tag
{
    /// \brief Transcript text
    runtime::String text;

    /// \brief Start time of transcript segment
    runtime::Timespan startTime;

    /// \brief End time of transcript segment
    runtime::Timespan endTime;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_TRANSCRIPT_TAG_H_INCL__
