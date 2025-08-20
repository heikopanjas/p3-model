/*!
 * \file runtimetimespan.h
 * \brief Timespan utility struct for the P3 Model library
 * \details Placeholder timespan struct for future implementation in podcast domain
 *
 * \startuml
 * !include docs/plantuml-monochrome.puml
 * title Timespan Utility Struct
 *
 * struct Timespan {
 *   ' Data members placeholder
 *   ' Future: int64_t total_nanoseconds
 * }
 *
 * note top of Timespan : Duration representation
Nanosecond precision
 *
 * \enduml
 */

#ifndef __P3_RUNTIMETIMESPAN_H_INCL__
#define __P3_RUNTIMETIMESPAN_H_INCL__

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

#endif // __P3_RUNTIMETIMESPAN_H_INCL__
