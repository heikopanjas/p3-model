#ifndef __P3_MODEL_H_INCL__
#define __P3_MODEL_H_INCL__

#pragma pack(push, 8)

#include <string>

namespace ultralove::p3::model {
/// \brief Main entry point for the P3 Model library
/// \details This class provides basic information about the P3 Model library
class Model
{
public:
    /// \brief Get the library version
    /// \return Version string in format "major.minor.patch"
    static std::string GetVersion();

    /// \brief Get the library name
    /// \return The name of the library
    static std::string GetLibraryName();

    /// \brief Initialize the P3 Model library
    /// \return True if initialization was successful, false otherwise
    static bool Initialize();

    /// \brief Cleanup and shutdown the P3 Model library
    static void Shutdown();

private:
    // Private constructor - this is a utility class
    Model()                        = delete;
    virtual ~Model()               = delete;
    Model(const Model&)            = delete;
    Model& operator=(const Model&) = delete;
};
} // namespace ultralove::p3::model

#pragma pack(pop)

#endif // __P3_MODEL_H_INCL__
