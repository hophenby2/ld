#include "steam_stub.h"

#include <DxLib.h>

namespace reconstructed {

bool initializeSteamStub() {
    OutputDebugString("[LikeDreamerRe] Steam initialization is stubbed for the first reconstruction scaffold.\n");
    return true;
}

void shutdownSteamStub() {
    OutputDebugString("[LikeDreamerRe] Steam shutdown stub.\n");
}

} // namespace reconstructed
