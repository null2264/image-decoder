//
// Created by len on 30/12/20.
//

#ifndef IMAGEDECODER_DECODER_WEBP_H
#define IMAGEDECODER_DECODER_WEBP_H

#include "decoder_base.h"
#include "stream.h"
#include <src/webp/decode.h>
#include <src/webp/demux.h>

class WebpDecoder: public BaseDecoder {
public:
  WebpDecoder(std::unique_ptr<Stream>&& stream, bool cropBorders);
  static bool handles(const uint8_t* stream);

  void decode(uint8_t* outPixels, Rect outRect, Rect inRect, bool rgb565, uint32_t sampleSize);

private:
  ImageInfo parseInfo();
};

#endif //IMAGEDECODER_DECODER_WEBP_H
