// PluginSimpleGain.cpp
// Brian Heim (brianlheim@gmail.com)

#include "SC_PlugIn.hpp"
#include "SimpleGain.hpp"

static InterfaceTable *ft;

namespace SimpleGain {

SimpleGain::SimpleGain()
{
    set_calc_function<SimpleGain, &SimpleGain::next>();
    next(1);
}

void SimpleGain::next(int nSamples)
{
    const float * input = in(0);
    const float * gain = in(1);
    float * outbuf = out(0);

    // simple gain function
    for (int i = 0; i < nSamples; ++i) {
        outbuf[i] = input[i] * gain[i];
    }
}

} // namespace SimpleGain

PluginLoad(SimpleGainUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<SimpleGain::SimpleGain>(ft, "SimpleGain");
}
