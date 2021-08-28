//------------------------------------------------------------------------
// Copyright(c) 2021 rys.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace rys {
//------------------------------------------------------------------------
static const Steinberg::FUID kmathsynthProcessorUID (0xDA1D0743, 0xFA2B5A1D, 0x9B752478, 0xB829C861);
static const Steinberg::FUID kmathsynthControllerUID (0x9FCF2E5F, 0x33B05EE2, 0xA387894A, 0x8384A902);

#define mathsynthVST3Category "Instrument"

//------------------------------------------------------------------------
} // namespace rys
