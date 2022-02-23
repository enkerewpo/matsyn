//------------------------------------------------------------------------
// Copyright(c) 2022 rys.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace rys {
//------------------------------------------------------------------------
static const Steinberg::FUID kmatsynProcessorUID (0x9622B1A4, 0x6C0550A4, 0xA7D93578, 0xE4C69140);
static const Steinberg::FUID kmatsynControllerUID (0xFFD56887, 0x337E5969, 0xB82590D3, 0xB855CF0B);

#define matsynVST3Category "Instrument"

//------------------------------------------------------------------------
} // namespace rys
