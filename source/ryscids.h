//------------------------------------------------------------------------
// Copyright(c) 2021 rys.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace rys {
//------------------------------------------------------------------------
static const Steinberg::FUID kmatsynProcessorUID (0x44987C92, 0x59B75667, 0x9F9498E2, 0x0A742689);
static const Steinberg::FUID kmatsynControllerUID (0xF59EAEEE, 0xB82054F7, 0x957BC99F, 0x091E6501);

#define matsynVST3Category "Instrument"

//------------------------------------------------------------------------
} // namespace rys
