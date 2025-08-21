///
// \file modeltagreferencetype.h
// \brief P3 Model Tag Reference Type Enumeration
// \details Tag reference source types
//

#ifndef __P3_MODEL_TAG_REFERENCE_TYPE_H_INCL__
#define __P3_MODEL_TAG_REFERENCE_TYPE_H_INCL__

#pragma pack(push, 8)

namespace ultralove::p3::model {
/// \brief Tag reference source types
enum class TagReferenceType
{
    ANY,       ///< Generic reference
    WIKIPEDIA, ///< Wikipedia reference
    WIKIDATA   ///< Wikidata reference
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_TAG_REFERENCE_TYPE_H_INCL__
