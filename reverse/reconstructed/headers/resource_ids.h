#pragma once

// Reconstructed resource identifier sketch.
// This is not original source. It is a local reverse-engineering aid derived
// from executable string tables and extracted resources.

namespace reconstructed {

enum class ResourceCategory {
    System,
    Player,
    Stage,
    Gallery,
    Effect,
    Bgm,
    Se,
    Text,
    Demo,
    Unknown,
};

struct ResourcePathEntry {
    ResourceCategory category;
    const char* logical_path;
};

// See reverse/symbols/resource-map.csv for the full extracted table.

} // namespace reconstructed
