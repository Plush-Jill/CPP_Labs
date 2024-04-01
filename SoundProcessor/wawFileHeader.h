#pragma once



struct TWawFileHeader{
    char chunkId[4];
    unsigned long chunkSize;
    char format[4];
    char subChunk1Id[4];
    unsigned long subchunk1Size;
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned long sampleRate;
    unsigned long byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    char subChunk2Id[4];
    unsigned long subChunk2Size;
};