#include "example_mod.h"
#include "nise/stub.h"
#include <cstdio>

extern "C" void LoadMyAssets()
{
    int count = VirtualAssets_LoadDir("/sdcard/MyMod/assets", "assets", true);

    char msg[64];
    snprintf(msg, sizeof(msg), "Archivos cargados: %d", count);
    ClientLog("ModInit", "MyMod", msg);
}

__attribute__((constructor))
static void OnLoad()
{
    LoadMyAssets();
}
