///
// \file modelchaptertag.h
// \brief P3 Model Chapter Tag
// \details Chapter tag derived from Tag
//

#ifndef __P3_MODEL_CHAPTER_TAG_H_INCL__
#define __P3_MODEL_CHAPTER_TAG_H_INCL__

#pragma pack(push, 8)

#include "modeltag.h"
#include "runtimetimespan.h"

namespace ultralove::p3::model {
/// \brief Chapter tag
/// \details Tag representing a chapter or section with timing
struct ChapterTag : public Tag
{
    /// \brief Chapter start time
    runtime::Timespan startTime;

    /// \brief Chapter end time
    runtime::Timespan endTime;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_CHAPTER_TAG_H_INCL__
