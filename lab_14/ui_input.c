#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "ui_input.h"
#include "processing.h"


static void onPrintButtonClicked(uiButton *b, void *data);
static void onOpenFileClicked(uiButton *b, void *data);
static void onSaveFileClicked(uiButton *b, void *data);
void input_error();


uiControl *fileInputOutput(void)
{
    uiBox *hbox = uiNewHorizontalBox();
    uiBoxSetPadded(hbox, 1);

    uiBox *vbox = uiNewVerticalBox();
    uiBoxSetPadded(vbox, 1);
    uiBoxAppend(hbox, uiControl(vbox), 1);
//===========================================================
    uiBoxAppend(vbox,
        uiControl(uiNewHorizontalSeparator()),
        0);

    uiGroup *group = uiNewGroup("Input array info:");
    uiGroupSetMargined(group, 1);
    uiBoxAppend(vbox, uiControl(group), 1);

    uiForm *entryForm = uiNewForm();
    uiFormSetPadded(entryForm, 1);
    uiGroupSetChild(group, uiControl(entryForm));

    uiEntry *size = uiNewEntry();
    uiFormAppend(entryForm,
        "Size:",
        uiControl(size),
        0);

    uiEntry *array = uiNewEntry();
    uiFormAppend(entryForm,
        "Array:",
        uiControl(array),
        0);

    uiEntry *position = uiNewEntry();
    uiFormAppend(entryForm,
        "Position:",
        uiControl(position),
        0);
//===========================================================
    addToFileInfo *info = malloc(sizeof(addToFileInfo));
    info->size = size;
    info->array = array;
    info->position = position;

//===========================================================
    uiButton *print_button = uiNewButton("PROCESSING");
    uiBoxAppend(vbox,
        uiControl(print_button),
        0);
//===========================================================
    mul_entry = uiNewMultilineEntry();
    uiMultilineEntrySetReadOnly(mul_entry, 1);
    uiBoxAppend(vbox, uiControl(mul_entry), 0);
//===========================================================

    uiBoxAppend(vbox,
        uiControl(uiNewHorizontalSeparator()),
        0);

    uiButtonOnClicked(print_button, onPrintButtonClicked, (void *)info);

    return uiControl(hbox);
}

static void onPrintButtonClicked(uiButton *b, void *data)
{
    addToFileInfo info = *((addToFileInfo *)data);

    uiEntry *size = uiEntry(info.size);
    uiEntry *array = uiEntry(info.array);
    uiEntry *position = uiEntry(info.position);
//===========================================================
    char *s_size = malloc(sizeof(char) * 20);
    char *s_array = malloc(sizeof(char) * 100);
    char *s_position = malloc(sizeof(char) * 20);

    s_size = uiEntryText(size);
    s_array = uiEntryText(array);
    s_position = uiEntryText(position);

    FILE *in = fopen("in.txt", "w");

    fprintf(in, "%s\n%s\n%s\n", s_size, s_array, s_position);

    fclose(in);

    in = fopen("in.txt", "r");

    int code_error = processing(in);
    if (code_error != 0);
    {
        input_error(code_error);
    }
    fclose(in);
}

void input_error(int code_error)
{
    switch(code_error)
    {
        case 1:
            uiMsgBoxError(mainwin,
            "Error input!",
            "INPUT_ERROR");
            break;

        case 2:
            uiMsgBoxError(mainwin,
            "Error input!",
            "ARRAY_IS_OVER");
            break;

        case 3:
            uiMsgBoxError(mainwin,
            "Error input!",
            "OUTSIDE_OF_ARRAY");
            break;

        case 4:
            uiMsgBoxError(mainwin,
            "Error input!",
            "MEMORY_IS_OVER");
            break;
    }
}
