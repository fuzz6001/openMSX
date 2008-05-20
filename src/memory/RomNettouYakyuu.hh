// $Id$

#ifndef ROMNETTOUYAKYUU_HH
#define ROMNETTOUYAKYUU_HH

#include "Rom8kBBlocks.hh"

namespace openmsx {

class SamplePlayer;
class WavData;

class RomNettouYakyuu : public Rom8kBBlocks
{
public:
	RomNettouYakyuu(MSXMotherBoard& motherBoard, const XMLElement& config,
	                const EmuTime& time, std::auto_ptr<Rom> rom);

	virtual void reset(const EmuTime& time);
	virtual void writeMem(word address, byte value, const EmuTime& time);
	virtual byte* getWriteCacheLine(word address) const;

private:
	std::auto_ptr<SamplePlayer> samplePlayer;
	std::auto_ptr<WavData> sample[16];

	// remember per region if writes are for the sample player or not
	// there are 4 x 8kB regions in [0x4000-0xBFFF]
	bool redirectToSamplePlayer[4];
};

} // namespace openmsx

#endif
