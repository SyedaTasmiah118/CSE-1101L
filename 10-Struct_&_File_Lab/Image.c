#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#pragma pack(push, 1)

typedef struct
{
    uint16_t type;
    uint32_t filesize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t pixelOffset;
} BMPFileHeader;

typedef struct
{
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    unsigned char xyz[24];
} BMPInfoHeader;

#pragma pack(pop)

int main()
{
    FILE *input = fopen("lena.bmp", "rb");
    FILE *output = fopen("lena_grayscale.bmp", "wb");

    if (input == NULL || output == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(fileHeader), 1, input);
    fread(&infoHeader, sizeof(infoHeader), 1, input);

    if (fileHeader.type != 0x4D42 ||
        infoHeader.bitsPerPixel != 24)
    {
        printf("Only 24-bit BMP files are supported.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    fseek(input, 0, SEEK_SET);

    unsigned char *header = malloc(fileHeader.pixelOffset);

    fread(header, 1, fileHeader.pixelOffset, input);
    fwrite(header, 1, fileHeader.pixelOffset, output);

    free(header);

    fseek(input, fileHeader.pixelOffset, SEEK_SET);

    int width = infoHeader.width;
    int height = infoHeader.height;

       int rowPadding = (4 - (width * 3) % 4) % 4;

    unsigned char pixel[3];
    unsigned char padding[3];

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            fread(pixel, 1, 3, input);

            unsigned char gray =
                0.114 * pixel[0] +
                0.587 * pixel[1] +
                0.299 * pixel[2];

            pixel[0] = gray;
            pixel[1] = gray;
            pixel[2] = gray;

            fwrite(pixel, 1, 3, output);
        }

        fread(padding, 1, rowPadding, input);
        fwrite(padding, 1, rowPadding, output);
    }

    fclose(input);
    fclose(output);

    printf("Width  : %d pixels\n", infoHeader.width);
    printf("Height : %d pixels\n", infoHeader.height);
    printf("\nGrayscale image created!\n");
    printf("New file: lena_grayscale.bmp\n");

    return 0;
}