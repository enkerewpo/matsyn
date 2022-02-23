//------------------------------------------------------------------------
// Copyright(c) 2022 rys.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace rys {
//------------------------------------------------------------------------
static const Steinberg::FUID kmatsynProcessorUID (0xAC903309, 0x07A553C6, 0x910CB489, 0xB6F1812A);
static const Steinberg::FUID kmatsynControllerUID (0x850299DF, 0xE71A5886, 0x903B3A59, 0x715662F9);

#define matsynVST3Category "Instrument"

//------------------------------------------------------------------------
} // namespace rys
