#include "diypng.h"
#include <iostream>
#include <stdint.h>
#include "adler32.h"

struct PngHeader 
{
	int32_t width;
	int32_t height;
	char bit_depth, colour, compression, filters, interlace;
};

void 	writePngMagicNumber(std::ostream & os )
{
}


void writeHeaderChunk(int width, int height, std::ostream & os )

{
	os << uint8_t(13);
	os << "IHDR";
	PngHeader h { width, height, 8, 2, 0, 0, 0 };

	os << uint32_t(width) << uint32_t(height);
}
	

void writePng8bitMonoUncompressed( int32_t width, int32_t height, char * pixels, std::ostream & os )
{
	writePngMagicNumber(os);
	writeHeaderChunk(width, height, os);
	
}

int main()
{
	return 0;
}
