#ifndef UI_OPEN_SAVE_PRODUCTS_H
#define UI_OPEN_SAVE_PRODUCTS_H

typedef struct addToFileInfo
{
    uiEntry *size;
    uiEntry *array;
    uiEntry *position;
} addToFileInfo;

uiControl *fileInputOutput(void);

uiMultilineEntry *mul_entry;
uiWindow *mainwin;


#endif // UI_OPEN_SAVE_PRODUCTS_H
