# P3 Model Library

A C++ object model library for podcast production and publishing (P3) workflows, providing comprehensive modeling capabilities for the entire podcast ecosystem.

## Overview

The P3 Model Library is designed to model the complete podcast production and publishing domain, from content creation to distribution. It provides a robust foundation for building podcast-related applications with modern C++ standards and best practices.

## Features

### Complete C++ Object Model (22 Classes)
- **Content Hierarchy**: Podcast → Season → Episode with full relationship management
- **Contributor System**: People, roles, and online presence management
- **Tag System**: Chapter markers, location tags, and transcript integration
- **Asset Management**: Picture and enclosure handling for media files
- **Publishing Workflow**: Publisher entities with ownership tracking
- **Annotation Framework**: Timestamped content annotation with external references
- **Enumeration System**: 6 comprehensive enums for type safety and validation

### Domain-Specific Models
- **Content Models**: Complete podcast content hierarchy with metadata
- **Production Models**: Contributor roles, presence tracking, and contribution management
- **Publishing Models**: Publisher entities with URI and ownership management
- **Metadata Models**: Tag system with Wikipedia/Wikidata integration
- **Asset Models**: Type-safe media file management (images, audio, video)
- **Workflow Models**: Chapter organization, location tracking, transcript management
- **Runtime Utilities**: GUID, String, TimeSpan, TimeStamp foundation classes

## Requirements

### Minimum Requirements

- CMake 4.0 or higher
- C++23 compatible compiler (tested with AppleClang 17.0.0)
- Ninja build system (recommended)

### Optional Dependencies (for documentation)

- Doxygen (API documentation generation)
- LaTeX distribution (PDF documentation)
- Graphviz dot (dependency graphs and UML diagrams)

## Quick Start

### Building the Library

```bash
# Clone the repository
git clone https://github.com/ultralove/p3-model.git
cd p3-model

# Configure with CMake using Ninja generator
cmake -G Ninja -B _build

# Build the static library
cmake --build _build
```

The build generates `_build/libp3-model.a` static library ready for integration.

### Building Documentation

```bash
# Generate LaTeX documentation (requires Doxygen)
cmake --build _build --target docs

# Build PDF from LaTeX (requires LaTeX distribution)
cmake --build _build --target docs-pdf

# PDF output location: _build/docs/latex/p3-model.pdf
```

### Integration Example

```cpp
#include "model.h"

int main() {
    // Initialize the P3 Model library
    if (!ultralove::p3::model::Model::Initialize()) {
        return 1;
    }

    // Get library information
    auto version = ultralove::p3::model::Model::GetVersion();
    auto name = ultralove::p3::model::Model::GetLibraryName();

    // Your podcast application logic here

    // Cleanup
    ultralove::p3::model::Model::Shutdown();
    return 0;
}
```

## Implementation Status

### Current Version: 0.1.0

The P3 Model Library includes a complete C++ object model implementation with 22 classes organized in a hierarchical structure:

#### Core Components ✅
- **Base Infrastructure**: Fabric base class providing common entity functionality
- **Content Hierarchy**: Podcast → Season → Episode relationship management
- **Contributor System**: People, roles, and online presence tracking
- **Publishing Workflow**: Publisher entities with ownership and URI management
- **Tag System**: Timestamped content annotation (chapters, locations, transcripts)
- **Asset Management**: Type-safe media file handling (pictures, enclosures)
- **Enumeration Framework**: 6 comprehensive enums for type safety

#### Usage Example

```cpp
#include "model.h"
using namespace ultralove::p3::model;

int main() {
    // Create a podcast with publisher
    Publisher publisher("https://example.com", nullptr);
    Podcast podcast("https://example.com/podcast", "My Podcast", &publisher);

    // Create a season with episodes
    Season season1(1);
    Episode episode1("https://example.com/ep1", "Episode 1",
                    EpisodeType::FULL, runtime::Timespan{});

    // Add content relationships
    season1.AddEpisode(&episode1);
    podcast.AddSeason(&season1);

    // Add media assets
    Picture artwork(PictureType::JPG);
    Enclosure audioFile(EnclosureType::MP3, 15728640);

    episode1.SetPicture(&artwork);
    episode1.AddEnclosure(&audioFile);

    return 0;
}
```

