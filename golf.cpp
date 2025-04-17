#include <emscripten.h>

extern "C" {

// Returns index of current hole (0-based) and writes percent through it to percentThrough pointer
EMSCRIPTEN_KEEPALIVE
int getHoleIndex(double elapsedMinutes, double* holeTimes, int holeCount, double* percentThrough) {
    double sum = 0.0;
    for (int i = 0; i < holeCount; ++i) {
        if (elapsedMinutes < sum + holeTimes[i]) {
            *percentThrough = (elapsedMinutes - sum) / holeTimes[i] * 100.0;
            return i;
        }
        sum += holeTimes[i];
    }
    *percentThrough = 100.0;
    return holeCount - 1; // fully done
}

}
