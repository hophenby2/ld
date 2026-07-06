#pragma once

#include <span>

namespace reconstructed {

enum class ResourceMode {
    ExtractedFiles,
    DxArchive,
};

enum class GraphLoadKind {
    Single,
    Div,
};

enum class ResourceSource {
    Startup,
    Primary,
    Secondary,
};

enum class SoundKind {
    Bgm,
    Se,
};

struct GraphResourceSpec {
    const char* id;
    const char* logicalPath;
    GraphLoadKind loadKind;
    int allNum;
    int xNum;
    int yNum;
    int xSize;
    int ySize;
    ResourceSource source;
};

struct SoundResourceSpec {
    const char* id;
    const char* logicalPath;
    SoundKind kind;
    int bufferNum;
};

struct TextResourceSpec {
    const char* id;
    const char* logicalPath;
    unsigned int codePage;
    bool utf8Bom;
};

std::span<const GraphResourceSpec> startupGraphResources();
std::span<const GraphResourceSpec> frontendGraphResources();
std::span<const GraphResourceSpec> expandedGraphResources();
std::span<const SoundResourceSpec> soundResources();
std::span<const TextResourceSpec> textResources();

const char* toString(ResourceSource source);
const char* toString(GraphLoadKind kind);
const char* toString(SoundKind kind);

} // namespace reconstructed
