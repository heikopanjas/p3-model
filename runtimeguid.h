/*!
 * \file runtimeguid.h
 * \brief GUID utility struct for the P3 Model library
 * \details Placeholder GUID struct for future implementation in podcast domain
 *
 * \startuml
 * !include docs/plantuml-monochrome.puml
 * title GUID Utility Struct
 *
 * struct Guid {
 *   ' Data members placeholder
 *   ' Future: uint64_t high
 *   ' Future: uint64_t low
 * }
 *
 * note top of Guid : 128-bit UUID storage
RFC 4122 compliant
 *
 * \enduml
 */

#ifndef __P3_RUNTIMEGUID_H_INCL__
#define __P3_RUNTIMEGUID_H_INCL__

#pragma pack(push, 8)

#include <cstdint>

namespace ultralove::p3::runtime {
/// \brief Globally unique identifier struct for the P3 Model library
/// \details Placeholder GUID struct for future implementation
/// This will provide unique identification for podcast episodes, series, hosts, etc.
struct Guid
{
    // Data members will be added in future implementation
    // Planned: 128-bit UUID storage compliant with RFC 4122
    // uint64_t high;
    // uint64_t low;
};
} // namespace ultralove::p3::runtime

#pragma pack(pop)

#endif // __P3_RUNTIMEGUID_H_INCL__
