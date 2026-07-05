#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace reconstructed {

struct StageResourceHint {
    int stage = 0;
    const char* label;
    const char* backgrounds;
    const char* stageBgm;
    const char* bossBgm;
    const char* evidence;
};

struct ReplayStageFieldHint {
    const char* offset;
    const char* name;
    const char* note;
};

struct EntityModelHypothesis {
    const char* kind;
    const char* resourceEvidence;
    const char* expectedFields;
};

struct ReverseTargetFunction {
    const char* name;
    const char* evidence;
    const char* nextAction;
};

struct DemoProbeSummary {
    std::string id;
    std::string logicalPath;
    bool loaded = false;
    int headerFieldCount = 0;
    int inputRecordCount = 0;
    std::string firstHeader;
    std::string error;
};

class StageProbe {
public:
    bool loadDemoSummaries(const std::filesystem::path& assetRoot);

    const std::vector<DemoProbeSummary>& demos() const { return demos_; }

private:
    std::vector<DemoProbeSummary> demos_;
};

const std::vector<StageResourceHint>& stageResourceHints();
const std::vector<ReplayStageFieldHint>& replayStageFieldHints();
const std::vector<EntityModelHypothesis>& entityModelHypotheses();
const std::vector<ReverseTargetFunction>& reverseTargetFunctions();

} // namespace reconstructed