#### Runtime Dependencies
The struct implementations currently use placeholder runtime classes:
- `runtime::String`: Basic placeholder (will be enhanced)
- `runtime::GUID`: Basic 128-bit structure (will be enhanced)
- `runtime::Timestamp`: Basic placeholder (will be enhanced)
- `runtime::Timespan`: Basic placeholder (will be enhanced)

## Architecture

The library follows a layered architecture with clear separation of concerns:

- **Runtime Layer**: Core utilities and data types
- **Model Layer**: Domain-specific podcast models
- **Service Layer**: Business logic and workflows
- **Integration Layer**: External platform connectors

All components are designed for:

- Serialization and deserialization support
- Validation and business rule enforcement
- Extensibility for future podcast industry standards
- Integration with external podcast platforms and tools

## Code Standards

The project follows strict C++ coding standards:

- **Language Standard**: C++23
- **Namespace**: All code in `ultralove::p3::model`
- **Naming Conventions**:
  - Types: Upper PascalCase (`Episode`, `SharedObject`)
  - Functions: Upper PascalCase (`GetTitle`, `SetDuration`)
  - Variables: camelCase (`bufferSize`, `episodeCount`)
  - Member variables: camelCase with underscore postfix (`title_`, `duration_`)
  - Constants: UPPER_SNAKE_CASE (`MAX_EPISODE_LENGTH`)
- **Memory Management**: RAII principles, smart pointers preferred
- **Documentation**: Doxygen-style comments with UML diagrams

## Project Structure

```text
p3-model/
├── CMakeLists.txt          # Main build configuration
├── version.in              # Version management
├── model.h                 # Main library header
├── model.cpp               # Main library implementation
├── runtime*.h              # Runtime utility headers
├── cmake/                  # CMake package configuration
│   └── p3-model-config.cmake.in
├── docs/                   # Documentation resources
│   ├── plantuml-monochrome.puml  # PlantUML styling
│   └── plantuml-monochrome.css   # CSS styling
└── _build/                 # Build output directory (generated)
    ├── libp3-model.a       # Static library
    └── docs/               # Generated documentation
```

## Version Management

Version information is managed through the `version.in` file. The current version is automatically read by CMake during the build process.

Current version: **0.1.0**

To update the version:

1. Edit the `version.in` file
2. Rebuild the project

## Contributing

We welcome contributions to the P3 Model Library. Please follow these guidelines:

1. **Code Style**: Follow the established coding standards outlined above
2. **Testing**: Write unit tests for new functionality
3. **Documentation**: Update documentation for API changes
4. **Commits**: Use conventional commit format (`type(scope): description`)
5. **Branches**: Use feature branches for development

### Commit Message Format

```text
type(scope): description

feat(core): add episode duration validation
fix(model): correct timestamp serialization
docs(api): update getting started guide
```

## Build System

The project uses modern CMake practices:

- Target-based configuration with `target_*` commands
- Ninja generator for optimal build performance
- Debug build type by default for development
- Comprehensive compiler warnings and standards compliance
- Automatic dependency management
- Package configuration for easy integration

## Documentation

The library includes comprehensive documentation:

- **API Documentation**: Generated with Doxygen
- **UML Diagrams**: Embedded PlantUML diagrams in headers
- **Architecture Diagrams**: Graphviz DOT for complex relationships
- **Integration Examples**: Practical usage patterns
- **Build Instructions**: Complete setup and build guide

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Support

For questions, issues, or contributions:

- **Issues**: Use GitHub Issues for bug reports and feature requests
- **Discussions**: Use GitHub Discussions for general questions
- **Documentation**: Refer to the generated API documentation

## Roadmap

The P3 Model Library is under active development. Planned features include:

- Complete podcast content modeling
- Production workflow automation
- Multi-platform publishing support
- Analytics and reporting capabilities
- Plugin architecture for extensibility
- Integration with popular podcast platforms

---

**P3 Model Library** - Building the future of podcast production technology.
