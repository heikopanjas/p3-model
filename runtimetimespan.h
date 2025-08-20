/*!
 * \file runtimetimespan.h
 * \brief Timespan utility struct for the P3 Model library
 * \details Placeholder timespan struct for future implementation in podcast domain
 *
 * \dot
 * digraph timespan_struct {
 *   rankdir=TB;
 *   node [shape=record, style=filled, fillcolor=white, fontname="Arial"];
 *
 *   Timespan [label="{Timespan|Future: int64_t total_nanoseconds\\l}"];
 *
 *   Note [shape=note, label="Duration representation\\nNanosecond precision"];
 *   Timespan -> Note [style=dashed];
 * }
 * \enddot
 */

#ifndef __P3_RUNTIME_TIMESPAN_H_INCL__
#define __P3_RUNTIME_TIMESPAN_H_INCL__

#pragma pack(push, 8)

#include <cstdint>

namespace ultralove::p3::runtime {
/// \brief Timespan struct for the P3 Model library
/// \details Placeholder timespan struct for future implementation
/// This will handle podcast duration data like episode lengths, ad break durations, etc.
struct Timespan
{
    // Data members will be added in future implementation
    // Planned: nanosecond precision duration storage, conversion utilities
};
} // namespace ultralove::p3::runtime

#pragma pack(pop)

#endif // __P3_RUNTIME_TIMESPAN_H_INCL__
