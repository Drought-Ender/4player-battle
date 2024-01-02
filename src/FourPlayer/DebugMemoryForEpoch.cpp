#include "VsOptions.h"
#include "JSystem/JKernel/JKRHeap.h"

void DrawDebugMemory(Graphics& gfx) {
    #if FOURPLAYER_DEBUG == 1
    J2DPrint print (getPikminFont(), 0.0f);

    print.mGlyphHeight /= 3;
    print.mGlyphWidth /= 3;

    f32 megabytes = (JKRHeap::sCurrentHeap->getFreeSize() / 8.0f) / 1e+6f;
    f32 currentHeapMB = (JKRHeap::sCurrentHeap->getSize() / 8.0f) / 1e+6f;

    print.print(85.0f, 10.0f, "sCurrentHeap: %f MB/%f MB", currentHeapMB - megabytes, currentHeapMB);
    print.print(85.0f, 20.0f, "Normal Heap Size: 1.258151/1.262372 MB");
    print.print(85.0f, 30.0f, "System Heap: %u/%u", JKRHeap::sSystemHeap->getFreeSize(), JKRHeap::sSystemHeap->getSize());
    print.print(85.0f, 40.0f, "POKO COUNT: 100000000");
    print.print(85.0f, 50.0f, "PISH BANK ACCOUNT: $6 gadzillion");
    // print.print(100.0f, 30.0f, "Total Memory: %x/%x", JKRHeap::sRootHeap->getFreeSize(), JKRHeap::sRootHeap->getSize());
    #endif
}